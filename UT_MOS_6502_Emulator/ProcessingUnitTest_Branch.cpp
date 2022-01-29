#include "gtest/gtest.h"
#include "../MOS_6502_Emulator/ProcessingUnit.h"

TEST(ProcessingUnit, BCC_CarryIsFalse_JumpForward)
{
	ProcessingUnit testItem;
	testItem.CLC();

	ASSERT_EQ(0x0000, testItem.getProgramCounter());

	testItem.BCC(0x05);

	// 5 + 2 (branch command length)
	ASSERT_EQ(0x0007, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BCC_CarryIsFalse_JumpBackward)
{
	ProcessingUnit testItem;
	testItem.CLC();

	testItem.setProgramCounter(0x0006);

	ASSERT_EQ(0x0006, testItem.getProgramCounter());

	testItem.BCC(0xFC); //-4

	// 6 - 4 + 2 
	ASSERT_EQ(0x004, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BCC_CarryIsTrue_IncreaseProgramCounter)
{
	ProcessingUnit testItem;
	testItem.SEC();
	
	ASSERT_EQ(0x0000, testItem.getProgramCounter());

	testItem.BCC(0xFF);

	ASSERT_EQ(0x0002, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BCS_CarryIsTrue_JumpForward)
{
	ProcessingUnit testItem;
	testItem.SEC();

	ASSERT_EQ(0x0000, testItem.getProgramCounter());

	testItem.BCS(0x05);

	// 5 + 2
	ASSERT_EQ(0x0007, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BCS_CarryIsTrue_JumpBackward)
{
	ProcessingUnit testItem;
	testItem.SEC();
	testItem.SEC();

	testItem.setProgramCounter(0x0002);

	ASSERT_EQ(0x0002, testItem.getProgramCounter());

	testItem.BCS(0xFF); //-1

	// 2 - 1 + 2
	ASSERT_EQ(0x0003, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BCS_CarryIsFalse_IncreaseProgramCounter)
{
	ProcessingUnit testItem;
	testItem.CLC();

	ASSERT_EQ(0x0000, testItem.getProgramCounter());

	testItem.BCS(0xFF);

	ASSERT_EQ(0x0002, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BNE_ZeroIsFalse_JumpForward)
{
	ProcessingUnit testItem;
	testItem.LDA(0x01);

	ASSERT_EQ(0x0000, testItem.getProgramCounter());

	testItem.BNE(0x05);

	// 5 + 2
	ASSERT_EQ(0x0007, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BNE_ZeroIsFalse_JumpBackward)
{
	ProcessingUnit testItem;
	testItem.LDA(0x01);
	testItem.LDA(0x01);

	testItem.setProgramCounter(0x0002);

	ASSERT_EQ(0x0002, testItem.getProgramCounter());

	testItem.BNE(0xFF); //-1

	// 2 - 1 + 2
	ASSERT_EQ(0x0003, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BNE_ZeroIsTrue_IncreaseProgramCounter)
{
	ProcessingUnit testItem;
	testItem.LDA(0x00);

	ASSERT_EQ(0x0000, testItem.getProgramCounter());

	testItem.BNE(0xFF);

	ASSERT_EQ(0x0002, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BEQ_ZeroIsTrue_JumpForward)
{
	ProcessingUnit testItem;
	testItem.LDA(0x00);

	ASSERT_EQ(0x0000, testItem.getProgramCounter());

	testItem.BEQ(0x05);

	// 5 + 2
	ASSERT_EQ(0x0007, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BEQ_ZeroIsTrue_JumpBackward)
{
	ProcessingUnit testItem;
	testItem.LDA(0x00);
	testItem.LDA(0x00);

	testItem.setProgramCounter(0x0002);

	ASSERT_EQ(0x0002, testItem.getProgramCounter());

	testItem.BEQ(0xFF); //-1

	// 2 - 1 + 2
	ASSERT_EQ(0x0003, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BEQ_ZeroIsFalse_IncreaseProgramCounter)
{
	ProcessingUnit testItem;
	testItem.LDA(0x01);

	ASSERT_EQ(0x0000, testItem.getProgramCounter());

	testItem.BEQ(0xFF);

	ASSERT_EQ(0x0002, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BPL_NegativeIsFalse_JumpForward)
{
	ProcessingUnit testItem;
	testItem.LDA(0x00);

	ASSERT_EQ(0x0000, testItem.getProgramCounter());

	testItem.BPL(0x05);

	// 5 + 2
	ASSERT_EQ(0x0007, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BPL_NegativeIsFalse_JumpBackward)
{
	ProcessingUnit testItem;
	testItem.LDA(0x00);
	testItem.LDA(0x00);

	testItem.setProgramCounter(0x0002);

	ASSERT_EQ(0x0002, testItem.getProgramCounter());

	testItem.BPL(0xFF); //-1

	// 2 - 1 + 2
	ASSERT_EQ(0x0003, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BPL_NegativeIsTrue_IncreaseProgramCounter)
{
	ProcessingUnit testItem;
	testItem.LDA(0xFF);

	ASSERT_EQ(0x0000, testItem.getProgramCounter());

	testItem.BPL(0xFF);

	ASSERT_EQ(0x0002, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BMI_NegativeIsTrue_JumpForward)
{
	ProcessingUnit testItem;
	testItem.LDA(0xFF);

	ASSERT_EQ(0x0000, testItem.getProgramCounter());

	testItem.BMI(0x05);

	// 5 + 2
	ASSERT_EQ(0x0007, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BMI_NegativeIsTrue_JumpBackward)
{
	ProcessingUnit testItem;
	testItem.LDA(0xFF);
	testItem.LDA(0xFF);

	testItem.setProgramCounter(0x0002);

	ASSERT_EQ(0x0002, testItem.getProgramCounter());

	testItem.BMI(0xFF); //-1

	// 2 - 1 + 2
	ASSERT_EQ(0x0003, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BMI_NegativeIsFalse_IncreaseProgramCounter)
{
	ProcessingUnit testItem;
	testItem.LDA(0x00);

	ASSERT_EQ(0x0000, testItem.getProgramCounter());

	testItem.BMI(0xFF);

	ASSERT_EQ(0x0002, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BVC_OverflowIsFalse_JumpForward)
{
	ProcessingUnit testItem;
	testItem.CLV();

	ASSERT_EQ(0x0000, testItem.getProgramCounter());

	testItem.BVC(0x05);

	// 5 + 2
	ASSERT_EQ(0x0007, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BVC_OverflowIsFalse_JumpBackward)
{
	ProcessingUnit testItem;
	testItem.CLV();
	testItem.CLV();

	testItem.setProgramCounter(0x0002);

	ASSERT_EQ(0x0002, testItem.getProgramCounter());

	testItem.BVC(0xFF); //-1

	// 2 - 1 + 2
	ASSERT_EQ(0x0003, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BVC_OverflowIsTrue_IncreaseProgramCounter)
{
	ProcessingUnit testItem;
	testItem.LDA(0x80);
	testItem.ADC(0x80);

	ASSERT_EQ(0x0000, testItem.getProgramCounter());

	testItem.BVC(0xFF);

	ASSERT_EQ(0x0002, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BVS_OverflowIsTrue_JumpForward)
{
	ProcessingUnit testItem;
	testItem.LDA(0x80);
	testItem.ADC(0x80);

	ASSERT_EQ(0x0000, testItem.getProgramCounter());

	testItem.BVS(0x05);

	// 5 + 2
	ASSERT_EQ(0x0007, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BVS_OverflowIsTrue_JumpBackward)
{
	ProcessingUnit testItem;
	testItem.LDA(0x80);
	testItem.ADC(0x80);

	testItem.setProgramCounter(0x0002);

	ASSERT_EQ(0x0002, testItem.getProgramCounter());

	testItem.BVS(0xFF); //-1

	// 2 - 1 + 2
	ASSERT_EQ(0x0003, testItem.getProgramCounter());
}

TEST(ProcessingUnit, BVS_OverflowIsFalse_IncreaseProgramCounter)
{
	ProcessingUnit testItem;
	testItem.CLV();

	ASSERT_EQ(0x0000, testItem.getProgramCounter());

	testItem.BVS(0xFF);

	ASSERT_EQ(0x0002, testItem.getProgramCounter());
}