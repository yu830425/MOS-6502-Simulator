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
	m_registerY(0x00)
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

void ProcessingUnit::setStackController(shared_ptr<IStack> spStackController)
{
	m_spStackController = spStackController;
}

void ProcessingUnit::PHA()
{
	m_spStackController->push(m_accumulator);
}

void ProcessingUnit::PLA()
{
	setRegister(m_accumulator, m_spStackController->pop());
}

void ProcessingUnit::PHP()
{
	auto processStatus = composeStatus();

	m_spStackController->push(processStatus);
}

void ProcessingUnit::PLP()
{
	auto processStatus = m_spStackController->pop();

	setProcessStatus(processStatus);
}

BYTE ProcessingUnit::composeStatus()
{
	//NV(1)BDIZC
	BYTE status = 0b00100000;

	if (m_negative)  status |= 0b10000000;
	if (m_overflow)  status |= 0b01000000;
	if (m_break)	 status |= 0b00010000;
	if (m_decimal)	 status |= 0b00001000;
	if (m_interrupt) status |= 0b00000100;
	if (m_zero)		 status |= 0b00000010;
	if (m_carry)	 status |= 0b00000001;

	return status;
}

void ProcessingUnit::setProcessStatus(BYTE processStatus)
{
	m_negative	= ((processStatus & 0b10000000) != 0);
	m_overflow	= ((processStatus & 0b01000000) != 0);
	m_break		= ((processStatus & 0b00010000) != 0);
	m_decimal	= ((processStatus & 0b00001000) != 0);
	m_interrupt = ((processStatus & 0b00000100) != 0);
	m_zero		= ((processStatus & 0b00000010) != 0);
	m_carry		= ((processStatus & 0b00000001) != 0);
}
