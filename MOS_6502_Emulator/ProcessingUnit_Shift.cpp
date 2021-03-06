#include "ProcessingUnit.h"

BYTE ProcessingUnit::ASL(BYTE value)
{
	BYTE result = value << 1;

	m_negative = (result & 0x80) != 0;
	m_zero = result == 0;
	m_carry = (value & 0x80) != 0;

	return result;
}

BYTE ProcessingUnit::LSR(BYTE value)
{
	BYTE result = value >> 1;

	m_zero = result == 0;
	m_carry = (value & 0x01) != 0;
	m_negative = false;		//bit 7 will always be zero

	return result;
}