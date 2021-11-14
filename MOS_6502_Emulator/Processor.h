#pragma once
#include <memory>
#include <any>
#include <functional>
#include "ProcessingUnit.h"
#include "Bus.h"
#include "CommandTable.h"

using namespace std;

class Processor
{
public:
	Processor();

	void setProcessingUnit(std::shared_ptr<ProcessingUnit> processingUnit);
	void setBus(std::shared_ptr<Bus> bus);

	void setProgramCounter(WORD address);

	void run();
private:
	shared_ptr<ProcessingUnit> m_processingUnit;
	shared_ptr<Bus> m_bus;
	unordered_map<char, Command> m_commandTable;
	unordered_map<string, any> m_commandMap;
	unordered_map<string, bool> m_writeBackMap;
};
