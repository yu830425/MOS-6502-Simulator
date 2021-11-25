#include "Stack.h"

Stack::Stack()
{
	m_stackPointer = 0x01FF;
}

void Stack::push(BYTE value)
{
	m_bus->write(m_stackPointer, { value });
	m_stackPointer--;
}

BYTE Stack::pop()
{
	BYTE data = m_bus->read(m_stackPointer + 1, 1)[0];
	m_stackPointer++;

	return data;
}

BYTE Stack::getStackPointer()
{
	return m_stackPointer;
}

void Stack::setStackPointer(BYTE value)
{
	m_stackPointer = value;
}

void Stack::setBus(std::shared_ptr<Bus> bus)
{
	m_bus = bus;
}
