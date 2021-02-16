#include "gtest/gtest.h"
#include "../MOS_6502_Emulator/CoreProcessingUnit.h"

using ::testing::Test;

TEST(CoreProcessingUnit, INC_Input1_Return2)
{
	CoreProcessingUnit testItem;

	auto result = testItem.INC(0x01);

	ASSERT_EQ(0x02, result);
}

TEST(CoreProcessingUnit, INC_ResultIsNegative_SetNegativeFlag)
{
	CoreProcessingUnit testItem;

	auto result = testItem.INC(0xFE);
	ASSERT_EQ(0xFF, result);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(CoreProcessingUnit, INC_ResultIsZero_SetZeroFlag)
{
	CoreProcessingUnit testItem;

	auto result = testItem.INC(0xFF);
	ASSERT_EQ(0x00, result);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(CoreProcessingUnit, INX_RegisterXis2_RegisterXBecome3)
{
	CoreProcessingUnit testItem;
	testItem.LDX(0x02);

	testItem.INX();

	auto registerX = testItem.getRegisterX();
	ASSERT_EQ(0x03, registerX);
}

TEST(CoreProcessingUnit, INX_RegisterXIsNegative_SetNegativeFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDX(0xFE);

	testItem.INX();

	auto registerX = testItem.getRegisterX();
	ASSERT_EQ(0xFF, registerX);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(CoreProcessingUnit, INX_RegisterXIsZero_SetZeroFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDX(0xFF);

	testItem.INX();

	auto registerX = testItem.getRegisterX();
	ASSERT_EQ(0x00, registerX);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(CoreProcessingUnit, INY_RegisterXis2_RegisterXBecome3)
{
	CoreProcessingUnit testItem;
	testItem.LDY(0x02);

	testItem.INY();

	auto registerX = testItem.getRegisterY();
	ASSERT_EQ(0x03, registerX);
}

TEST(CoreProcessingUnit, INY_RegisterXIsNegative_SetNegativeFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDY(0xFE);

	testItem.INY();

	auto registerX = testItem.getRegisterY();
	ASSERT_EQ(0xFF, registerX);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(CoreProcessingUnit, INY_RegisterXIsZero_SetZeroFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDY(0xFF);

	testItem.INY();

	auto registerX = testItem.getRegisterY();
	ASSERT_EQ(0x00, registerX);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}
