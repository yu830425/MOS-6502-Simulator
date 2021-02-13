#include "gtest/gtest.h"
#include "../MOS_6502_Emulator/CoreProcessingUnit.h"

using ::testing::Test;

TEST(CoreProcessingUnit, STA_returnAccumulatorValue)
{
	CoreProcessingUnit testItem;
	testItem.LDA(0x50);

	auto accumulator = testItem.STA();
	ASSERT_EQ(0x50, accumulator);
}

TEST(CoreProcessingUnit, STX_returnAccumulatorValue)
{
	CoreProcessingUnit testItem;
	testItem.LDX(0x50);

	auto accumulator = testItem.STX();
	ASSERT_EQ(0x50, accumulator);
}

TEST(CoreProcessingUnit, STY_returnAccumulatorValue)
{
	CoreProcessingUnit testItem;
	testItem.LDY(0x50);

	auto accumulator = testItem.STY();
	ASSERT_EQ(0x50, accumulator);
}