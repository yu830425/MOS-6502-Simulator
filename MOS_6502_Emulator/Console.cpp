#include "Console.h"
#include <iostream>

void Console::write(WORD address, const std::vector<BYTE>& data)
{
	for (auto dataPerByte : data)
	{
		std::cout << dataPerByte;
	}

	std::cout.flush();
}

std::vector<BYTE> Console::read(WORD address, int size)
{
	return std::vector<BYTE>(size, 0);
}
