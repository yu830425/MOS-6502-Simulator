#include "CommandTable.h"

std::unordered_map<char, Command> createCommandMap()
{
	return unordered_map<char, Command>({
		{0xAD, Command{"LDA", AddressMode::Absolute}},
		{0xBD, Command{"LDA", AddressMode::AbsoluteIndexedX}},
		{0xB9, Command{"LDA", AddressMode::AbsoulteIndexedY}},
		{0xA9, Command{"LDA", AddressMode::Immediate}},
		{0xA5, Command{"LDA", AddressMode::ZeroPage}},
		{0xA1, Command{"LDA", AddressMode::ZeroPageIndexedIndirect}},
		{0xB5, Command{"LDA", AddressMode::ZeroPageIndexedX}},
		{0xB1, Command{"LDA", AddressMode::ZeroPageIndirectIndexedY}},

		{0xAE, Command{"LDX", AddressMode::Absolute}},
		{0xBE, Command{"LDX", AddressMode::AbsoulteIndexedY}},
		{0xA2, Command{"LDX", AddressMode::Immediate}},
		{0xA6, Command{"LDX", AddressMode::ZeroPage}},
		{0xB6, Command{"LDX", AddressMode::ZeroPageIndexedY}},

		{0xAC, Command{"LDY", AddressMode::Absolute}},
		{0xBC, Command{"LDY", AddressMode::AbsoluteIndexedX}},
		{0xA0, Command{"LDY", AddressMode::Immediate}},
		{0xA4, Command{"LDY", AddressMode::ZeroPage}},
		{0xB4, Command{"LDY", AddressMode::ZeroPageIndexedX}},

		{0x8D, Command{"STA", AddressMode::Absolute}},
		{0x9D, Command{"STA", AddressMode::AbsoluteIndexedX}},
		{0x99, Command{"STA", AddressMode::AbsoulteIndexedY}},
		{0x85, Command{"STA", AddressMode::ZeroPage}},
		{0x81, Command{"STA", AddressMode::ZeroPageIndexedIndirect}},
		{0x95, Command{"STA", AddressMode::ZeroPageIndexedX}},
		{0x91, Command{"STA", AddressMode::ZeroPageIndirectIndexedY}},

		{0x8E, Command{"STX", AddressMode::Absolute}},
		{0x86, Command{"STX", AddressMode::ZeroPage}},
		{0x96, Command{"STX", AddressMode::ZeroPageIndexedY}},

		{0x8C, Command{"STY", AddressMode::Absolute}},
		{0x84, Command{"STY", AddressMode::ZeroPage}},
		{0x94, Command{"STY", AddressMode::ZeroPageIndexedX}},

		{0x6D, Command{"ADC", AddressMode::Absolute}},
		{0x7D, Command{"ADC", AddressMode::AbsoluteIndexedX}},
		{0x79, Command{"ADC", AddressMode::AbsoulteIndexedY}},
		{0x69, Command{"ADC", AddressMode::Immediate}},
		{0x65, Command{"ADC", AddressMode::ZeroPage}},
		{0x61, Command{"ADC", AddressMode::ZeroPageIndexedIndirect}},
		{0x75, Command{"ADC", AddressMode::ZeroPageIndexedX}},
		{0x71, Command{"ADC", AddressMode::ZeroPageIndirectIndexedY}},

		{0xED, Command{"SBC", AddressMode::Absolute}},
		{0xFD, Command{"SBC", AddressMode::AbsoluteIndexedX}},
		{0xF9, Command{"SBC", AddressMode::AbsoulteIndexedY}},
		{0xE9, Command{"SBC", AddressMode::Immediate}},
		{0xE5, Command{"SBC", AddressMode::ZeroPage}},
		{0xE1, Command{"SBC", AddressMode::ZeroPageIndexedIndirect}},
		{0xF5, Command{"SBC", AddressMode::ZeroPageIndexedX}},
		{0xF1, Command{"SBC", AddressMode::ZeroPageIndirectIndexedY}},

		{0xEE, Command{"INC", AddressMode::Absolute}},
		{0xFE, Command{"INC", AddressMode::AbsoluteIndexedX}},
		{0xE6, Command{"INC", AddressMode::ZeroPage}},
		{0xF6, Command{"INC", AddressMode::ZeroPageIndexedX}},

		{0xE8, Command{"INX", AddressMode::Implied}},

		{0xC8, Command{"INY", AddressMode::Implied}},

		{0xCE, Command{"DEC", AddressMode::Absolute}},
		{0xDE, Command{"DEC", AddressMode::AbsoluteIndexedX}},
		{0xC6, Command{"DEC", AddressMode::ZeroPage}},
		{0xD6, Command{"DEC", AddressMode::ZeroPageIndexedX}},

		{0xCA, Command{"DEX", AddressMode::Implied}},

		{0x88, Command{"DEY", AddressMode::Implied}},

		{0x0E, Command{"ASL", AddressMode::Absolute}},
		{0x1E, Command{"ASL", AddressMode::AbsoluteIndexedX}},
		{0x0A, Command{"ASL", AddressMode::Accumulator}},
		{0x06, Command{"ASL", AddressMode::ZeroPage}},
		{0x16, Command{"ASL", AddressMode::ZeroPageIndexedX}},

		{0x4E, Command{"LSR", AddressMode::Absolute}},
		{0x5E, Command{"LSR", AddressMode::AbsoluteIndexedX}},
		{0x4A, Command{"LSR", AddressMode::Accumulator}},
		{0x46, Command{"LSR", AddressMode::ZeroPage}},
		{0x56, Command{"LSR", AddressMode::ZeroPageIndexedX}},

		{0x2E, Command{"ROL", AddressMode::Absolute}},
		{0x3E, Command{"ROL", AddressMode::AbsoluteIndexedX}},
		{0x2A, Command{"ROL", AddressMode::Accumulator}},
		{0x26, Command{"ROL", AddressMode::ZeroPage}},
		{0x36, Command{"ROL", AddressMode::ZeroPageIndexedX}},

		{0x6E, Command{"ROR", AddressMode::Absolute}},
		{0x7E, Command{"ROR", AddressMode::AbsoluteIndexedX}},
		{0x6A, Command{"ROR", AddressMode::Accumulator}},
		{0x66, Command{"ROR", AddressMode::ZeroPage}},
		{0x76, Command{"ROR", AddressMode::ZeroPageIndexedX}},

		{0x2D, Command{"AND", AddressMode::Absolute}},
		{0x3D, Command{"AND", AddressMode::AbsoluteIndexedX}},
		{0x39, Command{"AND", AddressMode::AbsoulteIndexedY}},
		{0x29, Command{"AND", AddressMode::Immediate}},
		{0x25, Command{"AND", AddressMode::ZeroPage}},
		{0x21, Command{"AND", AddressMode::ZeroPageIndexedIndirect}},
		{0x35, Command{"AND", AddressMode::ZeroPageIndexedX}},
		{0x31, Command{"AND", AddressMode::ZeroPageIndirectIndexedY}},

		{0x0D, Command{"ORA", AddressMode::Absolute}},
		{0x1D, Command{"ORA", AddressMode::AbsoluteIndexedX}},
		{0x19, Command{"ORA", AddressMode::AbsoulteIndexedY}},
		{0x09, Command{"ORA", AddressMode::Immediate}},
		{0x05, Command{"ORA", AddressMode::ZeroPage}},
		{0x01, Command{"ORA", AddressMode::ZeroPageIndexedIndirect}},
		{0x15, Command{"ORA", AddressMode::ZeroPageIndexedX}},
		{0x11, Command{"ORA", AddressMode::ZeroPageIndirectIndexedY}},

		{0x4D, Command{"EOR", AddressMode::Absolute}},
		{0x5D, Command{"EOR", AddressMode::AbsoluteIndexedX}},
		{0x59, Command{"EOR", AddressMode::AbsoulteIndexedY}},
		{0x49, Command{"EOR", AddressMode::Immediate}},
		{0x45, Command{"EOR", AddressMode::ZeroPage}},
		{0x41, Command{"EOR", AddressMode::ZeroPageIndexedIndirect}},
		{0x55, Command{"EOR", AddressMode::ZeroPageIndexedX}},
		{0x51, Command{"EOR", AddressMode::ZeroPageIndirectIndexedY}},

		{0xCD, Command{"CMP", AddressMode::Absolute}},
		{0xDD, Command{"CMP", AddressMode::AbsoluteIndexedX}},
		{0xD9, Command{"CMP", AddressMode::AbsoulteIndexedY}},
		{0xC9, Command{"CMP", AddressMode::Immediate}},
		{0xC5, Command{"CMP", AddressMode::ZeroPage}},
		{0xC1, Command{"CMP", AddressMode::ZeroPageIndexedIndirect}},
		{0xD5, Command{"CMP", AddressMode::ZeroPageIndexedX}},
		{0xD1, Command{"CMP", AddressMode::ZeroPageIndirectIndexedY}},

		{0xEC, Command{"CPX", AddressMode::Absolute}},
		{0xE0, Command{"CPX", AddressMode::Immediate}},
		{0xE4, Command{"CPX", AddressMode::ZeroPage}},

		{0xCC, Command{"CPY", AddressMode::Absolute}},
		{0xC0, Command{"CPY", AddressMode::Immediate}},
		{0xC4, Command{"CPY", AddressMode::ZeroPage}},

		{0x2C, Command{"BIT", AddressMode::Absolute}},
		{0x89, Command{"BIT", AddressMode::Immediate}},
		{0x24, Command{"BIT", AddressMode::ZeroPage}},

		{0x90, Command{"BCC", AddressMode::Relative}},
		{0xB0, Command{"BCS", AddressMode::Relative}},
		{0xD0, Command{"BNE", AddressMode::Relative}},
		{0xF0, Command{"BEQ", AddressMode::Relative}},
		{0x10, Command{"BPL", AddressMode::Relative}},
		{0x30, Command{"BMI", AddressMode::Relative}},
		{0x50, Command{"BVC", AddressMode::Relative}},
		{0x70, Command{"BVS", AddressMode::Relative}},
		
		{0xAA, Command{"TAX", AddressMode::Implied}},
		{0x8A, Command{"TXA", AddressMode::Implied}},
		{0xA8, Command{"TAY", AddressMode::Implied}},
		{0x98, Command{"TYA", AddressMode::Implied}},
		{0xBA, Command{"TSX", AddressMode::Implied}},
		{0x9A, Command{"TXS", AddressMode::Implied}},

		{0x48, Command{"PHA", AddressMode::Implied}},
		{0x68, Command{"PLA", AddressMode::Implied}},
		{0x08, Command{"PHP", AddressMode::Implied}},
		{0x28, Command{"PLP", AddressMode::Implied}},

		{0x4C, Command{"JMP", AddressMode::Absolute}},
		{0x6C, Command{"JMP", AddressMode::AbsoluteIndirect}},

		{0x20, Command{"JSR", AddressMode::Absolute}},
		{0x60, Command{"RTS", AddressMode::Implied}},
		{0x40, Command{"RTI", AddressMode::Implied}},
		
		{0x18, Command{"CLC", AddressMode::Implied}},
		{0x38, Command{"SEC", AddressMode::Implied}},
		{0xD8, Command{"CLD", AddressMode::Implied}},
		{0xF8, Command{"SED", AddressMode::Implied}},
		{0x58, Command{"CLI", AddressMode::Implied}},
		{0x78, Command{"SEI", AddressMode::Implied}},
		{0xB8, Command{"CLV", AddressMode::Implied}},

		{0x00, Command{"BRK", AddressMode::Implied}},
		{0xEA, Command{"NOP", AddressMode::Implied}}
	});
}
