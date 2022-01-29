#include "gtest/gtest.h"
#include <fstream>
#include "../MOS_6502_Emulator/BinaryLoader.h"

void createTestBin()
{
	char version = 2;
	char cpuVersion = 0;
	char spAddress = 0x20;
	char loadAddress[2] = { 0x00, 0x02 };
	char resetAddress[2] = { 0x00, 0x02 };

	char program[3] = { 0xD8, 0xA2, 0xFF };

	std::fstream binary("test.bin", std::ios::binary | std::ios::out);
	binary << "sim65";
	binary.write(&version, 1);
	binary.write(&cpuVersion, 1);
	binary.write(&spAddress, 1);
	binary.write(loadAddress, 2);
	binary.write(resetAddress, 2);
	binary.write(program, 3);

	binary.flush();
	binary.close();
}

TEST(BinaryLoaderTest, isValid_CorrectSignature_ReturnTrue)
{
	createTestBin();

	BinaryLoader loader("test.bin");

	auto result = loader.isValid();

	ASSERT_EQ(result, true);
}

TEST(BinaryLoaderTest, getAddress)
{
	createTestBin();

	BinaryLoader loader("test.bin");

	auto spAddress = loader.getSpAddress();
	ASSERT_EQ(spAddress, 0x20);

	auto loadAddress = loader.getLoadAddress();
	ASSERT_EQ(loadAddress, 0x0200);

	auto resetAddress = loader.getResetAddress();
	ASSERT_EQ(resetAddress, 0x0200);
}

TEST(BinaryLoaderTest, getProgram)
{
	createTestBin();

	BinaryLoader loader("test.bin");

	auto progam = loader.getProgram();

	ASSERT_EQ(progam[0], 0xD8);
	ASSERT_EQ(progam[1], 0xA2);
	ASSERT_EQ(progam[2], 0xFF);
}