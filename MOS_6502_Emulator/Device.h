#pragma once

#include "BasicType.h"
#include <vector>

class Device
{
public:
	Device() = default;

	virtual void write(WORD address, const std::vector<BYTE> &data) = 0;
	virtual std::vector<BYTE> read(WORD address, int size) = 0;
};
