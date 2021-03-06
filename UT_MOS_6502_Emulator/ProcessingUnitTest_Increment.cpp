#include "gtest/gtest.h"
#include "../MOS_6502_Emulator/ProcessingUnit.h"

using ::testing::Test;

TEST(ProcessingUnit, INC_Input1_Return2)
{
	ProcessingUnit testItem;

	auto result = testItem.INC(0x01);

	ASSERT_EQ(0x02, result);
}

TEST(ProcessingUnit, INC_ResultIsNegative_SetNegativeFlag)
{
	ProcessingUnit testItem;

	auto result = testItem.INC(0xFE);
	ASSERT_EQ(0xFF, result);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(ProcessingUnit, INC_ResultIsZero_SetZeroFlag)
{
	ProcessingUnit testItem;

	auto result = testItem.INC(0xFF);
	ASSERT_EQ(0x00, result);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(ProcessingUnit, INX_RegisterXis2_RegisterXBecome3)
{
	ProcessingUnit testItem;
	testItem.LDX(0x02);

	testItem.INX();

	auto registerX = testItem.getRegisterX();
	ASSERT_EQ(0x03, registerX);
}

TEST(ProcessingUnit, INX_RegisterXIsNegative_SetNegativeFlag)
{
	ProcessingUnit testItem;
	testItem.LDX(0xFE);

	testItem.INX();

	auto registerX = testItem.getRegisterX();
	ASSERT_EQ(0xFF, registerX);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(ProcessingUnit, INX_RegisterXIsZero_SetZeroFlag)
{
	ProcessingUnit testItem;
	testItem.LDX(0xFF);

	testItem.INX();

	auto registerX = testItem.getRegisterX();
	ASSERT_EQ(0x00, registerX);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(ProcessingUnit, INY_RegisterYis2_RegisterYBecome3)
{
	ProcessingUnit testItem;
	testItem.LDY(0x02);

	testItem.INY();

	auto registerX = testItem.getRegisterY();
	ASSERT_EQ(0x03, registerX);
}

TEST(ProcessingUnit, INY_RegisterYIsNegative_SetNegativeFlag)
{
	ProcessingUnit testItem;
	testItem.LDY(0xFE);

	testItem.INY();

	auto registerX = testItem.getRegisterY();
	ASSERT_EQ(0xFF, registerX);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(ProcessingUnit, INY_RegisterYIsZero_SetZeroFlag)
{
	ProcessingUnit testItem;
	testItem.LDY(0xFF);

	testItem.INY();

	auto registerX = testItem.getRegisterY();
	ASSERT_EQ(0x00, registerX);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}
