#pragma once
#include <gmock/gmock.h>
#include "../MOS_6502_Emulator/ProcessingUnit.h"

class MockProcessingUnit : public ProcessingUnit
{
public:
	MOCK_METHOD(void, setProgramCounter, (WORD));
};
