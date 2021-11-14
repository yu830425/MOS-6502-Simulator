#include "ProcessingUnit.h"
#include <stdexcept>

using namespace std;

ProcessingUnit::ProcessingUnit()
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
	m_programCounter(0x0000)
{
	//m_spStackController = make_shared<Stack>();
}

bool ProcessingUnit::getFlag(char flagSymbol)
{
	//NV(1)BDIZC
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

BYTE ProcessingUnit::getAccumulator()
{
	return m_accumulator;
}

BYTE ProcessingUnit::getRegisterX()
{
	return m_registerX;
}

BYTE ProcessingUnit::getRegisterY()
{
	return m_registerY;
}

WORD ProcessingUnit::getProgramCounter()
{
	return m_programCounter;
}

void ProcessingUnit::setProgramCounter(WORD programCounter)
{
	m_programCounter = programCounter;
}

void ProcessingUnit::setStackController(shared_ptr<Stack> spStackController)
{
	m_spStackController = spStackController;
}

void ProcessingUnit::setAccumulator(BYTE accumulator)
{
	m_accumulator = accumulator;
}

