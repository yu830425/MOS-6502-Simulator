#include "ProcessingUnit.h"

BYTE ProcessingUnit::STA()
{
	m_programCounter++;
	return m_accumulator;
}

BYTE ProcessingUnit::STX()
{
	m_programCounter++;
	return m_registerX;
}

BYTE ProcessingUnit::STY()
{
	m_programCounter++;
	return m_registerY;
}