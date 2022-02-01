#include "ProcessingUnit.h"

BYTE ProcessingUnit::ROL(BYTE value)
{
	BYTE result = value << 1;
	bool carry = m_carry;

	m_carry = (value & 0x80) != 0;

	result |= (carry ? 0x01 : 0x00);

	m_negative = (result & 0x80) != 0;
	m_zero = result == 0;

	return result;
}

BYTE ProcessingUnit::ROR(BYTE value)
{
	BYTE result = value >> 1;
	bool carry = m_carry;

	m_carry = (value & 0x01) != 0;

	result |= (carry ? 0x01 : 0x00) << 7;

	m_negative = (result & 0x80) != 0;
	m_zero = result == 0;

	return result;
}