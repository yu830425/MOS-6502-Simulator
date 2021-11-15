#pragma once
#include "Device.h"

class Memory : public Device
{
public:
	Memory(int sizeOfMemory);

	void write(WORD address, const std::vector<BYTE>& data) override;
	std::vector<BYTE> read(WORD address, int size) override;

private:
	std::vector<BYTE> m_memory;
};
