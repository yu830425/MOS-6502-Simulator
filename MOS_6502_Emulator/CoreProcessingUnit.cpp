#include "CoreProcessingUnit.h"
#include <stdexcept>

using namespace std;

CoreProcessingUnit::CoreProcessingUnit()
	:m_negative(false),
	m_overflow(false),
	m_break(false),
	m_decimal(false),
	m_interrupt(false),
	m_zero(false),
	m_carry(false),
	m_accumulator(0x00),
	m_registerX(0x00),
	m_registerY(0x00),
{

}

bool CoreProcessingUnit::getFlag(char flagSymbol)
{
	//NVBDIZC
	switch (flagSymbol)
	{
	case 'N':
		return m_negative;
	case 'V':
		return m_overflow;
	case 'B':
		return m_break;
	case 'D':
		return m_decimal;
	case 'I':
		return m_interrupt;
	case 'Z':
		return m_zero;
	case 'C':
		return m_carry;
	}

	return false;
}

BYTE CoreProcessingUnit::getAccumulator()
{
	return m_accumulator;
}

BYTE CoreProcessingUnit::getRegisterX()
{
	return m_registerX;
}

BYTE CoreProcessingUnit::getRegisterY()
{
	return m_registerY;
}
