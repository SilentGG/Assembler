//
//		Emulator class - supports the emulation of VC3600 programs
//
#ifndef _EMULATOR_H      // UNIX way of preventing multiple inclusions.
#define _EMULATOR_H

class emulator {

public:
	// The size of the memory of the VC3600.
	const static int MEMSZ = 10000;

	emulator() {
		memset(m_memory, 0, MEMSZ * sizeof(int));
	}

	/**/
	/*
	emulator::insertMemory() emulator::insertMemory()

	NAME

	emulator::insertMemory - Records instructions and data into VC3600 memory.

	SYNOPSIS

	bool emulator::insertMemory(int a_location, int a_contents);
    a_location --> the location in memory.
    a_contents --> the data to insert.

	DESCRIPTION

	This function insert the given contents into a given location
	in memory.

	RETURNS

	Returns false if the location is outside memory.
	Returns true if successfully installed.

	AUTHOR

	Joe Gramuglia

	DATE

	4:22am 12/24/2015

	*/
	/**/
	bool insertMemory(int a_location, int a_contents);

	/**/
	/*
	emulator::runProgram() emulator::runProgram()

	NAME

	emulator::runProgram - Runs the VC3600 program recorded in memory.

	SYNOPSIS

	bool emulator::runProgram();

	DESCRIPTION

	This function runs the translated program.

	RETURNS

	Returns true if successful.

	AUTHOR

	Joe Gramuglia

	DATE

	4:25am 12/24/2015

	*/
	/**/
	bool runProgram();

private:

	// The memory of the VC3600.
	int m_memory[MEMSZ];

	/**/
	/*
	emulator::add() emulator::add()

	NAME

	emulator::add - Adds a value to the accumulator.

	SYNOPSIS

	void emulator::add(int &a_address, int &a_acc);
    a_address --> the location in memory.
    a_acc     --> the accumulator.

	DESCRIPTION

	This function adds a given value to the accumulator.
	The result is stored in the accumulator.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	4:26am 12/24/2015

	*/
	/**/
	void add(int &a_address, int &a_acc);

	/**/
	/*
	emulator::subtract() emulator::subtract()

	NAME

	emulator::subtract - Subract a value from the accumulator.

	SYNOPSIS

	void subtract(int &a_address, int &a_acc);
    a_address --> the location in memory.
    a_acc     --> the accumulator.

	DESCRIPTION

	This function subtracts a value from the accumulator.
	The result is stored in the accumulator.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	4:28am 12/24/2015

	*/
	/**/
	void subtract(int &a_address, int &a_acc);

	/**/
	/*
	emulator::multiply() emulator::multiply()

	NAME

	emulator::multiply - Multiply a value with the accumulator.

	SYNOPSIS

	void multiply(int &a_address, int &a_acc);
    a_address --> the location in memory.
    a_acc     --> the accumulator.

	DESCRIPTION

	This function multiplies a given value with the accumulator.
	The result is stored in the accumulator.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	4:29am 12/24/2015

	*/
	/**/
	void multiply(int &a_address, int &a_acc);

	/**/
	/*
	emulator::divide() emulator::divide()

	NAME

	emulator::divide - Divide the accumulator by a value.

	SYNOPSIS

	void divide(int &a_address, int &a_acc);
    a_address --> the location in memory.
    a_acc     --> the accumulator.

	DESCRIPTION

	This function divides a given value with the accumulator.
	The result is stored in the accumulator.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	4:30am 12/24/2015

	*/
	/**/
	void divide(int &a_address, int &a_acc);

	/**/
	/*
	emulator::load() emulator::load()

	NAME

	emulator::load - Load a value into the accumulator.

	SYNOPSIS

	void load(int &a_address, int &a_acc);
    a_address --> the location in memory.
    a_acc     --> the accumulator.

	DESCRIPTION

	This function loads a given value into the accumulator.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	4:30am 12/24/2015

	*/
	/**/
	void load(int &a_address, int &a_acc);

	/**/
	/*
	emulator::store() emulator::store()

	NAME

	emulator::store - Store the accumulator to a memory location.

	SYNOPSIS

	void store(int &a_address, int &a_acc);
    a_address --> the location in memory.
    a_acc     --> the accumulator.

	DESCRIPTION

	This function stores the accumulator to a memory location.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	4:33am 12/24/2015

	*/
	/**/
	void store(int &a_address, int &a_acc);

	/**/
	/*
	emulator::read() emulator::read()

	NAME

	emulator::read - Read input into a memory location.

	SYNOPSIS

	void read(int &a_address);
    a_address --> the location in memory

	DESCRIPTION

	This function reads input into a memory location.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	4:34am 12/24/2015

	*/
	/**/
	void read(int &a_address);

	/**/
	/*
	emulator::write() emulator::write()

	NAME

	emulator::write - Write a value out to the screen.

	SYNOPSIS

	void write(int &a_address);
    a_address --> the location in memory

	DESCRIPTION

	This function writes a value out to the screen.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	4:35am 12/24/2015

	*/
	/**/
	void write(int &a_address);

	/**/
	/*
	emulator::branch() emulator::branch()

	NAME

	emulator::branch - Branch to a given memory location.

	SYNOPSIS

	void branch(int &a_address, int &a_loc);
    a_address --> the location in memory
	a_loc     --> the location to be set

	DESCRIPTION

	This function branches to a given memory location.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	4:37am 12/24/2015

	*/
	/**/
	void branch(int &a_address, int &a_loc);

	/**/
	/*
	emulator::branchMinus() emulator::branchMinus()

	NAME

	emulator::branchMinus - Branch if the accumulator is negative.

	SYNOPSIS

	void branchMinus(int &a_address, int &a_acc, int &a_loc);
    a_address --> the location in memory.
    a_acc     --> the accumulator.
	a_loc     --> the location to be set.

	DESCRIPTION

	This function branches if the accumulator is negative.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	4:37am 12/24/2015

	*/
	/**/
	void branchMinus(int &a_address, int &a_acc, int &a_loc);

	/**/
	/*
	emulator::branchZero() emulator::branchZero()

	NAME

	emulator::branchZero - Branch if the accumulator is zero.

	SYNOPSIS

	void branchZero(int &a_address, int &a_acc, int &a_loc);
    a_address --> the location in memory.
    a_acc     --> the accumulator.
	a_loc     --> the location to be set.

	DESCRIPTION

	This function branches if the accumulator is zero.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	4:39am 12/24/2015

	*/
	/**/
	void branchZero(int &a_address, int &a_acc, int &a_loc);

	/**/
	/*
	emulator::branchPositive() emulator::branchPositive()

	NAME

	emulator::branchPositive - Branch if the accumulator is positive.

	SYNOPSIS

	void branchPositive(int &a_address, int &a_acc, int &a_loc);
    a_address --> the location in memory.
    a_acc     --> the accumulator.
	a_loc     --> the location to be set.

	DESCRIPTION

	This function branches if the accumulator is positive.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	4:41am 12/24/2015

	*/
	/**/
	void branchPositive(int &a_address, int &a_acc, int &a_loc);
};

#endif
