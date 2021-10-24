#pragma once

#include "BasicType.h"

class Stack
{
public:
	virtual void push(BYTE value);
	virtual BYTE pop();
	virtual BYTE getStackPointer();
	virtual	void setStackPointer(BYTE value);
};
