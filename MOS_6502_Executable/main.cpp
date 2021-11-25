#include "../MOS_6502_Emulator/BinaryLoader.h"
#include "../MOS_6502_Emulator/Bus.h"
#include "../MOS_6502_Emulator/Memory.h"
#include "../MOS_6502_Emulator/Console.h"
#include "../MOS_6502_Emulator/Processor.h"

int main()
{
	BinaryLoader loader("practice");

	auto spAddress = loader.getSpAddress();
	auto loadAddress = loader.getLoadAddress();
	auto resetAddress = loader.getResetAddress();
	auto program = loader.getProgram();

	std::shared_ptr<Device> memory = std::make_shared<Memory>(0xFFFE);
	std::shared_ptr<Device> console = std::make_shared<Console>();

	std::shared_ptr<Bus> bus = std::make_shared<Bus>();
	bus->addDevice({ 0x0000, 0xFFFE }, memory);
	bus->addDevice({ 0xFFFF, 0xFFFF }, console);

	bus->write(loadAddress, program);

	Processor processor;
	processor.setBus(bus);
	processor.setProgramCounter(resetAddress);
	processor.run();

	return 0;
}