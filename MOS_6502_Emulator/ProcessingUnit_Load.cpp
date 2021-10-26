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
}

void ProcessingUnit::LDX(BYTE value)
{
	setRegister(m_registerX, value);
}

void ProcessingUnit::LDY(BYTE value)
{
	setRegister(m_registerY, value);
}
