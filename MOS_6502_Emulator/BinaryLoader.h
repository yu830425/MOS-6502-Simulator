#pragma once
#include "BasicType.h"
#include <string>
#include <vector>

class BinaryLoader
{
public:
	BinaryLoader(std::string binaryPath);

	bool isValid();
	BYTE getSpAddress();

	WORD getLoadAddress();
	WORD getResetAddress();
	std::vector<BYTE> getProgram();
private:
	std::string m_signature;
	int m_version;
	int m_cpuType;
	BYTE m_spAddress;
	WORD m_loadAddress;
	WORD m_resetAddress;
	std::vector<BYTE> m_program;
};
