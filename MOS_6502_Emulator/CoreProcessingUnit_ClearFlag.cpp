#include "CoreProcessingUnit.h"

void CoreProcessingUnit::CLC()
{
	m_carry = false;
}

void CoreProcessingUnit::CLD()
{
	m_decimal = false;
}

void CoreProcessingUnit::CLI()
{
	m_interrupt = false;
}

void CoreProcessingUnit::CLV()
{
	m_overflow = false;
}