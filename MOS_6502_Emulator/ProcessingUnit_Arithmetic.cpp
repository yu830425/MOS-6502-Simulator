#include "ProcessingUnit.h"

void ProcessingUnit::ADC(BYTE value)
{
	BYTE carry = m_carry ? 1 : 0;
	WORD result = m_accumulator + value + carry;
	BYTE temp = result & 0xFF;

	m_carry = result > 255;
	m_negative = (result & 0x80) != 0;
	m_zero = temp == 0;
	m_overflow = ((~m_accumulator & ~value & temp | m_accumulator & value & ~temp) & 0x80) != 0;

	m_accumulator = result & 0xFF;

	m_programCounter++;
}

void ProcessingUnit::SBC(BYTE value)
{
	BYTE borrow = m_carry ? 0 : 1;
	WORD result = m_accumulator - value - borrow;
	BYTE temp = result & 0xFF;

	m_zero = (result & 0xFF) == 0;
	m_negative = (result & 0x80) != 0;
	m_carry = m_accumulator < value;
	m_overflow = ((temp & ~m_accumulator & value | ~temp & m_accumulator & ~value) & 0x80) != 0;

	m_accumulator = result & 0xFF;

	m_programCounter++;
}