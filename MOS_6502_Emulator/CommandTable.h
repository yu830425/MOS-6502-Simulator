#pragma once

#include <unordered_map>
#include <string>

using namespace std;

enum AddressMode
{
	Accumulator,
	Implied,
	Immediate,
	Absolute,
	ZeroPage,
	Relative,
	AbsoluteIndirect,
	AbsoluteIndexedX,
	AbsoulteIndexedY,
	ZeroPageIndexedX,
	ZeroPageIndexedY,
	ZeroPageIndexedIndirect,
	ZeroPageIndirectIndexedY
};

struct Command
{
	string commnadName;
	AddressMode mode;
};

unordered_map<char, Command> createCommandMap();
