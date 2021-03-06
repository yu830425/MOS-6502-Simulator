#pragma once
#include "BasicType.h"

class IStack
{
public:
	virtual void push(BYTE value) = 0;
	virtual BYTE pop() = 0;
	virtual BYTE getStackPointer() = 0;
	virtual void setStackPointer(BYTE value) = 0;
};
