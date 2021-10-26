#include "ProcessingUnit.h"

void ProcessingUnit::JMP(WORD address)
{
	m_programCounter = address;
}

void ProcessingUnit::JSR(WORD address)
{
	BYTE upperByte = m_programCounter >> 8;
	BYTE lowerByte = m_programCounter & 0xFF;
	m_spStackController->push(m_programCounter >> 8);
	m_spStackController->push(m_programCounter & 0xFF);

	m_programCounter = address;
}

void ProcessingUnit::RTS()
{
	BYTE lowerByte = m_spStackController->pop();
	BYTE upperByte = m_spStackController->pop();

	m_programCounter = upperByte << 8;
	m_programCounter |= lowerByte;
}
