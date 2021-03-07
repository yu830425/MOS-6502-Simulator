#include "ProcessingUnit.h"

void ProcessingUnit::SEC()
{
	m_carry = true;
	m_programCounter++;
}

void ProcessingUnit::SED()
{
	m_decimal = true;
	m_programCounter++;
}

void ProcessingUnit::SEI()
{
	m_interrupt = true;
	m_programCounter++;
}
