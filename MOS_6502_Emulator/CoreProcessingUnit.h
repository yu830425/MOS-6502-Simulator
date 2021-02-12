#pragma once
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;

class CoreProcessingUnit
{
public:
	CoreProcessingUnit();

	bool getFlag(char flagSymbol);
	BYTE getAccumulator();
	BYTE getRegisterX();
	BYTE getRegisterY();

private:
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

