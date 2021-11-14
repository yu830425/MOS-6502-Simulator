#include "Processor.h"
#include <iostream>

Processor::Processor()
{
	using namespace std::placeholders;

	m_commandTable = createCommandMap();
	m_commandMap = std::unordered_map<string, any>{
		{"LDA", std::bind(&ProcessingUnit::LDA, &m_processingUnit, _1)},
		{"LDX", std::bind(&ProcessingUnit::LDX, &m_processingUnit, _1)},
		{"LDY", std::bind(&ProcessingUnit::LDY, &m_processingUnit, _1)},
		{"STA", std::bind(&ProcessingUnit::STA, &m_processingUnit)},
		{"STX", std::bind(&ProcessingUnit::STX, &m_processingUnit)},
		{"STY", std::bind(&ProcessingUnit::STY, &m_processingUnit)},
		{"SEC", std::bind(&ProcessingUnit::SEC, &m_processingUnit)},
		{"CLC", std::bind(&ProcessingUnit::CLC, &m_processingUnit)},
		{"SEI", std::bind(&ProcessingUnit::SED, &m_processingUnit)},
		{"CLI", std::bind(&ProcessingUnit::CLI, &m_processingUnit)},
		{"CLV", std::bind(&ProcessingUnit::CLV, &m_processingUnit)},
		{"ADC", std::bind(&ProcessingUnit::ADC, &m_processingUnit, _1)},
		{"SBC", std::bind(&ProcessingUnit::SBC, &m_processingUnit, _1)},
		{"INC", std::bind(&ProcessingUnit::INC, &m_processingUnit, _1)},
		{"INX", std::bind(&ProcessingUnit::INX, &m_processingUnit)},
		{"INY", std::bind(&ProcessingUnit::INY, &m_processingUnit)},
		{"DEC", std::bind(&ProcessingUnit::DEC, &m_processingUnit, _1)},
		{"DEX", std::bind(&ProcessingUnit::DEX, &m_processingUnit)},
		{"DEY", std::bind(&ProcessingUnit::DEY, &m_processingUnit)},
		{"ASL", std::bind(&ProcessingUnit::ASL, &m_processingUnit, _1)},
		{"LSR", std::bind(&ProcessingUnit::LSR, &m_processingUnit, _1)},
		{"ROL", std::bind(&ProcessingUnit::ROL, &m_processingUnit, _1)},
		{"ROR", std::bind(&ProcessingUnit::ROR, &m_processingUnit, _1)},
		{"AND", std::bind(&ProcessingUnit::AND, &m_processingUnit, _1)},
		{"ORA", std::bind(&ProcessingUnit::ORA, &m_processingUnit, _1)},
		{"EOR", std::bind(&ProcessingUnit::EOR, &m_processingUnit, _1)},
		{"PHA", std::bind(&ProcessingUnit::PHA, &m_processingUnit)},
		{"PLA", std::bind(&ProcessingUnit::PLA, &m_processingUnit)},
		{"PHP", std::bind(&ProcessingUnit::PHP, &m_processingUnit)},
		{"PLP", std::bind(&ProcessingUnit::PLP, &m_processingUnit)},
		{"TAX", std::bind(&ProcessingUnit::TAX, &m_processingUnit)},
		{"TAY", std::bind(&ProcessingUnit::TAY, &m_processingUnit)},
		{"TXA", std::bind(&ProcessingUnit::TXA, &m_processingUnit)},
		{"TYA", std::bind(&ProcessingUnit::TYA, &m_processingUnit)},
		{"TSX", std::bind(&ProcessingUnit::TSX, &m_processingUnit)},
		{"TXS", std::bind(&ProcessingUnit::TXS, &m_processingUnit)},
		{"CMP", std::bind(&ProcessingUnit::CMP, &m_processingUnit, _1)},
		{"CPX", std::bind(&ProcessingUnit::CPX, &m_processingUnit, _1)},
		{"CPY", std::bind(&ProcessingUnit::CPY, &m_processingUnit, _1)},
		{"BIT", std::bind(&ProcessingUnit::BIT, &m_processingUnit, _1)},
		{"BCC", std::bind(&ProcessingUnit::BCC, &m_processingUnit, _1)},
		{"BCS", std::bind(&ProcessingUnit::BCS, &m_processingUnit, _1)},
		{"BNE", std::bind(&ProcessingUnit::BNE, &m_processingUnit, _1)},
		{"BEQ", std::bind(&ProcessingUnit::BEQ, &m_processingUnit, _1)},
		{"BPL", std::bind(&ProcessingUnit::BPL, &m_processingUnit, _1)},
		{"BMI", std::bind(&ProcessingUnit::BMI, &m_processingUnit, _1)},
		{"BVC", std::bind(&ProcessingUnit::BVC, &m_processingUnit, _1)},
		{"BVS", std::bind(&ProcessingUnit::BCS, &m_processingUnit, _1)},
		{"JMP", std::bind(&ProcessingUnit::JMP, &m_processingUnit, _1)},
		{"JSR", std::bind(&ProcessingUnit::JSR, &m_processingUnit, _1)},
		{"RTS", std::bind(&ProcessingUnit::RTS, &m_processingUnit)}
	};
}

void Processor::setProcessingUnit(std::shared_ptr<ProcessingUnit> processingUnit)
{
	m_processingUnit = processingUnit;
}

void Processor::setBus(std::shared_ptr<Bus> bus)
{
	m_bus = bus;
}

void Processor::setProgramCounter(WORD address)
{
	m_processingUnit->setProgramCounter(address);
}

void Processor::run()
{
	while (true)
	{
		bool increaseProgramCounter = true;

		//Fetch
		auto programCounter = m_processingUnit->getProgramCounter();
		auto opCode = m_bus->read(programCounter, 1)[0];

		//Decode
		auto command = m_commandTable[opCode];

		//Read
		WORD value = 0;
		bool writeback = false;

		if (command.mode == AddressMode::Accumulator)
		{
			value = m_processingUnit->getAccumulator();
		}
		else if (command.mode == AddressMode::Immediate)
		{
			value = m_bus->read(programCounter + 1, 1)[0];
		}
		else if (command.mode == AddressMode::Absolute)
		{
			auto parameter = m_bus->read(programCounter + 1, 2);
			auto address = (WORD)parameter[1] << 8 + parameter[0];

			value = m_bus->read(address, 1)[0];
		}
		else if (command.mode == AddressMode::ZeroPage)
		{
			auto address = m_bus->read(programCounter + 1, 1)[0];

			value = m_bus->read(address, 1)[0];
		}
		else if (command.mode == AddressMode::AbsoluteIndirect)
		{
			auto parameter = m_bus->read(programCounter + 1, 2);
			auto address = (WORD)parameter[1] << 8 + parameter[0];
			auto temp = m_bus->read(address, 2);

			value = (WORD)temp[1] << 8 + temp[0];
		}
		else if (command.mode == AddressMode::AbsoluteIndexedX)
		{
			auto parameter = m_bus->read(programCounter + 1, 2);
			auto address = (WORD)parameter[1] << 8 + parameter[0];

			value = m_bus->read(address + m_processingUnit->getRegisterX(), 1)[0];
		}
		else if (command.mode == AddressMode::AbsoulteIndexedY)
		{
			auto parameter = m_bus->read(programCounter + 1, 2);
			auto address = (WORD)parameter[1] << 8 + parameter[0];

			value = m_bus->read(address + m_processingUnit->getRegisterY(), 1)[0];
		}
		else if (command.mode == AddressMode::ZeroPageIndexedX)
		{
			auto zeroPageAddress = m_bus->read(programCounter + 1, 1)[0];
			auto indexX = m_processingUnit->getRegisterX();

			value = m_bus->read(zeroPageAddress + indexX, 1)[0];
		}
		else if (command.mode == AddressMode::ZeroPageIndexedY)
		{
			auto zeroPageAddress = m_bus->read(programCounter + 1, 1)[0];
			auto indexY = m_processingUnit->getRegisterY();

			value = m_bus->read(zeroPageAddress + indexY, 1)[0];
		}
		else if (command.mode == AddressMode::ZeroPageIndexedIndirect)
		{
			auto zeroPageAddress = m_bus->read(programCounter + 1, 1)[0];
			auto indexX = m_processingUnit->getRegisterX();
			auto indirectAddress = m_bus->read(zeroPageAddress + indexX, 2);

			auto address = (WORD)indirectAddress[1] << 8 + indirectAddress[0];

			value = m_bus->read(address, 1)[0];
		}
		else if (command.mode == AddressMode::ZeroPageIndirectIndexedY)
		{
			auto zeroPageAddress = m_bus->read(programCounter + 1, 1)[0];
			auto indexY = m_processingUnit->getRegisterY();
			auto indirectAddress = m_bus->read(zeroPageAddress + indexY, 2);

			auto address = (WORD)indirectAddress[1] << 8 + indirectAddress[0];

			value = m_bus->read(address, 1)[0];
		}

		//Jump and Branch
		if (command.mode == AddressMode::Relative)
		{
			auto offset = m_bus->read(programCounter + 1, 1)[0];
			auto commandAction = std::any_cast<std::function<void(BYTE)>>(m_commandMap[command.commnadName]);
			commandAction(offset);

			continue;
		}

		if (command.commnadName == "JMP" || command.commnadName == "JSR")
		{
			auto commandAction = std::any_cast<std::function<void(WORD)>>(m_commandMap[command.commnadName]);


			if (command.mode == AddressMode::Absolute)
			{
				auto parameter = m_bus->read(programCounter + 1, 2);
				auto address = (WORD)parameter[1] << 8 + parameter[0];

				commandAction(address);
			}
			else if (command.mode == AddressMode::AbsoluteIndirect)
			{
				commandAction(value);
			}

			continue;
		}

		//Execute
		if (m_commandMap[command.commnadName].type() == typeid(std::function<void()>))
		{
			auto commandAction = std::any_cast<std::function<void()>>(m_commandMap[command.commnadName]);
			commandAction();
		}
		else if (m_commandMap[command.commnadName].type() == typeid(std::function<void(BYTE)>))
		{
			auto commandAction = std::any_cast<std::function<void(BYTE)>>(m_commandMap[command.commnadName]);
			commandAction(value);
		}
		else if (m_commandMap[command.commnadName].type() == typeid(std::function<BYTE()>))
		{
			auto commandAction = std::any_cast<std::function<BYTE()>>(m_commandMap[command.commnadName]);
			writeback = true;
			value = commandAction();
		}
		else if (m_commandMap[command.commnadName].type() == typeid(std::function<BYTE(BYTE)>))
		{
			auto commandAction = std::any_cast<std::function<BYTE(BYTE)>>(m_commandMap[command.commnadName]);
			value = commandAction(value);
		}
		else
		{
			std::cout << "Unsupported command" << std::endl;
		}

		//Write back
		if (writeback)
		{
			if (command.mode == AddressMode::Accumulator)
			{
				m_processingUnit->setAccumulator(value);
			}
			else if (command.mode == AddressMode::Absolute)
			{
				auto parameter = m_bus->read(programCounter + 1, 2);
				auto address = (WORD)parameter[1] << 8 + parameter[0];

				m_bus->write(address, std::vector<BYTE>{ (BYTE)value});
			}
			else if (command.mode == AddressMode::ZeroPage)
			{
				auto address = m_bus->read(programCounter + 1, 1)[0];

				m_bus->write(address, std::vector<BYTE>{ (BYTE)value});
			}
			else if (command.mode == AddressMode::AbsoluteIndexedX)
			{
				auto parameter = m_bus->read(programCounter + 1, 2);
				auto address = (WORD)parameter[1] << 8 + parameter[0];

				m_bus->write(address + m_processingUnit->getRegisterX(), std::vector<BYTE>{ (BYTE)value});
			}
			else if (command.mode == AddressMode::AbsoulteIndexedY)
			{
				auto parameter = m_bus->read(programCounter + 1, 2);
				auto address = (WORD)parameter[1] << 8 + parameter[0];

				m_bus->write(address + m_processingUnit->getRegisterY(), std::vector<BYTE>{ (BYTE)value});
			}
			else if (command.mode == AddressMode::ZeroPageIndexedX)
			{
				auto zeroPageAddress = m_bus->read(programCounter + 1, 1)[0];
				auto indexX = m_processingUnit->getRegisterX();

				m_bus->write(zeroPageAddress + indexX, std::vector<BYTE>{ (BYTE)value});
			}
			else if (command.mode == AddressMode::ZeroPageIndexedY)
			{
				auto zeroPageAddress = m_bus->read(programCounter + 1, 1)[0];
				auto indexY = m_processingUnit->getRegisterY();

				m_bus->write(zeroPageAddress + indexY, std::vector<BYTE>{ (BYTE)value});
			}
			else if (command.mode == AddressMode::ZeroPageIndexedIndirect)
			{
				auto zeroPageAddress = m_bus->read(programCounter + 1, 1)[0];
				auto indexX = m_processingUnit->getRegisterX();
				auto indirectAddress = m_bus->read(zeroPageAddress + indexX, 2);

				auto address = (WORD)indirectAddress[1] << 8 + indirectAddress[0];

				m_bus->write(address, std::vector<BYTE>{ (BYTE)value});
			}
			else if (command.mode == AddressMode::ZeroPageIndirectIndexedY)
			{
				auto zeroPageAddress = m_bus->read(programCounter + 1, 1)[0];
				auto indexY = m_processingUnit->getRegisterY();
				auto indirectAddress = m_bus->read(zeroPageAddress + indexY, 2);

				auto address = (WORD)indirectAddress[1] << 8 + indirectAddress[0];

				m_bus->write(address, std::vector<BYTE>{ (BYTE)value});
			}
		}

		// Increase Program Counter
		if (command.mode == AddressMode::Accumulator)
		{
			programCounter += 1;
		}
		else if (command.mode == AddressMode::Immediate)
		{
			programCounter += 2;
		}
		else if (command.mode == AddressMode::Absolute)
		{
			programCounter += 3;
		}
		else if (command.mode == AddressMode::ZeroPage)
		{
			programCounter += 2;
		}
		else if (command.mode == AddressMode::AbsoluteIndexedX)
		{
			programCounter += 3;
		}
		else if (command.mode == AddressMode::AbsoulteIndexedY)
		{
			programCounter += 3;
		}
		else if (command.mode == AddressMode::ZeroPageIndexedX)
		{
			programCounter += 2;
		}
		else if (command.mode == AddressMode::ZeroPageIndexedY)
		{
			programCounter += 2;
		}
		else if (command.mode == AddressMode::ZeroPageIndexedIndirect)
		{
			programCounter += 2;
		}
		else if (command.mode == AddressMode::ZeroPageIndirectIndexedY)
		{
			programCounter += 2;
		}

		m_processingUnit->setProgramCounter(programCounter);
	}
}
