#include "gtest/gtest.h"
#include "../MOS_6502_Emulator/Memory.h"

TEST(MemeoryTest, ReadWriteTest)
{
	Memory testItem(16);

	testItem.write(0x05, std::vector<BYTE>{0x01, 0x02, 0x03});

	auto result = testItem.read(0x06, 2);

	ASSERT_EQ(result[0], 0x02);
	ASSERT_EQ(result[1], 0x03);
}