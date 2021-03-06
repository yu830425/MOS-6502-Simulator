#include "gtest/gtest.h"
#include "../MOS_6502_Emulator/ProcessingUnit.h"

using ::testing::Test;

TEST(ProcessingUnit, ROL_0xF0RotateLeft1Bit_ReturnShouldBe0xE1)
{
	ProcessingUnit testItem;

	auto result = testItem.ROL(0xF0);

	ASSERT_EQ(0xE1, result);
}

TEST(ProcessingUnit, ROL_0xF0RotateLeft2Bit_ReturnShouldBe0xC3)
{
	ProcessingUnit testItem;

	auto result = testItem.ROL(0xF0);
	result = testItem.ROL(result);

	ASSERT_EQ(0xC3, result);
}

TEST(ProcessingUnit, ROL_ResultIsNegative_SetNegativeFlag)
{
	ProcessingUnit testItem;

	auto result = testItem.ROL(0xF0);
	ASSERT_EQ(0xE1, result);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(ProcessingUnit, ROL_ResultIsZero_SetZeroFlag)
{
	ProcessingUnit testItem;

	auto result = testItem.ROL(0x00);
	ASSERT_EQ(0x00, result);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(ProcessingUnit, ROL_Bit7Is1_SetCarryFlag)
{
	ProcessingUnit testItem;

	auto result = testItem.ROL(0xF0);
	ASSERT_EQ(0xE1, result);

	auto carry = testItem.getFlag('C');
	ASSERT_TRUE(carry);
}

TEST(ProcessingUnit, ROR_0x0FRotateRight1Bit_ReturnShouldBe0x87)
{
	ProcessingUnit testItem;

	auto result = testItem.ROR(0x0F);

	ASSERT_EQ(0x87, result);
}

TEST(ProcessingUnit, ROR_ResultIsNegative_SetNegativeFlag)
{
	ProcessingUnit testItem;

	auto result = testItem.ROR(0x0F);
	ASSERT_EQ(0x87, result);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(ProcessingUnit, ROR_ResultIsZero_SetZeroFlag)
{
	ProcessingUnit testItem;

	auto result = testItem.ROR(0x00);
	ASSERT_EQ(0x00, result);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(ProcessingUnit, ROR_Bit0Is1_SetCarryFlag)
{
	ProcessingUnit testItem;

	auto result = testItem.ROR(0x0F);
	ASSERT_EQ(0x87, result);

	auto carry = testItem.getFlag('C');
	ASSERT_TRUE(carry);
}
