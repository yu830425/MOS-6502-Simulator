#include "CoreProcessingUnit.h"

void CoreProcessingUnit::SEC()
{
	m_carry = true;
}

void CoreProcessingUnit::SED()
{
	m_decimal = true;
}

void CoreProcessingUnit::SEI()
{
	m_interrupt = true;
}
