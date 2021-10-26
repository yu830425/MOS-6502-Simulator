#pragma once
#include <gmock/gmock.h>
#include "../MOS_6502_Emulator/Device.h"

class MockDevice : public Device
{
public:
	MOCK_METHOD(void, write, (WORD, const std::vector<BYTE>&), (override));
	MOCK_METHOD(std::vector<BYTE>, read, (WORD, int), (override));
};
