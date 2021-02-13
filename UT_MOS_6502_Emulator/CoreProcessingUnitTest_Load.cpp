#include "gtest/gtest.h"
#include "../MOS_6502_Emulator/CoreProcessingUnit.h"

using ::testing::Test;

TEST(CoreProcessingUnit, LDA_changeNegativeFlag)
{
	CoreProcessingUnit testItem;

	testItem.LDA(0x80);

	auto negative = testItem.getFlag('N');
	auto accumulator = testItem.getAccumulator();

	ASSERT_TRUE(negative);
	ASSERT_EQ(0x80, accumulator);
}

TEST(CoreProcessingUnit, LDA_changeZeroFlag)
{
	CoreProcessingUnit testItem;

	testItem.LDA(0x00);

	auto zero = testItem.getFlag('Z');
	auto accumulator = testItem.getAccumulator();

	ASSERT_TRUE(zero);
	ASSERT_EQ(0x00, accumulator);
}

TEST(CoreProcessingUnit, LDX_changeNegativeFlag)
{
	CoreProcessingUnit testItem;

	testItem.LDX(0x80);

	auto negative = testItem.getFlag('N');
	auto registerX = testItem.getRegisterX();

	ASSERT_TRUE(negative);
	ASSERT_EQ(0x80, registerX);
}

TEST(CoreProcessingUnit, LDX_changeZeroFlag)
{
	CoreProcessingUnit testItem;

	testItem.LDX(0x00);

	auto zero = testItem.getFlag('Z');
	auto registerX = testItem.getRegisterX();

	ASSERT_TRUE(zero);
	ASSERT_EQ(0x00, registerX);
}

TEST(CoreProcessingUnit, LDY_changeNegativeFlag)
{
	CoreProcessingUnit testItem;

	testItem.LDY(0x80);

	auto negative = testItem.getFlag('N');
	auto registerY = testItem.getRegisterY();

	ASSERT_TRUE(negative);
	ASSERT_EQ(0x80, registerY);
}

TEST(CoreProcessingUnit, LDY_changeZeroFlag)
{
	CoreProcessingUnit testItem;

	testItem.LDY(0x00);

	auto zero = testItem.getFlag('Z');
	auto registerY = testItem.getRegisterY();

	ASSERT_TRUE(zero);
	ASSERT_EQ(0x00, registerY);
}