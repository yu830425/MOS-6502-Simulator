#include "Memory.h"

Memory::Memory(int sizeOfMemory) : m_memory(sizeOfMemory, 0)
{
}

void Memory::write(WORD address, const std::vector<BYTE>& data)
{
	auto ptr = address;

	for (auto dataPerByte : data)
	{
		m_memory[ptr] = dataPerByte;
		ptr++;
	}
}

std::vector<BYTE> Memory::read(WORD address, int size)
{
	std::vector<BYTE> result;

	for (auto i = 0; i < size; i++)
	{
		result.push_back(m_memory[address + i]);
	}

	return result;
}
