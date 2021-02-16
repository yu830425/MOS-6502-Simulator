#include "gtest/gtest.h"
#include "../MOS_6502_Emulator/CoreProcessingUnit.h"

using ::testing::Test;

TEST(CoreProcessingUnit, DEC_Input2_Return1)
{
	CoreProcessingUnit testItem;

	auto result = testItem.DEC(0x02);

	ASSERT_EQ(0x01, result);
}

TEST(CoreProcessingUnit, DEC_ResultIsNegative_SetNegativeFlag)
{
	CoreProcessingUnit testItem;

	auto result = testItem.DEC(0x00);
	ASSERT_EQ(0xFF, result);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(CoreProcessingUnit, DEC_ResultIsZero_SetZeroFlag)
{
	CoreProcessingUnit testItem;

	auto result = testItem.DEC(0x01);
	ASSERT_EQ(0x00, result);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(CoreProcessingUnit, DEX_RegisterXis2_RegisterXBecome1)
{
	CoreProcessingUnit testItem;
	testItem.LDX(0x02);

	testItem.DEX();

	auto registerX = testItem.getRegisterX();
	ASSERT_EQ(0x01, registerX);
}

TEST(CoreProcessingUnit, DEX_RegisterXIsNegative_SetNegativeFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDX(0x00);

	testItem.DEX();

	auto registerX = testItem.getRegisterX();
	ASSERT_EQ(0xFF, registerX);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(CoreProcessingUnit, DEX_RegisterXIsZero_SetZeroFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDX(0x01);

	testItem.DEX();

	auto registerX = testItem.getRegisterX();
	ASSERT_EQ(0x00, registerX);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(CoreProcessingUnit, DEY_RegisterXis2_RegisterXBecome1)
{
	CoreProcessingUnit testItem;
	testItem.LDY(0x02);

	testItem.DEY();

	auto registerX = testItem.getRegisterY();
	ASSERT_EQ(0x01, registerX);
}

TEST(CoreProcessingUnit, DEY_RegisterXIsNegative_SetNegativeFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDY(0x00);

	testItem.DEY();

	auto registerX = testItem.getRegisterY();
	ASSERT_EQ(0xFF, registerX);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(CoreProcessingUnit, DEY_RegisterXIsZero_SetZeroFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDY(0x01);

	testItem.DEY();

	auto registerX = testItem.getRegisterY();
	ASSERT_EQ(0x00, registerX);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}