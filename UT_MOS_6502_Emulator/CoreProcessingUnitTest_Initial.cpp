#include "gtest/gtest.h"
#include "../MOS_6502_Emulator/CoreProcessingUnit.h"

using ::testing::Test;

TEST(CoreProessingUnit, InitialFlags)
{
	CoreProcessingUnit testItem;

	auto negative = testItem.getFlag('N');
	auto overflow = testItem.getFlag('V');
	auto breakFlag = testItem.getFlag('B');
	auto decimal = testItem.getFlag('D');
	auto interrupt = testItem.getFlag('I');
	auto zero = testItem.getFlag('Z');
	auto carry = testItem.getFlag('C');

	ASSERT_FALSE(negative);
	ASSERT_FALSE(overflow);
	ASSERT_FALSE(breakFlag);
	ASSERT_FALSE(decimal);
	ASSERT_FALSE(interrupt);
	ASSERT_FALSE(zero);
	ASSERT_FALSE(carry);
}

TEST(CoreProessingUnit, InitialRegister)
{
	CoreProcessingUnit testItem;

	auto accumulator = testItem.getAccumulator();
	auto registerX = testItem.getRegisterX();
	auto registerY = testItem.getRegisterY();

	ASSERT_EQ(0, accumulator);
	ASSERT_EQ(0, registerX);
	ASSERT_EQ(0, registerY);
}
