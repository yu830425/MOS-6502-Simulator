#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../MOS_6502_Emulator/ProcessingUnit.h"
#include "MockStack.h"

using ::testing::Return;

TEST(ProcessingUnit, PHA_AccumulatorIs0x40_Push0x40OnStack)
{
	shared_ptr<MockStack> mockStack = make_shared<MockStack>();
	EXPECT_CALL(*mockStack, push(0x40)).Times(1);

	ProcessingUnit testItem;
	testItem.setStackController(mockStack);

	testItem.LDA(0x40);
	testItem.PHA();
}

TEST(ProcessingUnit, PLA_0x40InStack_Pull0x40FromStack)
{
	shared_ptr<MockStack> mockStack = make_shared<MockStack>();
	EXPECT_CALL(*mockStack, pop()).WillOnce(Return(0x40));

	ProcessingUnit testItem;
	testItem.setStackController(mockStack);

	testItem.PLA();
	auto accumulator = testItem.getAccumulator();

	ASSERT_EQ(0x40, accumulator);
}

TEST(ProcessingUnit, PHP_CarryIsOn_Push0x00onStack)
{
	shared_ptr<MockStack> mockStack = make_shared<MockStack>();
	EXPECT_CALL(*mockStack, push(0b00100001)).Times(1);

	ProcessingUnit testItem;
	testItem.setStackController(mockStack);

	testItem.SEC();
	testItem.PHP();
}

TEST(ProcessingUnit, PLP_0x21OnStack_Pop0x21FromStack)
{
	shared_ptr<MockStack> mockStack = make_shared<MockStack>();
	EXPECT_CALL(*mockStack, pop()).WillOnce(Return(0b00100001));

	ProcessingUnit testItem;
	testItem.setStackController(mockStack);

	testItem.PLP();

	auto carry = testItem.getFlag('C');
	ASSERT_TRUE(carry);
}