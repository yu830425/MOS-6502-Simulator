#include "ProcessingUnit.h"

void ProcessingUnit::CLC()
{
	m_carry = false;
}

void ProcessingUnit::CLD()
{
	m_decimal = false;
}

void ProcessingUnit::CLI()
{
	m_interrupt = false;
}

void ProcessingUnit::CLV()
{
	m_overflow = false;
}