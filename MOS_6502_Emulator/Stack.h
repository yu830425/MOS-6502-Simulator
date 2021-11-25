#pragma once

#include "BasicType.h"
#include <memory>
#include "Bus.h"

class Stack
{
public:
	Stack();

	virtual void push(BYTE value);
	virtual BYTE pop();
	virtual BYTE getStackPointer();
	virtual	void setStackPointer(BYTE value);

	void setBus(std::shared_ptr<Bus> bus);

private:
	std::shared_ptr<Bus> m_bus;
	BYTE m_stackPointer;
};
