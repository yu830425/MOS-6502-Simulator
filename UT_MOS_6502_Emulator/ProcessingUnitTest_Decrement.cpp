#include "gtest/gtest.h"
#include "../MOS_6502_Emulator/ProcessingUnit.h"

using ::testing::Test;

TEST(ProcessingUnit, DEC_Input2_Return1)
{
	ProcessingUnit testItem;

	auto result = testItem.DEC(0x02);

	ASSERT_EQ(0x01, result);
}

TEST(ProcessingUnit, DEC_ResultIsNegative_SetNegativeFlag)
{
	ProcessingUnit testItem;

	auto result = testItem.DEC(0x00);
	ASSERT_EQ(0xFF, result);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(ProcessingUnit, DEC_ResultIsZero_SetZeroFlag)
{
	ProcessingUnit testItem;

	auto result = testItem.DEC(0x01);
	ASSERT_EQ(0x00, result);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(ProcessingUnit, DEX_RegisterXis2_RegisterXBecome1)
{
	ProcessingUnit testItem;
	testItem.LDX(0x02);

	testItem.DEX();

	auto registerX = testItem.getRegisterX();
	ASSERT_EQ(0x01, registerX);
}

TEST(ProcessingUnit, DEX_RegisterXIsNegative_SetNegativeFlag)
{
	ProcessingUnit testItem;
	testItem.LDX(0x00);

	testItem.DEX();

	auto registerX = testItem.getRegisterX();
	ASSERT_EQ(0xFF, registerX);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(ProcessingUnit, DEX_RegisterXIsZero_SetZeroFlag)
{
	ProcessingUnit testItem;
	testItem.LDX(0x01);

	testItem.DEX();

	auto registerX = testItem.getRegisterX();
	ASSERT_EQ(0x00, registerX);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(ProcessingUnit, DEY_RegisterYis2_RegisterYBecome1)
{
	ProcessingUnit testItem;
	testItem.LDY(0x02);

	testItem.DEY();

	auto registerX = testItem.getRegisterY();
	ASSERT_EQ(0x01, registerX);
}

TEST(ProcessingUnit, DEY_RegisterYIsNegative_SetNegativeFlag)
{
	ProcessingUnit testItem;
	testItem.LDY(0x00);

	testItem.DEY();

	auto registerX = testItem.getRegisterY();
	ASSERT_EQ(0xFF, registerX);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(ProcessingUnit, DEY_RegisterYIsZero_SetZeroFlag)
{
	ProcessingUnit testItem;
	testItem.LDY(0x01);

	testItem.DEY();

	auto registerX = testItem.getRegisterY();
	ASSERT_EQ(0x00, registerX);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}