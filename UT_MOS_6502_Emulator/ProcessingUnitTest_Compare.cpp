#include "gtest/gtest.h"
#include "../MOS_6502_Emulator/ProcessingUnit.h"

TEST(ProcessingUnit, CMP_ValueGreaterThanAccumulator_NegativeShouldBeTrue)
{
	ProcessingUnit testItem;
	
	testItem.LDA(0x54);
	testItem.CMP(0x55);

	auto negative = testItem.getFlag('N');
	auto zero = testItem.getFlag('Z');
	auto carry = testItem.getFlag('C');

	ASSERT_TRUE(negative);
	ASSERT_FALSE(zero);
	ASSERT_FALSE(carry);
}

TEST(ProcessingUnit, CMP_ValueEqualAccumulator_ZeroAndCarryShouldBeTrue)
{
	ProcessingUnit testItem;

	testItem.LDA(0x55);
	testItem.CMP(0x55);

	auto negative = testItem.getFlag('N');
	auto zero = testItem.getFlag('Z');
	auto carry = testItem.getFlag('C');

	ASSERT_FALSE(negative);
	ASSERT_TRUE(zero);
	ASSERT_TRUE(carry);
}

TEST(ProcessingUnit, CMP_ValueLessThanAccumulator_CarryShouldBeTrue)
{
	ProcessingUnit testItem;

	testItem.LDA(0x55);
	testItem.CMP(0x54);

	auto negative = testItem.getFlag('N');
	auto zero = testItem.getFlag('Z');
	auto carry = testItem.getFlag('C');

	ASSERT_FALSE(negative);
	ASSERT_FALSE(zero);
	ASSERT_TRUE(carry);
}

TEST(ProcessingUnit, CPX_ValueGreaterThanRegisterX_NegativeShouldBeTrue)
{
	ProcessingUnit testItem;

	testItem.LDX(0x54);
	testItem.CPX(0x55);

	auto negative = testItem.getFlag('N');
	auto zero = testItem.getFlag('Z');
	auto carry = testItem.getFlag('C');

	ASSERT_TRUE(negative);
	ASSERT_FALSE(zero);
	ASSERT_FALSE(carry);
}

TEST(ProcessingUnit, CPY_ValueGreaterThanRegisterY_NegativeShouldBeTrue)
{
	ProcessingUnit testItem;

	testItem.LDY(0x54);
	testItem.CPY(0x55);

	auto negative = testItem.getFlag('N');
	auto zero = testItem.getFlag('Z');
	auto carry = testItem.getFlag('C');

	ASSERT_TRUE(negative);
	ASSERT_FALSE(zero);
	ASSERT_FALSE(carry);
}

TEST(ProcessingUnit, BIT_EachBitIsDifferent_ZeroShouldBeTrue)
{
	ProcessingUnit testItem;

	testItem.LDA(0x02);
	testItem.BIT(0x55);

	auto zero = testItem.getFlag('Z');

	ASSERT_TRUE(zero);
}

TEST(ProcessingUnit, BIT_MemoryBit6And7Is1_SetNegativeAndOverflow)
{
	ProcessingUnit testItem;

	testItem.LDA(0x02);
	testItem.BIT(0b11000000);

	auto negative = testItem.getFlag('N');
	auto overflow = testItem.getFlag('V');

	ASSERT_TRUE(negative);
	ASSERT_TRUE(overflow);
}