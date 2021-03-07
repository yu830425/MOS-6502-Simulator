#include "ProcessingUnit.h"

void ProcessingUnit::TAX()
{
	setRegister(m_registerX, m_accumulator);
	m_programCounter++;
}

void ProcessingUnit::TAY()
{
	setRegister(m_registerY, m_accumulator);
	m_programCounter++;
}

void ProcessingUnit::TXA()
{
	setRegister(m_accumulator, m_registerX);
	m_programCounter++;
}

void ProcessingUnit::TXY()
{
	setRegister(m_accumulator, m_registerY);
	m_programCounter++;
}

void ProcessingUnit::TSX()
{
	setRegister(m_registerX, m_spStackController->getStackPointer());
	m_programCounter++;
}

void ProcessingUnit::TXS()
{
	m_spStackController->setStackPointer(m_registerX);
	m_programCounter++;
}
