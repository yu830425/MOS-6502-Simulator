#include "Bus.h"

void Bus::addDevice(RangeAddress address, std::shared_ptr<Device> device)
{
	m_devices.emplace_back(address, device);
}

void Bus::write(WORD address, const std::vector<BYTE>& data)
{
	auto deviceInfomation = findDevice(address);
	auto targetAddress = address - deviceInfomation.first.from;

	deviceInfomation.second->write(targetAddress, data);
}

std::vector<BYTE> Bus::read(WORD address, int size)
{
	auto deviceInfomation = findDevice(address);
	auto targetAddress = address - deviceInfomation.first.from;

	return deviceInfomation.second->read(targetAddress, size);
}

DeviceInformation Bus::findDevice(WORD address)
{
	for (auto device : m_devices)
	{
		if (device.first.from <= address && address <= device.first.to)
		{
			return device;
		}
	}

	return {};
}
