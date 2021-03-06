#include "ProcessingUnit.h"

void ProcessingUnit::SEC()
{
	m_carry = true;
}

void ProcessingUnit::SED()
{
	m_decimal = true;
}

void ProcessingUnit::SEI()
{
	m_interrupt = true;
}
