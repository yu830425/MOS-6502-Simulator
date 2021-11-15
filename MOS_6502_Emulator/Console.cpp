#include "Console.h"
#include <iostream>

void Console::write(WORD address, const std::vector<BYTE>& data)
{
	for (auto dataPerByte : data)
	{
		std::cout << dataPerByte;
	}

	std::cout << std::endl;
}

std::vector<BYTE> Console::read(WORD address, int size)
{
	return {};
}
