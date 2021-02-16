#include "gtest/gtest.h"
#include "../MOS_6502_Emulator/CoreProcessingUnit.h"

using ::testing::Test;

TEST(CoreProcessingUnit, ROL_0xF0RotateLeft1Bit_ReturnShouldBe0xE1)
{
	CoreProcessingUnit testItem;

	auto result = testItem.ROL(0xF0);

	ASSERT_EQ(0xE1, result);
}

TEST(CoreProcessingUnit, ROL_0xF0RotateLeft2Bit_ReturnShouldBe0xC3)
{
	CoreProcessingUnit testItem;

	auto result = testItem.ROL(0xF0);
	result = testItem.ROL(result);

	ASSERT_EQ(0xC3, result);
}

TEST(CoreProcessingUnit, ROL_ResultIsNegative_SetNegativeFlag)
{
	CoreProcessingUnit testItem;

	auto result = testItem.ROL(0xF0);
	ASSERT_EQ(0xE1, result);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(CoreProcessingUnit, ROL_ResultIsZero_SetZeroFlag)
{
	CoreProcessingUnit testItem;

	auto result = testItem.ROL(0x00);
	ASSERT_EQ(0x00, result);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(CoreProcessingUnit, ROL_Bit7Is1_SetCarryFlag)
{
	CoreProcessingUnit testItem;

	auto result = testItem.ROL(0xF0);
	ASSERT_EQ(0xE1, result);

	auto carry = testItem.getFlag('C');
	ASSERT_TRUE(carry);
}

TEST(CoreProcessingUnit, ROR_0x0FRotateRight1Bit_ReturnShouldBe0x87)
{
	CoreProcessingUnit testItem;

	auto result = testItem.ROR(0x0F);

	ASSERT_EQ(0x87, result);
}

TEST(CoreProcessingUnit, ROR_ResultIsNegative_SetNegativeFlag)
{
	CoreProcessingUnit testItem;

	auto result = testItem.ROR(0x0F);
	ASSERT_EQ(0x87, result);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(CoreProcessingUnit, ROR_ResultIsZero_SetZeroFlag)
{
	CoreProcessingUnit testItem;

	auto result = testItem.ROR(0x00);
	ASSERT_EQ(0x00, result);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(CoreProcessingUnit, ROR_Bit0Is1_SetCarryFlag)
{
	CoreProcessingUnit testItem;

	auto result = testItem.ROR(0x0F);
	ASSERT_EQ(0x87, result);

	auto carry = testItem.getFlag('C');
	ASSERT_TRUE(carry);
}
