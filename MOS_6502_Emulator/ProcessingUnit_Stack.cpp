#include "ProcessingUnit.h"

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
	m_negative = ((processStatus & 0b10000000) != 0);
	m_overflow = ((processStatus & 0b01000000) != 0);
	m_break = ((processStatus & 0b00010000) != 0);
	m_decimal = ((processStatus & 0b00001000) != 0);
	m_interrupt = ((processStatus & 0b00000100) != 0);
	m_zero = ((processStatus & 0b00000010) != 0);
	m_carry = ((processStatus & 0b00000001) != 0);
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

