#include "CoreProcessingUnit.h"

void CoreProcessingUnit::setRegister(BYTE& cpuRegister, BYTE value)
{
	cpuRegister = value;

	m_negative = (value & 0x80) != 0;
	m_zero = value == 0;
}

void CoreProcessingUnit::LDA(BYTE value)
{
	setRegister(m_accumulator, value);
}

void CoreProcessingUnit::LDX(BYTE value)
{
	setRegister(m_registerX, value);
}

void CoreProcessingUnit::LDY(BYTE value)
{
	setRegister(m_registerY, value);
}

BYTE CoreProcessingUnit::STA()
{
	return m_accumulator;
}

BYTE CoreProcessingUnit::STX()
{
	return m_registerX;
}

BYTE CoreProcessingUnit::STY()
{
	return m_registerY;
}