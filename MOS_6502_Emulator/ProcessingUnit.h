#pragma once
#include "BasicType.h"
#include "Stack.h"
#include <memory>

using namespace std;

class ProcessingUnit
{
public:
	ProcessingUnit();

	bool getFlag(char flagSymbol);
	BYTE getAccumulator();
	BYTE getRegisterX();
	BYTE getRegisterY();
	WORD getProgramCounter();
	void setStackController(shared_ptr<Stack> spStackController);

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
	void TYA();
	void TSX();
	void TXS();

	void CMP(BYTE value);
	void CPX(BYTE value);
	void CPY(BYTE value);
	void BIT(BYTE value);

	void BCC(BYTE value);
	void BCS(BYTE value);
	void BNE(BYTE value);
	void BEQ(BYTE value);
	void BPL(BYTE value);
	void BMI(BYTE value);
	void BVC(BYTE value);
	void BVS(BYTE value);

	void JMP(WORD address);
	void JSR(WORD address);
	void RTS();
private:
	void setRegister(BYTE &cpuRegister, BYTE value);
	BYTE composeStatus();
	void setProcessStatus(BYTE processStatus);
	void compare(BYTE cpuRegister, BYTE value);
	void branch(bool pivot, BYTE value);

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

	shared_ptr<Stack> m_spStackController;
};

