#include "CoreProcessingUnit.h"

void CoreProcessingUnit::AND(BYTE value)
{
	BYTE result = m_accumulator & value;

	setRegister(m_accumulator, result);
}

void CoreProcessingUnit::ORA(BYTE value)
{
	BYTE result = m_accumulator | value;

	setRegister(m_accumulator, result);
}

void CoreProcessingUnit::EOR(BYTE value)
{
	BYTE result = m_accumulator ^ value;

	setRegister(m_accumulator, result);
}
