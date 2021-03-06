#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockStack.h"
#include "../MOS_6502_Emulator/ProcessingUnit.h"

using ::testing::Return;

TEST(ProcessingUnit, TAX_AccumulatorIs0x87_RegisterXShouldBe0x87)
{
	ProcessingUnit testItem;
	testItem.LDA(0x87);

	testItem.TAX();

	auto registerX = testItem.getRegisterX();
	ASSERT_EQ(0x87, registerX);
}

TEST(ProcessingUnit, TAY_AccumulatorIs0x87_RegisterYShouldBe0x87)
{
	ProcessingUnit testItem;
	testItem.LDA(0x87);

	testItem.TAY();

	auto registerY = testItem.getRegisterY();
	ASSERT_EQ(0x87, registerY);
}

TEST(ProcessingUnit, TXA_RegisterXIs0x87_AccumulatorShouldBe0x87)
{
	ProcessingUnit testItem;
	testItem.LDX(0x87);

	testItem.TXA();

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x87, accumulator);
}

TEST(ProcessingUnit, TYA_RegisterYIs0x87_AccumulatorShouldBe0x87)
{
	ProcessingUnit testItem;
	testItem.LDY(0x87);

	testItem.TXY();

	auto accumulator = testItem.getAccumulator();
	ASSERT_EQ(0x87, accumulator);
}

TEST(ProcessingUnit, TSX_StackPointerIs0x87_RegisterXShouldBe0x87)
{
	shared_ptr<MockStack> mockStack = make_shared<MockStack>();
	EXPECT_CALL(*mockStack, getStackPointer()).WillOnce(Return(0x87));

	ProcessingUnit testItem;
	testItem.setStackController(mockStack);

	testItem.TSX();

	auto registerX = testItem.getRegisterX();
	ASSERT_EQ(0x87, registerX);
}

TEST(ProcessingUnit, TXS_RegisterXIs0x87_WillSetStackPointerAs0x87)
{
	shared_ptr<MockStack> mockStack = make_shared<MockStack>();
	EXPECT_CALL(*mockStack, setStackPointer(0x87)).Times(1);

	ProcessingUnit testItem;
	testItem.setStackController(mockStack);
	testItem.LDX(0x87);

	testItem.TXS();
}
