//
//		Assembler class.  This is a container for all the components
//		that make up the assembler.
//
#pragma once 

#include "SymTab.h"
#include "Instruction.h"
#include "FileAccess.h"
#include "Emulator.h"


class Assembler {

public:
	Assembler(int argc, char *argv[]);
	~Assembler();

	/**/
	/*
	Assembler::PassI() Assembler::PassI()

	NAME

	Assembler::PassI - establish the locations of the symbols

	SYNOPSIS

	void Assembler::PassI();

	DESCRIPTION

	This function passes through the given file and stores every label into
	the symbol table. 

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	3:09am 12/24/2015

	*/
	/**/
	void PassI();

	/**/
	/*
	Assembler::PassII() Assembler::PassII()

	NAME

	Assembler::PassII - generate a translation

	SYNOPSIS

	void Assembler::PassII();

	DESCRIPTION

	This function translates instructions form the given file
	to machine code. It then stores the code into the appropriate
	memory location within the emulator.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	3:14am 12/24/2015

	*/
	/**/
	void PassII();

	/**/
	/*
	Assembler::DisplaySymbolTable() Assembler::DisplaySymbolTable()

	NAME

	Assembler::DisplaySymbolTable - Display the symbols in the symbol table.

	SYNOPSIS

	void Assembler::DisplaySymbolTable();

	DESCRIPTION

	This function displays every symbol in the symbol table.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	3:16am 12/24/2015

	*/
	/**/
	void DisplaySymbolTable() { m_symtab.DisplaySymbolTable(); }

	/**/
	/*
	Assembler::RunEmulator() Assembler::RunEmulator()

	NAME

	Assembler::RunEmulator - Run emulator on the translation.

	SYNOPSIS

	void Assembler::RunEmulator();

	DESCRIPTION

	This function runs the machine code instructions that were
	translated from the given file.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	3:21am 12/24/2015

	*/
	/**/
	void RunEmulator();

private:
	FileAccess m_facc;	    // File Access object
	SymbolTable m_symtab;	// Symbol table object
	Instruction m_inst;	    // Instruction object
	emulator m_emul;        // Emulator for VC3600

	/**/
	/*
	Assembler::CheckLabel() Assembler::CheckLabel()

	NAME

	Assembler::CheckLabel - Checks for label errors.

	SYNOPSIS

	void Assembler::CheckLabel();

	DESCRIPTION

	This function uses the semi-translated label instruction
	and attempts to convert it to machine code.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	3:25am 12/24/2015

	*/
	/**/
	void CheckLabel();

	/**/
	/*
	Assembler::CheckOpCode() Assembler::CheckOpCode()

	NAME

	Assembler::CheckOpCode - Checks for op code errors.

	SYNOPSIS

	void Assembler::CheckOpCode();

	DESCRIPTION

	This function uses the semi-translated op code instruction
	and attempts to convert it to machine code.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	3:25am 12/24/2015

	*/
	/**/
	int CheckOpCode();

	/**/
	/*
	Assembler::CheckOperand() Assembler::CheckOperand()

	NAME

	Assembler::CheckOperand - Checks for operand errors.

	SYNOPSIS

	void Assembler::CheckOperand();

	DESCRIPTION

	This function uses the semi-translated operand instruction
	and attempts to convert it to machine code.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	3:27am 12/24/2015

	*/
	/**/
	int CheckOperand();
};
