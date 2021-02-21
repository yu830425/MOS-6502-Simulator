#pragma once
using BYTE = unsigned char;
using WORD = unsigned short;
using DWORD = unsigned long;

class CoreProcessingUnit
{
public:
	CoreProcessingUnit();

	bool getFlag(char flagSymbol);
	BYTE getAccumulator();
	BYTE getRegisterX();
	BYTE getRegisterY();

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

private:
	void setRegister(BYTE &cpuRegister, BYTE value);

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
};

