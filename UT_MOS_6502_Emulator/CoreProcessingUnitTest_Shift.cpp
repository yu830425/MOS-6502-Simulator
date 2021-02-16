#include "gtest/gtest.h"
#include "../MOS_6502_Emulator/CoreProcessingUnit.h"

using ::testing::Test;

TEST(CoreProcessingUnit, ASL_0x40ShiftLeft1Bit_ReturnShouldBe0x80)
{
	CoreProcessingUnit testItem;

	auto result = testItem.ASL(0x40);

	ASSERT_EQ(0x80, result);
}

TEST(CoreProcessingUnit, ASL_Bit7Is1_SetCarryFlag)
{
	CoreProcessingUnit testItem;

	auto result = testItem.ASL(0x80);
	ASSERT_EQ(0x00, result);

	auto carry = testItem.getFlag('C');
	ASSERT_TRUE(carry);
}

TEST(CoreProcessingUnit, ASL_ResultIsZero_SetZeroFlag)
{
	CoreProcessingUnit testItem;

	auto result = testItem.ASL(0x80);
	ASSERT_EQ(0x00, result);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(CoreProcessingUnit, ASL_ResultIsNegative_SetNegativeFlag)
{
	CoreProcessingUnit testItem;

	auto result = testItem.ASL(0x40);
	ASSERT_EQ(0x80, result);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(CoreProcessingUnit, LSR_0x80ShiftRight1Bit_ReturnShouldBe0x40)
{
	CoreProcessingUnit testItem;

	auto result = testItem.LSR(0x80);

	ASSERT_EQ(0x40, result);
}

TEST(CoreProcessingUnit, LSR_Bit0Is1_SetCarryFlag)
{
	CoreProcessingUnit testItem;

	auto result = testItem.LSR(0x01);
	ASSERT_EQ(0x00, result);

	auto carry = testItem.getFlag('C');
	ASSERT_TRUE(carry);
}

TEST(CoreProcessingUnit, LSR_ResultIsZero_SetZeroFlag)
{
	CoreProcessingUnit testItem;

	auto result = testItem.LSR(0x01);
	ASSERT_EQ(0x00, result);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}