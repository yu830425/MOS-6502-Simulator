#pragma once
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../MOS_6502_Emulator/Stack.h"

class MockStack : public Stack
{
public:
	MOCK_METHOD1(push, void(BYTE));
	MOCK_METHOD0(pop, BYTE(void));
	MOCK_METHOD0(getStackPointer, BYTE(void));
	MOCK_METHOD1(setStackPointer, void(BYTE));
};
