#include "CoreProcessingUnit.h"

void CoreProcessingUnit::SEC()
{
	m_carry = true;
}

void CoreProcessingUnit::CLC()
{
	m_carry = false;
}

void CoreProcessingUnit::SED()
{
	m_decimal = true;
}

void CoreProcessingUnit::CLD()
{
	m_decimal = false;
}

void CoreProcessingUnit::SEI()
{
	m_interrupt = true;
}

void CoreProcessingUnit::CLI()
{
	m_interrupt = false;
}

void CoreProcessingUnit::CLV()
{
	m_overflow = false;
}