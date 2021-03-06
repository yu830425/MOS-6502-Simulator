#include "gtest/gtest.h"
#include "../MOS_6502_Emulator/ProcessingUnit.h"

using ::testing::Test;

TEST(ProcessingUnit, ASL_0x40ShiftLeft1Bit_ReturnShouldBe0x80)
{
	ProcessingUnit testItem;

	auto result = testItem.ASL(0x40);

	ASSERT_EQ(0x80, result);
}

TEST(ProcessingUnit, ASL_Bit7Is1_SetCarryFlag)
{
	ProcessingUnit testItem;

	auto result = testItem.ASL(0x80);
	ASSERT_EQ(0x00, result);

	auto carry = testItem.getFlag('C');
	ASSERT_TRUE(carry);
}

TEST(ProcessingUnit, ASL_ResultIsZero_SetZeroFlag)
{
	ProcessingUnit testItem;

	auto result = testItem.ASL(0x80);
	ASSERT_EQ(0x00, result);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(ProcessingUnit, ASL_ResultIsNegative_SetNegativeFlag)
{
	ProcessingUnit testItem;

	auto result = testItem.ASL(0x40);
	ASSERT_EQ(0x80, result);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(ProcessingUnit, LSR_0x80ShiftRight1Bit_ReturnShouldBe0x40)
{
	ProcessingUnit testItem;

	auto result = testItem.LSR(0x80);

	ASSERT_EQ(0x40, result);
}

TEST(ProcessingUnit, LSR_Bit0Is1_SetCarryFlag)
{
	ProcessingUnit testItem;

	auto result = testItem.LSR(0x01);
	ASSERT_EQ(0x00, result);

	auto carry = testItem.getFlag('C');
	ASSERT_TRUE(carry);
}

TEST(ProcessingUnit, LSR_ResultIsZero_SetZeroFlag)
{
	ProcessingUnit testItem;

	auto result = testItem.LSR(0x01);
	ASSERT_EQ(0x00, result);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}