//
//      Implementation of the Assembler class.
//
#include "stdafx.h"
#include "Assembler.h"
#include "Errors.h"

// Constructor for the assembler.  Note: we are passing argc and argv to the file access constructor.
Assembler::Assembler(int argc, char *argv[])
	: m_facc(argc, argv)
{
	// Nothing else to do here.
}
// Destructor currently does nothing.  You might need to add something.
Assembler::~Assembler()
{
}
// Pass I establishes the location of the labels.  You will do a better function comments.
void Assembler::PassI()
{
	// Tracks the location of the instructions to be generated.
	int loc = 0;

	// Successively process each line of source code.
	for (; ; ) {

		// Read the next line from the source file.
		string buff;
		if (!m_facc.GetNextLine(buff)) {

			// If there are no more lines, we are missing an end statement.
			// We will let this error be reported by Pass II.
			return;
		}
		// Parse the line and get the instruction type.
		Instruction::InstructionType st = m_inst.ParseInstruction(buff);

		// If this is an end statement, there is nothing left to do in pass I.
		// Pass II will determine if the end is the last statement.
		if (st == Instruction::ST_End) return;

		// Labels can only be on machine language and assembler language
		// instructions.
		if (st != Instruction::ST_MachineLanguage && st != Instruction::ST_AssemblerInstr) continue;

		// If the instruction has a label, record it and its location in the
		// symbol table.
		if (m_inst.isLabel()) {
			m_symtab.AddSymbol(m_inst.GetLabel(), loc);
		}
		// Compute the location of the next instruction.
		loc = m_inst.LocationNextInstruction(loc);
	}
} /* void Assembler::PassI(); */

void Assembler::PassII()
{
	cout << "Label\tOpCode\tOperand\tErrors" << endl;

	// Reads from the start of the file
	m_facc.rewind();

	// Finishes the program
	bool end = false;

	// Tracks the location of the instructions to be generated.
	int loc = 0;

	// Successively process each line of source code.
	while (true) {

		// Reset the error report
		Errors::InitErrorReporting();

		// Read the next line from the source file.
		string buff;
		if (!m_facc.GetNextLine(buff)) {
			if (!end) {
				// If there are no more lines and have not seen an end statement, we have an error.
				string error = "Missing end statement";
				Errors::RecordError(error);
			}
			return;
		}

		// Parse the line and get the instruction type.
		Instruction::InstructionType st = m_inst.ParseInstruction(buff);

		if (st == Instruction::ST_End) {
			// If this is an end statement, check if there is anything else in the file.
			end = true;
		}

		// Ignore comments
		if (st == Instruction::ST_Comment) {
			continue;
		}

		// Holds the machine code equivalent of the operation code
		int operation = -1;
		// Holds the machine code equivalent of the operand
		int address = -1;

		// Check there are no more than 3 pieces of instruction
		if (m_inst.GetLabel() == "???" && m_inst.GetOpCode() == "???" && m_inst.GetOperand() == "???") {
			// Instruction is to long
			string error = "Instruction is to long";
			Errors::RecordError(error);
		}

		// Check label for errors
		CheckLabel();

		// Check op code for errors
		operation = CheckOpCode();

		// Check operand for errors
		address = CheckOperand();

		// Holds the full machine code instruction
		int context = -1;

		if (operation != -1 && address != -1) {
			// If all the pieces of the machine code exist, create the machine code instruction
			context = operation * 10000 + address;
		}

		// Display the location
		cout << loc << '\t';

		// Display the translation
		if (context >= 0) {
			// If the full machine code instruction was created, add it to memory
			m_emul.insertMemory(loc, context);

			cout << setfill('0') << setw(6) << context;
		}
		else {
			cout << '\t';
		}

		// Display the instruction
		cout << '\t' << m_inst.GetLabel() << '\t' << m_inst.GetOpCode() << '\t' << m_inst.GetOperand() << '\t';

		// Display the errors
		Errors::DisplayErrors();

		cout << endl;

		// Compute the location of the next instruction.
		loc = m_inst.LocationNextInstruction(loc);
	}
} /* void Assembler::PassII(); */

void Assembler::RunEmulator() {
	// Run the program
	m_emul.runProgram();
} /* void Assembler::RunEmulator(); */

void Assembler::CheckLabel() {
	if (m_inst.GetLabel() == "???") {
		// If the label is unknown, report error.
		string error = "Unknown label";
		Errors::RecordError(error);
	}
} /* void Assembler::CheckLabel(); */

int Assembler::CheckOpCode() {
	// Holds the machine code equivalent to the op code
	int opCode = -1;

	if (m_inst.GetOpCode() == "???") {
		// If the isntruction is unknown, report error.
		string error = "Unknown op code";
		Errors::RecordError(error);
	}
	else {
		if (m_inst.GetNumOpCode() >= -1) {
			// If the numeric op code is valid, set the op code.
			opCode = m_inst.GetNumOpCode();
		}
	}

	return opCode;
} /* void Assembler::CheckOpCode(); */

int Assembler::CheckOperand() {
	// Holds the machine code equivalent to the operand
	int operand = -1;

	if (m_inst.GetOperand().empty()) {
		if (m_inst.GetOpCode() == "halt") {
			// If op code is halt, there is no operand
			operand = 0;
		}
	}
	else if (m_inst.GetOperand() == "???") {
		// If operand is unknown, report error.
		string error = "Unknown operand";
		Errors::RecordError(error);
	}
	else if (!m_inst.IsNumericOperand()) {
		// Holds the value of a symbol
		int symLoc = -1;

		if (m_symtab.LookupSymbol(m_inst.GetOperand(), symLoc)) {
			// If the symbol was found, use the value for the address
			operand = symLoc;
		}
		else {
			// Otherwise, report error
			string error = "Operand not in symbol table";
			Errors::RecordError(error);
		}
	}
	else {
		if (m_inst.GetOperandValue() >= 0 || m_inst.GetOperandValue() < 10000) {
			// If the memory location is valid, use the operand value
			operand = m_inst.GetOperandValue();
		}
		else {
			// Otherwise, report error
			string error = "Operand is not a valid memory location";
			Errors::RecordError(error);
		}
	}

	return operand;
} /* void Assembler::CheckOperand(); */