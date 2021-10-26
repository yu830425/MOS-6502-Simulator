#include "gtest/gtest.h"
#include "../MOS_6502_Emulator/ProcessingUnit.h"

TEST(ProcessingUnit, ADC_1Add1WithoutCarry_Equal2)
{
	ProcessingUnit testItem;
	testItem.LDA(0x01);

	testItem.ADC(0x01);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x02, accumulator);
}

TEST(ProcessingUnit, ADC_255Add1_ShouldSetCarryFlag)
{
	ProcessingUnit testItem;
	testItem.LDA(0x01);	//1

	testItem.ADC(0xFF);	//-1(255)

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0, accumulator);

	auto carry = testItem.getFlag('C');
	ASSERT_TRUE(carry);
}

TEST(ProcessingUnit, ADC_1Add1WithCarry_Eqaul3)
{
	ProcessingUnit testItem;
	testItem.SEC();
	testItem.LDA(0x01);	//reset accumulator

	testItem.ADC(0x01);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x03, accumulator);
}

TEST(ProcessingUnit, ADC_ResultIsLessThanZero_SetNegativeFlag)
{
	ProcessingUnit testItem;
	testItem.LDA(0xFF);	//-1
	testItem.LDX(0x00); //set negative flag to zero.

	testItem.ADC(0xFF);	//-1

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0xFE, accumulator);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(ProcessingUnit, ADC_ResultIsZero_SetZeroFlag)
{
	ProcessingUnit testItem;
	testItem.LDA(0x01);	//1
	testItem.ADC(0xFF);	//-1

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x00, accumulator);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(ProcessingUnit, ADC_NegativeAddNegativeEqualPositive_SetOverflowFlag)
{
	ProcessingUnit testItem;
	testItem.LDA(0x80);
	testItem.ADC(0x80);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x00, accumulator);

	auto overflow = testItem.getFlag('V');
	ASSERT_TRUE(overflow);
}

TEST(ProcessingUnit, SBC_2Minus1WithoutCarry_Equal0)
{
	ProcessingUnit testItem;
	testItem.LDA(0x02);

	testItem.SBC(0x01);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x00, accumulator);
}

TEST(ProcessingUnit, SBC_2Minus1WithCarry_Equal1)
{
	ProcessingUnit testItem;
	testItem.LDA(0x02);
	testItem.SEC();

	testItem.SBC(0x01);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x01, accumulator);
}

TEST(ProcessingUnit, SBC_ResultIsZero_SetZeroFlag)
{
	ProcessingUnit testItem;
	testItem.LDA(0x02);

	testItem.SBC(0x01);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x00, accumulator);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(ProcessingUnit, SBC_ResultIsNegative_SetNegativeFlag)
{
	ProcessingUnit testItem;
	testItem.LDA(0x02);

	testItem.SBC(0x02);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0xFF, accumulator);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(ProcessingUnit, SBC_1Minus255_SetCarryFlag)
{
	ProcessingUnit testItem;
	testItem.LDA(0x01);
	testItem.SBC(0xFF);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x01, accumulator);

	auto carry = testItem.getFlag('C');
	ASSERT_TRUE(carry);
}

TEST(ProcessingUnit, SBC_PositiveMinusNegativeEqualNegative_SetOverflowFlag)
{
	ProcessingUnit testItem;
	testItem.LDA(0x7F);	//127
	testItem.SEC();

	testItem.SBC(0xFF);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x80, accumulator);

	auto overflow = testItem.getFlag('V');
	ASSERT_TRUE(overflow);
}
