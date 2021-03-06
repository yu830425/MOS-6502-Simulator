#include "ProcessingUnit.h"

void ProcessingUnit::TAX()
{
	setRegister(m_registerX, m_accumulator);
}

void ProcessingUnit::TAY()
{
	setRegister(m_registerY, m_accumulator);
}

void ProcessingUnit::TXA()
{
	setRegister(m_accumulator, m_registerX);
}

void ProcessingUnit::TXY()
{
	setRegister(m_accumulator, m_registerY);
}

void ProcessingUnit::TSX()
{
	setRegister(m_registerX, m_spStackController->getStackPointer());
}

void ProcessingUnit::TXS()
{
	m_spStackController->setStackPointer(m_registerX);
}
