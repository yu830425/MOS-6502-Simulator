#include "ProcessingUnit.h"

BYTE ProcessingUnit::DEC(BYTE value)
{
	BYTE result = value - 1;

	m_negative = (result & 0x80) != 0;
	m_zero = result == 0;

	return result;
}

void ProcessingUnit::DEX()
{
	m_registerX = DEC(m_registerX);
}

void ProcessingUnit::DEY()
{
	m_registerY = DEC(m_registerY);
}