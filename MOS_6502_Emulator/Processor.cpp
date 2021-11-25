#include "Processor.h"
#include <iostream>

Processor::Processor()
{
	m_stack = make_shared<Stack>();

	m_processingUnit = make_shared<ProcessingUnit>();
	m_processingUnit->setStackController(m_stack);

	m_commandTable = createCommandMap();

	m_commandMap = std::unordered_map<string, any>{
		{"LDA", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->LDA(_1);})},
		{"LDX", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->LDX(_1);})},
		{"LDY", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->LDY(_1);})},
		{"STA", std::function<BYTE(void)>([&](){return m_processingUnit->STA();})},
		{"STX", std::function<BYTE(void)>([&](){return m_processingUnit->STX();})},
		{"STY", std::function<BYTE(void)>([&](){return m_processingUnit->STY();})},
		{"SEC", std::function<void(void)>([&](){m_processingUnit->SEC();})},
		{"CLC", std::function<void(void)>([&](){m_processingUnit->CLC();})},
		{"CLD", std::function<void(void)>([&](){m_processingUnit->CLD();})},
		{"SED", std::function<void(void)>([&](){m_processingUnit->SED();})},
		{"SEI", std::function<void(void)>([&](){m_processingUnit->SEI();})},
		{"CLI", std::function<void(void)>([&](){m_processingUnit->CLI();})},
		{"CLV", std::function<void(void)>([&](){m_processingUnit->CLV();})},
		{"ADC", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->ADC(_1);})},
		{"SBC", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->SBC(_1);})},
		{"INC", std::function<BYTE(BYTE)>([&](BYTE _1){ return m_processingUnit->INC(_1);})},
		{"INX", std::function<void(void)>([&](){m_processingUnit->INX();})},
		{"INY", std::function<void(void)>([&](){m_processingUnit->INY();})},
		{"DEC", std::function<BYTE(BYTE)>([&](BYTE _1){ return m_processingUnit->DEC(_1);})},
		{"DEX", std::function<void(void)>([&](){m_processingUnit->DEX();})},
		{"DEY", std::function<void(void)>([&](){m_processingUnit->DEY();})},
		{"ASL", std::function<BYTE(BYTE)>([&](BYTE _1){ return m_processingUnit->ASL(_1);})},
		{"LSR", std::function<BYTE(BYTE)>([&](BYTE _1){ return m_processingUnit->LSR(_1);})},
		{"ROL", std::function<BYTE(BYTE)>([&](BYTE _1){ return m_processingUnit->ROL(_1);})},
		{"ROR", std::function<BYTE(BYTE)>([&](BYTE _1){ return m_processingUnit->ROR(_1);})},
		{"AND", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->AND(_1);})},
		{"ORA", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->ORA(_1);})},
		{"EOR", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->EOR(_1);})},
		{"PHA", std::function<void(void)>([&](){m_processingUnit->PHA();})},
		{"PLA", std::function<void(void)>([&](){m_processingUnit->PLA();})},
		{"PHP", std::function<void(void)>([&](){m_processingUnit->PHP();})},
		{"PLP", std::function<void(void)>([&](){m_processingUnit->PLP();})},
		{"TAX", std::function<void(void)>([&](){m_processingUnit->TAX();})},
		{"TAY", std::function<void(void)>([&](){m_processingUnit->TAY();})},
		{"TXA", std::function<void(void)>([&](){m_processingUnit->TXA();})},
		{"TYA", std::function<void(void)>([&](){m_processingUnit->TYA();})},
		{"TSX", std::function<void(void)>([&](){m_processingUnit->TSX();})},
		{"TXS", std::function<void(void)>([&](){m_processingUnit->TXS();})},
		{"CMP", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->CMP(_1);})},
		{"CPX", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->CPX(_1);})},
		{"CPY", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->CPY(_1);})},
		{"BIT", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->BIT(_1);})},
		{"BCC", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->BCC(_1);})},
		{"BCS", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->BCS(_1);})},
		{"BNE", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->BNE(_1);})},
		{"BEQ", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->BEQ(_1);})},
		{"BPL", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->BPL(_1);})},
		{"BMI", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->BMI(_1);})},
		{"BVC", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->BVC(_1);})},
		{"BVS", std::function<void(BYTE)>([&](BYTE _1){m_processingUnit->BVS(_1);})},
		{"JMP", std::function<void(WORD)>([&](WORD _1){m_processingUnit->JMP(_1);})},
		{"JSR", std::function<void(WORD)>([&](WORD _1){m_processingUnit->JSR(_1);})},
		{"RTS", std::function<void(void)>([&](){m_processingUnit->RTS();})}
	};
}

void Processor::setProcessingUnit(std::shared_ptr<ProcessingUnit> processingUnit)
{
	m_processingUnit = processingUnit;
}

void Processor::setBus(std::shared_ptr<Bus> bus)
{
	m_bus = bus;
	m_stack->setBus(m_bus);
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
		auto x = m_processingUnit->getRegisterX();
		auto acc = m_processingUnit->getAccumulator();
		auto y = m_processingUnit->getRegisterY();

		auto opCode = m_bus->read(programCounter, 1)[0];

		if (programCounter == 0xFFF9)
		{
			cout << "Emulator is terminated. return code = " << (int)m_processingUnit->getAccumulator() << endl;
			break;
		}

		//Decode
		auto command = m_commandTable[opCode];

		//cout << command.commandName << endl;

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
			auto address = ((WORD)parameter[1] << 8) + parameter[0];

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
			auto address = ((WORD)parameter[1] << 8) + parameter[0];
			auto temp = m_bus->read(address, 2);

			value = ((WORD)temp[1] << 8) + temp[0];
		}
		else if (command.mode == AddressMode::AbsoluteIndexedX)
		{
			auto parameter = m_bus->read(programCounter + 1, 2);
			auto address = ((WORD)parameter[1] << 8) + parameter[0];

			value = m_bus->read(address + m_processingUnit->getRegisterX(), 1)[0];
		}
		else if (command.mode == AddressMode::AbsoulteIndexedY)
		{
			auto parameter = m_bus->read(programCounter + 1, 2);
			auto address = ((WORD)parameter[1] << 8) + parameter[0];

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

			auto address = ((WORD)indirectAddress[1] << 8) + indirectAddress[0];

			value = m_bus->read(address, 1)[0];
		}
		else if (command.mode == AddressMode::ZeroPageIndirectIndexedY)
		{
			auto zeroPageAddress = m_bus->read(programCounter + 1, 1)[0];
			auto indexY = m_processingUnit->getRegisterY();
			auto indirectAddress = m_bus->read(zeroPageAddress, 2);

			auto address = ((WORD)indirectAddress[1] << 8) + indirectAddress[0];

			value = m_bus->read(address + indexY, 1)[0];
		}

		//Jump and Branch
		if (command.mode == AddressMode::Relative)
		{
			auto offset = m_bus->read(programCounter + 1, 1)[0];
			auto commandAction = std::any_cast<std::function<void(BYTE)>>(m_commandMap[command.commandName]);
			commandAction(offset);

			continue;
		}

		if (command.commandName == "JMP" || command.commandName == "JSR")
		{
			auto commandAction = std::any_cast<std::function<void(WORD)>>(m_commandMap[command.commandName]);


			if (command.mode == AddressMode::Absolute)
			{
				auto parameter = m_bus->read(programCounter + 1, 2);
				auto address = ((WORD)parameter[1] << 8) + parameter[0];

				commandAction(address);
			}
			else if (command.mode == AddressMode::AbsoluteIndirect)
			{
				commandAction(value);
			}

			continue;
		}

		if (command.commandName == "RTS")
		{
			auto commandAction = std::any_cast<std::function<void()>>(m_commandMap[command.commandName]);
			commandAction();

			continue;
		}

		//Execute
		if (m_commandMap[command.commandName].type() == typeid(std::function<void()>))
		{
			auto commandAction = std::any_cast<std::function<void()>>(m_commandMap[command.commandName]);
			commandAction();
		}
		else if (m_commandMap[command.commandName].type() == typeid(std::function<void(BYTE)>))
		{
			auto commandAction = std::any_cast<std::function<void(BYTE)>>(m_commandMap[command.commandName]);
			commandAction(value);
		}
		else if (m_commandMap[command.commandName].type() == typeid(std::function<BYTE()>))
		{
			auto commandAction = std::any_cast<std::function<BYTE()>>(m_commandMap[command.commandName]);
			writeback = true;
			value = commandAction();
		}
		else if (m_commandMap[command.commandName].type() == typeid(std::function<BYTE(BYTE)>))
		{
			auto commandAction = std::any_cast<std::function<BYTE(BYTE)>>(m_commandMap[command.commandName]);
			value = commandAction(value);
		}
		else
		{
			std::cout << "Unsupported command" << std::endl;
			break;
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
				auto address = ((WORD)parameter[1] << 8) + parameter[0];

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
				auto address = ((WORD)parameter[1] << 8) + parameter[0];

				m_bus->write(address + m_processingUnit->getRegisterX(), std::vector<BYTE>{ (BYTE)value});
			}
			else if (command.mode == AddressMode::AbsoulteIndexedY)
			{
				auto parameter = m_bus->read(programCounter + 1, 2);
				auto address = ((WORD)parameter[1] << 8) + parameter[0];

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

				auto address = ((WORD)indirectAddress[1] << 8) + indirectAddress[0];

				m_bus->write(address, std::vector<BYTE>{ (BYTE)value});
			}
			else if (command.mode == AddressMode::ZeroPageIndirectIndexedY)
			{
				auto zeroPageAddress = m_bus->read(programCounter + 1, 1)[0];
				auto indexY = m_processingUnit->getRegisterY();
				auto indirectAddress = m_bus->read(zeroPageAddress, 2);

				auto address = ((WORD)indirectAddress[1] << 8) + indirectAddress[0];

				m_bus->write(address + indexY, std::vector<BYTE>{ (BYTE)value});
				//cout << (char)value << endl;
			}
		}

		// Increase Program Counter
		if (command.mode == AddressMode::Accumulator)
		{
			programCounter += 1;
		}
		else if (command.mode == AddressMode::Implied)
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
