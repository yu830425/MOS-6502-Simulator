#include "gtest/gtest.h"
#include "../MOS_6502_Emulator/ProcessingUnit.h"

using ::testing::Test;

TEST(ProcessingUnit, LDA_LoadNegativeValue_SetNegativeFlag)
{
	ProcessingUnit testItem;

	testItem.LDA(0x80);

	auto negative = testItem.getFlag('N');
	auto accumulator = testItem.getAccumulator();

	ASSERT_TRUE(negative);
	ASSERT_EQ(0x80, accumulator);
}

TEST(ProcessingUnit, LDA_LoadZero_SetZeroFlag)
{
	ProcessingUnit testItem;

	testItem.LDA(0x00);

	auto zero = testItem.getFlag('Z');
	auto accumulator = testItem.getAccumulator();

	ASSERT_TRUE(zero);
	ASSERT_EQ(0x00, accumulator);
}

TEST(ProcessingUnit, LDX_LoadNegative_SetNegativeFlag)
{
	ProcessingUnit testItem;

	testItem.LDX(0x80);

	auto negative = testItem.getFlag('N');
	auto registerX = testItem.getRegisterX();

	ASSERT_TRUE(negative);
	ASSERT_EQ(0x80, registerX);
}

TEST(ProcessingUnit, LDX_LoadZero_SetZeroFlag)
{
	ProcessingUnit testItem;

	testItem.LDX(0x00);

	auto zero = testItem.getFlag('Z');
	auto registerX = testItem.getRegisterX();

	ASSERT_TRUE(zero);
	ASSERT_EQ(0x00, registerX);
}

TEST(ProcessingUnit, LDY_LoadNegative_SetNegativeFlag)
{
	ProcessingUnit testItem;

	testItem.LDY(0x80);

	auto negative = testItem.getFlag('N');
	auto registerY = testItem.getRegisterY();

	ASSERT_TRUE(negative);
	ASSERT_EQ(0x80, registerY);
}

TEST(ProcessingUnit, LDY_LoadZero_SetZeroFlag)
{
	ProcessingUnit testItem;

	testItem.LDY(0x00);

	auto zero = testItem.getFlag('Z');
	auto registerY = testItem.getRegisterY();

	ASSERT_TRUE(zero);
	ASSERT_EQ(0x00, registerY);
}