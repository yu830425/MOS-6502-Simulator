#pragma once

#include "Device.h"
#include <vector>
#include <memory>

struct RangeAddress
{
	WORD from;
	WORD to;
};

using DeviceInformation = std::pair<RangeAddress, std::shared_ptr<Device>>;

class Bus
{
public:
	Bus() = default;

	void addDevice(RangeAddress address, std::shared_ptr<Device> device);
	void write(WORD address, const std::vector<BYTE> &data);
	std::vector<BYTE> read(WORD address, int size);

private:
	DeviceInformation findDevice(WORD address);

	std::vector<DeviceInformation> m_devices;
};
