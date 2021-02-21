#include "gtest/gtest.h"
#include "../MOS_6502_Emulator/CoreProcessingUnit.h"

using ::testing::Test;

TEST(CoreProcessingUnit, AND_0xFFAnd0x01_ResultShouldBe0x01)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0xFF);

	testItem.AND(0x01);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x01, accumulator);
}

TEST(CoreProcessingUnit, AND_ResultIsNegative_SetNegativeFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0xFF);

	testItem.AND(0x80);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x80, accumulator);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(CoreProcessingUnit, AND_ResultIsZero_SetZeroFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0xFF);

	testItem.AND(0x00);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x00, accumulator);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(CoreProcessingUnit, ORA_0x0FOr0xF0_ResultShouldBe0xFF)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0x0F);

	testItem.ORA(0xF0);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0xFF, accumulator);
}

TEST(CoreProcessingUnit, ORA_ResultIsNegative_SetNegativeFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0x0F);

	testItem.ORA(0xF0);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0xFF, accumulator);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(CoreProcessingUnit, ORA_ResultIsZero_SetZeroFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0x00);

	testItem.ORA(0x00);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x00, accumulator);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}

TEST(CoreProcessingUnit, EOR_0x85EOR0xFA_ResultShouldBe0x7F)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0x85);

	testItem.EOR(0xFA);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x7F, accumulator);
}

TEST(CoreProcessingUnit, EOR_ResultIsNegative_SetNegativeFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0x05);

	testItem.EOR(0xFA);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0xFF, accumulator);

	auto negative = testItem.getFlag('N');
	ASSERT_TRUE(negative);
}

TEST(CoreProcessingUnit, EOR_ResultIsZero_SetZeroFlag)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0xFF);

	testItem.EOR(0xFF);

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x00, accumulator);

	auto zero = testItem.getFlag('Z');
	ASSERT_TRUE(zero);
}
