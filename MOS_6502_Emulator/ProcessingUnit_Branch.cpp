#include "ProcessingUnit.h"

void ProcessingUnit::branch(bool criteria, BYTE value)
{
	if (criteria)
	{
		BYTE lowerByte = m_programCounter & 0xFF;

		lowerByte += value;

		m_programCounter &= 0xFF00;
		m_programCounter |= lowerByte;
	}
	m_programCounter += 2;
}

void ProcessingUnit::BCC(BYTE value)
{
	branch(!m_carry, value);
}

void ProcessingUnit::BCS(BYTE value)
{
	branch(m_carry, value);
}

void ProcessingUnit::BNE(BYTE value)
{
	branch(!m_zero, value);
}

void ProcessingUnit::BEQ(BYTE value)
{
	branch(m_zero, value);
}

void ProcessingUnit::BPL(BYTE value)
{
	branch(!m_negative, value);
}

void ProcessingUnit::BMI(BYTE value)
{
	branch(m_negative, value);
}

void ProcessingUnit::BVC(BYTE value)
{
	branch(!m_overflow, value);
}

void ProcessingUnit::BVS(BYTE value)
{
	branch(m_overflow, value);
}
