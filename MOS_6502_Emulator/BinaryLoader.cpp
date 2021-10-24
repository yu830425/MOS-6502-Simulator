#include "BinaryLoader.h"
#include <fstream>

BinaryLoader::BinaryLoader(std::string binaryPath)
{
	std::ifstream inputBinary(binaryPath, std::ios::binary | std::ios::in);

	char signature[6] = { 0 };
	inputBinary.read(signature, 5);

	char version = 0;
	inputBinary.read(&version, 1);

	char cpuType = 0;
	inputBinary.read(&cpuType, 1);

	char spAddress = 0;
	inputBinary.read(&spAddress, 1);

	char loadAddress[2] = { 0 };
	inputBinary.read(loadAddress, 2);

	char resetAddress[2] = { 0 };
	inputBinary.read(resetAddress, 2);

	m_signature = signature;
	m_version = version;
	m_cpuType = cpuType;
	m_spAddress = spAddress;
	
	m_loadAddress = 0;
	m_loadAddress |= loadAddress[1];
	m_loadAddress |= ((int)loadAddress[0]) << 8;

	m_resetAddress = 0;
	m_resetAddress |= resetAddress[1];
	m_resetAddress |= ((int)resetAddress[0]) << 8;

	char data = 0;

	while (inputBinary.get(data))
	{
		m_program.push_back(data);
	}
}

bool BinaryLoader::isValid()
{
	return m_signature == "sim65";
}

BYTE BinaryLoader::getSpAddress()
{
	return m_spAddress;
}

WORD BinaryLoader::getLoadAddress()
{
	return m_loadAddress;
}

WORD BinaryLoader::getResetAddress()
{
	return m_resetAddress;
}

std::vector<BYTE> BinaryLoader::getProgram()
{
	return m_program;
}
