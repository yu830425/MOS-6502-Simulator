#include "ProcessingUnit.h"

BYTE ProcessingUnit::STA()
{
	return m_accumulator;
}

BYTE ProcessingUnit::STX()
{
	return m_registerX;
}

BYTE ProcessingUnit::STY()
{
	return m_registerY;
}