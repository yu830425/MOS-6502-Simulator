#pragma once
#include "BasicType.h"
#include <memory>
#include "IStack.h"

using namespace std;

class ProcessingUnit
{
public:
	ProcessingUnit();

	bool getFlag(char flagSymbol);
	BYTE getAccumulator();
	BYTE getRegisterX();
	BYTE getRegisterY();
	BYTE getProgramCounter();
	void setStackController(shared_ptr<IStack> spStackController);

	void LDA(BYTE value);
	void LDX(BYTE value);
	void LDY(BYTE value);

	BYTE STA();
	BYTE STX();
	BYTE STY();
	
	void SEC();
	void CLC();
	void SED();
	void CLD();
	void SEI();
	void CLI();
	void CLV();

	void ADC(BYTE value);
	void SBC(BYTE value);

	BYTE INC(BYTE value);
	void INX();
	void INY();

	BYTE DEC(BYTE value);
	void DEX();
	void DEY();

	BYTE ASL(BYTE value);
	BYTE LSR(BYTE value);

	BYTE ROL(BYTE value);
	BYTE ROR(BYTE value);

	void AND(BYTE value);
	void ORA(BYTE value);
	void EOR(BYTE value);
	void PHA();

	void PLA();
	void PHP();
	void PLP();

	void TAX();
	void TAY();
	void TXA();
	void TXY();
	void TSX();
	void TXS();

	void CMP(BYTE value);
	void CPX(BYTE value);
	void CPY(BYTE value);
	void BIT(BYTE value);
private:
	void setRegister(BYTE &cpuRegister, BYTE value);
	BYTE composeStatus();
	void setProcessStatus(BYTE processStatus);
	void compare(BYTE cpuRegister, BYTE value);

	bool m_negative;
	bool m_overflow;
	bool m_break;
	bool m_decimal;
	bool m_interrupt;
	bool m_zero;
	bool m_carry;

	BYTE m_accumulator;
	BYTE m_registerX;
	BYTE m_registerY;
	WORD m_programCounter;

	shared_ptr<IStack> m_spStackController;	
};

