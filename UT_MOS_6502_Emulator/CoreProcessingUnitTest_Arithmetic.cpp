#include "gtest/gtest.h"
#include "../MOS_6502_Emulator/CoreProcessingUnit.h"

TEST(CoreProcessingUnit, ADC_1Add1WithoutCarry_Equal2)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0x01);

	testItem.ADC(0x01);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x02, accumulator);
}

TEST(CoreProcessingUnit, ADC_255Add1_ShouldSetCarryFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0x01);	//1

	testItem.ADC(0xFF);	//-1(255)

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0, accumulator);

	auto carry = testItem.getFlag('C');
	ASSERT_TRUE(carry);
}

TEST(CoreProcessingUnit, ADC_1Add1WithCarry_Eqaul3)
{
	CoreProcessingUnit testItem;
	testItem.SEC();
	testItem.LDA(0x01);	//reset accumulator

	testItem.ADC(0x01);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x03, accumulator);
}

TEST(CoreProcessingUnit, ADC_ResultIsLessThanZero_SetNegativeFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0xFF);	//-1
	testItem.LDX(0x00); //set negative flag to zero.

	testItem.ADC(0xFF);	//-1

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0xFE, accumulator);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(CoreProcessingUnit, ADC_ResultIsZero_SetZeroFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0x01);	//1
	testItem.ADC(0xFF);	//-1

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x00, accumulator);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(CoreProcessingUnit, ADC_NegativeAddNegativeEqualPositive_SetOverflowFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0x80);
	testItem.ADC(0x80);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x00, accumulator);

	auto overflow = testItem.getFlag('V');
	ASSERT_TRUE(overflow);
}

TEST(CoreProcessingUnit, SBC_2Minus1WithoutCarry_Equal0)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0x02);

	testItem.SBC(0x01);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x00, accumulator);
}

TEST(CoreProcessingUnit, SBC_2Minus1WithCarry_Equal1)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0x02);
	testItem.SEC();

	testItem.SBC(0x01);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x01, accumulator);
}

TEST(CoreProcessingUnit, SBC_ResultIsZero_SetZeroFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0x02);

	testItem.SBC(0x01);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x00, accumulator);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(CoreProcessingUnit, SBC_ResultIsNegative_SetNegativeFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0x02);

	testItem.SBC(0x02);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0xFF, accumulator);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(CoreProcessingUnit, SBC_1Minus255_SetCarryFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0x01);
	testItem.SBC(0xFF);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x01, accumulator);

	auto carry = testItem.getFlag('C');
	ASSERT_TRUE(carry);
}

TEST(CoreProcessingUnit, SBC_PositiveMinusNegativeEqualNegative_SetOverflowFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0x7F);	//127
	testItem.SEC();

	testItem.SBC(0xFF);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x80, accumulator);

	auto overflow = testItem.getFlag('V');
	ASSERT_TRUE(overflow);
}
