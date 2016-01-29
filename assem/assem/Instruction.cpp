#include "stdafx.h"
#include "Instruction.h"

Instruction::InstructionType Instruction::ParseInstruction(string & a_buff)
{
	// Save the original instruction
	m_instruction = a_buff;

	// Remove the comment from the instruction
	RemoveComment(a_buff);

	// Holds the first pieces of the instruction
	string firstInstr;

	// Holds the second pieces of the instruction
	string secondInstr;

	// Holds the third pieces of the instruction
	string thirdInstr;

	// Holds the fourth pieces of the instruction
	string extra;

	// Split the instruction into pieces
	SplitInstruction(a_buff, firstInstr, secondInstr, thirdInstr, extra);

	// Arrange the pieces to fit appropriately
	ArrangeInstruction(firstInstr, secondInstr, thirdInstr, extra);

	// Save the label
	m_Label = firstInstr;

	// Save the op code
	m_OpCode = secondInstr;

	// Save the operand
	m_Operand = thirdInstr;
	
	// Save the parsed op code
	m_NumOpCode = ParseOpCode(m_OpCode);

	// Save the parsed operand
	m_IsNumericOperand = ParseOperand(m_Operand);

	return m_type;
} /* Instruction::InstructionType Instruction::ParseInstruction(string & a_buff); */

int Instruction::LocationNextInstruction(int a_loc)
{
	if (m_type == ST_Comment) {
		// If the instruction is a comment, do nothing
		return a_loc;
	}
	else if (m_OpCode == "org") {
		if (m_IsNumericOperand) {
			// If the op code is "org", set the location to the operand
			a_loc = m_OperandValue;
		}
	}
	else if (m_OpCode == "ds") {
		if (m_IsNumericOperand) {
			// If the op code is "ds", add the operand to the location
			a_loc += m_OperandValue;
		}
	}
	else {
		// Increment the location
		a_loc++;
	}
	return a_loc;
} /* int Instruction::LocationNextInstruction(int a_loc); */

void Instruction::RemoveComment(string &a_buff) {
	// Remove everything after and including ';'
	a_buff = a_buff.substr(0, a_buff.find(';'));
} /* void Instruction::RemoveComment(string &a_buff); */

void Instruction::SplitInstruction(string &a_buff, string &a_firstInstr, string &a_secondInstr, string &a_thirdInstr, string &a_extra) {
	// Push the instruction into the buffer
	stringstream buffer;
	buffer << a_buff;

	// Pop the first piece of the instruction out
	buffer >> a_firstInstr;

	// Pop the second piece of the instruction out
	buffer >> a_secondInstr;

	// Pop the third piece of the instruction out
	buffer >> a_thirdInstr;

	// Pop the fourth piece of the instruction out
	buffer >> a_extra;
} /* void Instruction::SplitInstruction(string &a_buff, string &a_firstInstr, string &a_secondInstr, string &a_thirdInstr, string &a_extra); */

void Instruction::ArrangeInstruction(string &a_firstInstr, string &a_secondInstr, string &a_thirdInstr, string &a_extra) {
	if (!a_extra.empty()) {
		// If there is extra information, the instruction is invalid
		a_firstInstr = "???";
		a_secondInstr = "???";
		a_thirdInstr = "???";
	}

	if (a_thirdInstr.empty() && !a_firstInstr.empty() && !a_secondInstr.empty()) {
		// If the third piece is empty, the first piece is the op code and the second piece is the operand
		swap(a_firstInstr, a_secondInstr);
		swap(a_firstInstr, a_thirdInstr);
	}

	if (a_secondInstr.empty() && !a_firstInstr.empty()) {
		// If the second piece is empty, the first instruction is the op code
		swap(a_firstInstr, a_secondInstr);
	}

	// Otherwise, the first piece is the label, the second piece is the op code, and the third piece is the operand
} /* void Instruction::ArrangeInstruction(string &a_firstInstr, string &a_secondInstr, string &a_thirdInstr, string &a_extra); */

int Instruction::ParseOpCode(string &a_OpCode) {
	// Convert the op code to lower case
	ToLowerCase(a_OpCode);

	if (a_OpCode.empty()) {
		// If the op code is empty, the instruction is a comment
		m_type = ST_Comment;
		return -1;
	}
	else if (a_OpCode == "end") {
		// If the op code is "end", it is an end instruction
		m_type = ST_End;
		return -1;
	}
	else if (a_OpCode == "org"|| a_OpCode == "ds") {
		// If the op code is "org" or "ds", it is an assembler instruction with invalid op code
		m_type = ST_AssemblerInstr;
		return -1;
	}
	else if (a_OpCode == "dc") {
		// If the op code is "dc", it is an assembler instruction with valid op code
		m_type = ST_AssemblerInstr;
		return ST_DUCK;
	}
	else if (a_OpCode == "add") {
		// If the op code is "add", it is a machine language addition instruction
		m_type = ST_MachineLanguage;
		return ST_ADD;
	}
	else if (a_OpCode == "sub") {
		// If the op code is "sub", it is a machine language subtraction instruction
		m_type = ST_MachineLanguage;
		return ST_SUB;
	}
	else if (a_OpCode == "mult") {
		// If the op code is "mult", it is a machine language multiplitcation instruction
		m_type = ST_MachineLanguage;
		return ST_MULT;
	}
	else if (a_OpCode == "div") {
		// If the op code is "div", it is a machine language division instruction
		m_type = ST_MachineLanguage;
		return ST_DIV;
	}
	else if (a_OpCode == "load") {
		// If the op code is "load", it is a machine language load instruction
		m_type = ST_MachineLanguage;
		return ST_LOAD;
	}
	else if (a_OpCode == "store") {
		// If the op code is "store", it is a machine language store instruction
		m_type = ST_MachineLanguage;
		return ST_STORE;
	}
	else if (a_OpCode == "read") {
		// If the op code is "read", it is a machine language read instruction
		m_type = ST_MachineLanguage;
		return ST_READ;
	}
	else if (a_OpCode == "write") {
		// If the op code is "write", it is a machine language write instruction
		m_type = ST_MachineLanguage;
		return ST_WRITE;
	}
	else if (a_OpCode == "b") {
		// If the op code is "b", it is a machine language branch instruction
		m_type = ST_MachineLanguage;
		return ST_B;
	}
	else if (a_OpCode == "bm") {
		// If the op code is "bm", it is a machine language branch minus instruction
		m_type = ST_MachineLanguage;
		return ST_BM;
	}
	else if (a_OpCode == "bz") {
		// If the op code is "bz", it is a machine language branch zero instruction
		m_type = ST_MachineLanguage;
		return ST_BZ;
	}
	else if (a_OpCode == "bp") {
		// If the op code is "bp", it is a machine language branch positive instruction
		m_type = ST_MachineLanguage;
		return ST_BP;
	}
	else if (a_OpCode == "halt") {
		// If the op code is "halt", it is a machine language branch halt instruction
		m_type = ST_MachineLanguage;
		return ST_HALT;
	}
	else {
		// Otherwise, unknown instruction
		m_type = ST_MachineLanguage;
		a_OpCode = "???";
		return -1;
	}
} /* int Instruction::ParseOpCode(string &a_OpCode); */

void Instruction::ToLowerCase(string &a_buff) {
	// Convert every character to lowercase
	for (int i = 0; i < a_buff.length(); i++) {
		a_buff[i] = tolower(a_buff[i]);
	}
} /* void Instruction::ToLowerCase(string &a_buff); */

bool Instruction::ParseOperand(string &m_Operand) {
	// Push the operand into the buffer
	stringstream buffer;
	buffer << m_Operand;

	int number;

	if (buffer >> number) {
		// If the value can be converted to an integer, the operand is numeric
		m_OperandValue = number;
		return true;
	}
	else {
		// Otherwise, the operand is non-numeric
		m_OperandValue = -1;
		return false;
	}
} /* bool Instruction::ParseOperand(string &m_Operand); */