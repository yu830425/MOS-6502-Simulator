#pragma once
#include "Device.h"

class Console : public Device
{

public:
	virtual void write(WORD address, const std::vector<BYTE>& data) override;
	virtual std::vector<BYTE> read(WORD address, int size) override;
};
