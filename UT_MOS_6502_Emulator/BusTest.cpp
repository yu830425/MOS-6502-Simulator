#include "gtest/gtest.h"
#include "MockDevice.h"
#include "../MOS_6502_Emulator/Bus.h"

using ::testing::_;
using ::testing::Return;

TEST(BusTest, Write_UseAddress0x4000_WriteAtDevice2)
{
	std::vector<BYTE> data{ 33,44,55 };

	auto device1 = std::make_shared<MockDevice>();
	auto device2 = std::make_shared<MockDevice>();

	EXPECT_CALL(*device1, write(_, _)).Times(0);
	EXPECT_CALL(*device2, write(0x1000, data)).Times(1);

	Bus bus;

	bus.addDevice({0x0000, 0x2FFF}, device1);
	bus.addDevice({0x3000, 0xFFFF}, device2);

	bus.write(0x4000, data);
}

TEST(BusTest, Read_UseAddress0x4000_ReadAtDevice2)
{
	std::vector<BYTE> data{ 33,44,55 };

	auto device1 = std::make_shared<MockDevice>();
	auto device2 = std::make_shared<MockDevice>();

	EXPECT_CALL(*device1, read(_, _)).Times(0);
	EXPECT_CALL(*device2, read(0x1000, 3)).WillOnce(Return(data));

	Bus bus;

	bus.addDevice({ 0x0000, 0x2FFF }, device1);
	bus.addDevice({ 0x3000, 0xFFFF }, device2);

	auto result = bus.read(0x4000, 3);

	ASSERT_EQ(result, data);
}
