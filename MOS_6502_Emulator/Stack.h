#pragma once

#include "BasicType.h"
#include "IStack.h"

class Stack : public IStack
{
public:
	void push(BYTE value) override;
	BYTE pop() override;
	BYTE getStackPointer() override;
	void setStackPointer(BYTE value) override;
};
