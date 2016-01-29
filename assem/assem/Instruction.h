//
// Class to parse and provide information about instructions
//
#pragma once

// The elements of an instruction.
class Instruction {

public:

	Instruction() { };
	~Instruction() { };

	// Codes to indicate the type of instruction we are processing.
	enum InstructionType {
		ST_MachineLanguage, // A machine language instruction.
		ST_AssemblerInstr,  // Assembler Language instruction.
		ST_Comment,          // Comment or blank line
		ST_End                    // end instruction.
	};

	/**/
	/*
	Instruction::ParseInstruction() Instruction::ParseInstruction()

	NAME

	Instruction::ParseInstruction - Parse the Instruction.

	SYNOPSIS

	InstructionType Instruction::ParseInstruction(string &a_buff);
	a_buff --> the string to parse.

	DESCRIPTION

	This function parses a string to an instruction.

	RETURNS

	Returns ST_End if the string has an end instruction.
	Returns ST_Comment if the string is blank or contains a semi-colon with nothing before it.
	Returns ST_AssemblerInstr if contains a assembler instruction.
	Returns ST_MachineLanguage otherwise.

	AUTHOR

	Joe Gramuglia

	DATE

	2:04pm 12/24/2015

	*/
	/**/
	InstructionType ParseInstruction(string &a_buff);

	/**/
	/*
	Instruction::LocationNextInstruction() Instruction::LocationNextInstruction()

	NAME

	Instruction::LocationNextInstruction - Compute the location of the next instruction.

	SYNOPSIS

	int Instruction::LocationNextInstruction(int a_loc);
	a_loc --> the current location.

	DESCRIPTION

	This function calculates the location of the next instruction.

	RETURNS

	Returns the new location.

	AUTHOR

	Joe Gramuglia

	DATE

	2:07pm 12/24/2015

	*/
	/**/
	int LocationNextInstruction(int a_loc);

	/**/
	/*
	Instruction::&GetLabel() Instruction::&GetLabel()

	NAME

	Instruction::&GetLabel - To access the label.

	SYNOPSIS

	inline string &GetLabel();

	DESCRIPTION

	This function is uses to access the instruction label.

	RETURNS

	Returns the label.

	AUTHOR

	Joe Gramuglia

	DATE

	2:09pm 12/24/2015

	*/
	/**/
	inline string &GetLabel() {
		return m_Label;
	};

	/**/
	/*
	Instruction::isLabel() Instruction::isLabel()

	NAME

	Instruction::isLabel - To determine if a label is blank.

	SYNOPSIS

	inline bool isLabel();

	DESCRIPTION

	This function is uses to access the instruction label.

	RETURNS

	Returns true if the label isn't empty.
	Returns false otherwise.

	AUTHOR

	Joe Gramuglia

	DATE

	2:10pm 12/24/2015

	*/
	/**/
	inline bool isLabel() {
		return !m_Label.empty();
	};

	/**/
	/*
	Instruction::&GetOpCode() Instruction::&GetOpCode()

	NAME

	Instruction::&GetOpCode - To access the operation code.

	SYNOPSIS

	inline string &GetOpCode();

	DESCRIPTION

	This function is uses to access the operation code instruction.

	RETURNS

	Returns the operation code instruction.

	AUTHOR

	Joe Gramuglia

	DATE

	2:12pm 12/24/2015

	*/
	/**/
	inline string &GetOpCode() {
		return m_OpCode;
	};

	/**/
	/*
	Instruction::&GetNumOpCode() Instruction::&GetNumOpCode()

	NAME

	Instruction::&GetNumOpCode - To access the numeric value of the operation code.

	SYNOPSIS

	inline int &GetNumOpCode();

	DESCRIPTION

	This function is uses to access the numeric value of the operation code.

	RETURNS

	Returns the numeric value of the operation code.

	AUTHOR

	Joe Gramuglia

	DATE

	2:14pm 12/24/2015

	*/
	/**/
	inline int &GetNumOpCode() {
		return m_NumOpCode;
	};

	/**/
	/*
	Instruction::&GetOperand() Instruction::&GetOperand()

	NAME

	Instruction::&GetOperand - To access the operand.

	SYNOPSIS

	inline string &GetOperand();

	DESCRIPTION

	This function is uses to access the operand.

	RETURNS

	Returns the operand.

	AUTHOR

	Joe Gramuglia

	DATE

	2:14pm 12/24/2015

	*/
	/**/
	inline string &GetOperand() {
		return m_Operand;
	};

	/**/
	/*
	Instruction::&IsNumericOperand() Instruction::&IsNumericOperand()

	NAME

	Instruction::&IsNumericOperand - To determine if a operand is numeric.

	SYNOPSIS

	inline bool &IsNumericOperand();

	DESCRIPTION

	This function is uses to access the operand.

	RETURNS

	Returns the operand.

	AUTHOR

	Joe Gramuglia

	DATE

	2:15pm 12/24/2015

	*/
	/**/
	inline bool IsNumericOperand() {
		return m_IsNumericOperand;
	};

	/**/
	/*
	Instruction::&GetOperandValue() Instruction::&GetOperandValue()

	NAME

	Instruction::&GetOperandValue - To access the numeric operand.

	SYNOPSIS

	inline int &GetOperandValue();

	DESCRIPTION

	This function is uses to access the numeric value of the operand.

	RETURNS

	Returns the numeric operand.

	AUTHOR

	Joe Gramuglia

	DATE

	2:16pm 12/24/2015

	*/
	/**/
	inline int &GetOperandValue() {
		return m_OperandValue;
	};


private:


	// The elemements of a instruction
	string m_Label;        // The label.
	string m_OpCode;       // The symbolic op code.
	string m_Operand;      // The operand.


	string m_instruction;    // The original instruction.

							 // Derived values.
	int m_NumOpCode;     // The numerical value of the op code.
	InstructionType m_type; // The type of instruction.

	bool m_IsNumericOperand;// == true if the operand is numeric.
	int m_OperandValue;   // The value of the operand if it is numeric.

	/**/
	/*
	Instruction::RemoveComment() Instruction::RemoveComment()

	NAME

	Instruction::RemoveComment - To remove the comment from a string.

	SYNOPSIS

	void RemoveComment(string &a_buff);
    a_buff --> the string.

	DESCRIPTION

	This function removes the first semi-colon and everything past it from the string.

	RETURNS

	Returns string without the comment.

	AUTHOR

	Joe Gramuglia

	DATE

	2:19pm 12/24/2015

	*/
	/**/
	void RemoveComment(string &a_buff);

	/**/
	/*
	Instruction::SplitInstruction() Instruction::SplitInstruction()

	NAME

	Instruction::SplitInstruction - To split the string into pieces.

	SYNOPSIS

	void SplitInstruction(string &a_buff, string &a_firstInstr, string &a_secondInstr, string &a_thirdInstr, string &a_extra);
	a_buff        --> the string.
	a_firstInstr  --> the first word of the string.
	a_secondInstr --> the second word of the string.
	a_thirdInstr  --> the third word of the string.
	a_extra       --> the fourth word of the string.

	DESCRIPTION

	This function splits the instruction into pieces.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	2:22pm 12/24/2015

	*/
	/**/
	void SplitInstruction(string &a_buff, string &a_firstInstr, string &a_secondInstr, string &a_thirdInstr, string &a_extra);

	/**/
	/*
	Instruction::ArrangeInstruction() Instruction::ArrangeInstruction()

	NAME

	Instruction::ArrangeInstruction - To arrange the pieces of the instruction to the appropriate order.

	SYNOPSIS

	void ArrangeInstruction(string &firstInstr, string &secondInstr, string &thirdInstr, string &extra);
	a_firstInstr  --> the first word of the string.
	a_secondInstr --> the second word of the string.
	a_thirdInstr  --> the third word of the string.
	a_extra       --> the fourth word of the string.

	DESCRIPTION

	This function arrange the pieces of the instruction to the appropriate order.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	2:24pm 12/24/2015

	*/
	/**/
	void ArrangeInstruction(string &firstInstr, string &secondInstr, string &thirdInstr, string &extra);

	/**/
	/*
	Instruction::ParseOpCode() Instruction::ParseOpCode()

	NAME

	Instruction::ParseOpCode - To parse the operation code.

	SYNOPSIS

	int ParseOpCode(string &a_OpCode);
	a_OpCode --> the operation code.

	DESCRIPTION

	This function converts the operation code from a string to a numerical value.

	RETURNS

	Returns the numeric operation code.

	AUTHOR

	Joe Gramuglia

	DATE

	2:26pm 12/24/2015

	*/
	/**/
	int ParseOpCode(string &a_OpCode);

	/**/
	/*
	Instruction::ToLowerCase() Instruction::ToLowerCase()

	NAME

	Instruction::ToLowerCase - To parse the operation code.

	SYNOPSIS

	void ToLowerCase(string &a_buff);
	a_buff --> the string to convert.

	DESCRIPTION

	This function coverts a string to lowercase.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	2:28pm 12/24/2015

	*/
	/**/
	void ToLowerCase(string &a_buff);

	/**/
	/*
	Instruction::ParseOperand() Instruction::ParseOperand()

	NAME

	Instruction::ParseOperand - To parse the operand.

	SYNOPSIS

	bool ParseOperand(string &a_Operand);
	a_Operand --> the operand to convert.

	DESCRIPTION

	This function tries to coverts a operand to a numeric value.

	RETURNS

	Returns true if successful.
	Returns false if the operand isn't numeric.

	AUTHOR

	Joe Gramuglia

	DATE

	2:31pm 12/24/2015

	*/
	/**/
	bool ParseOperand(string &a_Operand);

	enum OpCode {
		ST_DUCK, // :)
		ST_ADD,
		ST_SUB,
		ST_MULT,
		ST_DIV,
		ST_LOAD,
		ST_STORE,
		ST_READ,
		ST_WRITE,
		ST_B,
		ST_BM,
		ST_BZ,
		ST_BP,
		ST_HALT
	};
};

