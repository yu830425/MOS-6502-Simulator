#include "ProcessingUnit.h"

void ProcessingUnit::AND(BYTE value)
{
	BYTE result = m_accumulator & value;

	setRegister(m_accumulator, result);
}

void ProcessingUnit::ORA(BYTE value)
{
	BYTE result = m_accumulator | value;

	setRegister(m_accumulator, result);
}

void ProcessingUnit::EOR(BYTE value)
{
	BYTE result = m_accumulator ^ value;

	setRegister(m_accumulator, result);
}
