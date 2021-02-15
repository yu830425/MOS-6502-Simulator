#include "CoreProcessingUnit.h"

BYTE CoreProcessingUnit::STA()
{
	return m_accumulator;
}

BYTE CoreProcessingUnit::STX()
{
	return m_registerX;
}

BYTE CoreProcessingUnit::STY()
{
	return m_registerY;
}