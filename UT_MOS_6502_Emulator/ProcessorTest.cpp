#include "gtest/gtest.h"
#include "MockDevice.h"
#include "../MOS_6502_Emulator/Bus.h"
#include "MockProcessingUnit.h"
#include "../MOS_6502_Emulator/Processor.h"

using ::testing::_;

TEST(ProcessorTest, setProgramCounter)
{
	auto mockProcessingUnit = std::make_shared<MockProcessingUnit>();

	EXPECT_CALL(*mockProcessingUnit, setProgramCounter(0x0020)).Times(1);

	Processor processor;

	processor.setProcessingUnit(mockProcessingUnit);
	processor.setProgramCounter(0x0020);
}