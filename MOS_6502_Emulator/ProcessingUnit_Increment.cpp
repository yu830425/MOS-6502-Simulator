#include "ProcessingUnit.h"

BYTE ProcessingUnit::INC(BYTE value)
{
	BYTE result = value + 1;

	m_negative = (result & 0x80) != 0;
	m_zero = result == 0;

	return result;
}

void ProcessingUnit::INX()
{
	m_registerX = INC(m_registerX);
}

void ProcessingUnit::INY()
{
	m_registerY = INC(m_registerY);
}
