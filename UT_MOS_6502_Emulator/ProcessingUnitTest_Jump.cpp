#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../MOS_6502_Emulator/ProcessingUnit.h"
#include "MockStack.h"

using ::testing::Return;

TEST(ProcessingUnit, JSR_GivePosition0x1234_StorePCAndJump)
{
	shared_ptr<MockStack> mockStack = make_shared<MockStack>();
	EXPECT_CALL(*mockStack, push(0x45)).Times(1);
	EXPECT_CALL(*mockStack, push(0x67)).Times(1);

	ProcessingUnit testItem;
	testItem.setStackController(mockStack);
	testItem.JMP(0x4567);

	testItem.JSR(0x1234);

	auto programCounter = testItem.getProgramCounter();
	ASSERT_EQ(0x1234, programCounter);
}

TEST(ProcessingUnit, RTS_JSRFrom0x4567_ShouldReturnTo0x4567)
{
	shared_ptr<MockStack> mockStack = make_shared<MockStack>();
	EXPECT_CALL(*mockStack, push(0x45)).Times(1);
	EXPECT_CALL(*mockStack, push(0x67)).Times(1);
	EXPECT_CALL(*mockStack, pop()).WillOnce(Return(0x67))
								  .WillOnce(Return(0x45));

	ProcessingUnit testItem;
	testItem.setStackController(mockStack);
	testItem.JMP(0x4567);
	testItem.JSR(0x1234);

	testItem.RTS();

	auto programCounter = testItem.getProgramCounter();
	ASSERT_EQ(0x4567, programCounter);
}
