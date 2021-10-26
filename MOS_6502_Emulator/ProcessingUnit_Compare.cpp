#include "ProcessingUnit.h"

void ProcessingUnit::compare(BYTE cpuRegister, BYTE value)
{
	m_negative = cpuRegister < value;
	m_zero = cpuRegister == value;
	m_carry = cpuRegister >= value;
}

void ProcessingUnit::CMP(BYTE value)
{
	compare(m_accumulator, value);
}

void ProcessingUnit::CPX(BYTE value)
{
	compare(m_registerX, value);
}

void ProcessingUnit::CPY(BYTE value)
{
	compare(m_registerY, value);
}

void ProcessingUnit::BIT(BYTE value)
{
	BYTE result = m_accumulator & value;

	m_zero = result == 0;
	m_negative = (value & 0x80) != 0;
	m_overflow = (value & 0x40) != 0;
}

