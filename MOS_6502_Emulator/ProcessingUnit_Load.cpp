#include "ProcessingUnit.h"

void ProcessingUnit::setRegister(BYTE& cpuRegister, BYTE value)
{
	cpuRegister = value;

	m_negative = (value & 0x80) != 0;
	m_zero = value == 0;
}

void ProcessingUnit::LDA(BYTE value)
{
	setRegister(m_accumulator, value);
	m_programCounter++;
}

void ProcessingUnit::LDX(BYTE value)
{
	setRegister(m_registerX, value);
	m_programCounter++;
}

void ProcessingUnit::LDY(BYTE value)
{
	setRegister(m_registerY, value);
	m_programCounter++;
}
