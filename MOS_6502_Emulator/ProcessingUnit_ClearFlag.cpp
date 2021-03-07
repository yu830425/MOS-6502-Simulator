#include "ProcessingUnit.h"

void ProcessingUnit::CLC()
{
	m_carry = false;
	m_programCounter++;
}

void ProcessingUnit::CLD()
{
	m_decimal = false;
	m_programCounter++;
}

void ProcessingUnit::CLI()
{
	m_interrupt = false;
	m_programCounter++;
}

void ProcessingUnit::CLV()
{
	m_overflow = false;
	m_programCounter++;
}