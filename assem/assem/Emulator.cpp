#pragma once

#include "stdafx.h"
#include "Emulator.h"
#include <sstream>

bool emulator::insertMemory(int a_location, int a_contents)
{
	if (a_location >= MEMSZ) {
		// If the location is outside memory, can't insert
		return false;
	}

	// Insert contents into memory location
	m_memory[a_location] = a_contents;
	return true;
} /* bool emulator::insertMemory(int a_location, int a_contents); */

bool emulator::runProgram()
{
	int accumulator = 0;

	// Start at location 100
	int loc = 100;

	while (true) {
		// The value at the memory location
		int content = m_memory[loc];

		// The operation code
		int opCode = content / 10000;

		// The address
		int address = content % 10000;

		if (opCode == 13) {
			// Halt.
			break;
		}

		if (opCode == 8) {
			// Write.
			write(address);
		}

		if (opCode == 7) {
			// Read.
			read(address);
		}

		if (opCode == 6) {
			// Store.
			store(address, accumulator);
		}

		if (opCode == 5) {
			// Load.
			load(address, accumulator);
		}

		if (opCode == 4) {
			// Divide.
			divide(address, accumulator);
		}

		if (opCode == 3) {
			// Multiply.
			multiply(address, accumulator);
		}

		if (opCode == 2) {
			// Subtract.
			subtract(address, accumulator);
		}

		if (opCode == 1) {
			// Add.
			add(address, accumulator);
		}

		// Increment location.
		loc++;

		if (opCode == 12) {
			// Branch if accumulator is positive.
			branchPositive(address, accumulator, loc);
		}

		if (opCode == 11) {
			// Branch if accumulator is zero.
			branchZero(address, accumulator, loc);
		}

		if (opCode == 10) {
			// Branch if accumulator is negative
			branchMinus(address, accumulator, loc);
		}

		if (opCode == 9) {
			// Branch to location
			branch(address, loc);
		}
	}
	return true;
} /* bool emulator::runProgram(); */

void emulator::add(int &a_address, int &a_acc) {
	// Add a value in memory to the accumulator.
	a_acc = a_acc + m_memory[a_address];
} /* void emulator::add(int &a_address, int &a_acc); */

void emulator::subtract(int &a_address, int &a_acc) {
	// Subtract a value in memory from the accumulator.
	a_acc = a_acc - m_memory[a_address];
} /* void emulator::subtract(int &a_address, int &a_acc); */

void emulator::multiply(int &a_address, int &a_acc) {
	// Multiply a value in memory with the accumulator.
	a_acc = a_acc * m_memory[a_address];
} /* void emulator::multiply(int &a_address, int &a_acc); */

void emulator::divide(int &a_address, int &a_acc) {
	// Divide the accumulator by a value in memory.
	a_acc = a_acc / m_memory[a_address];
} /* void emulator::divide(int &a_address, int &a_acc); */

void emulator::load(int &a_address, int &a_acc) {
	// Load a value in memory into the accumulator.
	a_acc = m_memory[a_address];
} /* void emulator::load(int &a_address, int &a_acc); */

void emulator::store(int &a_address, int &a_acc) {
	// Store the accumulator into a memory location.
	m_memory[a_address] = a_acc;
} /* void emulator::store(int &a_address, int &a_acc); */

void emulator::read(int &a_address) {
	// Prompt the user for input.
	cout << "? ";

	string input;
	cin >> input;

	stringstream ss;
	ss << input;

	// Retrieve the first 6 digits.
	string first6 = "";
	if (input.length() > 6) {
		for (int i = 0; i < 6; i++) {
			first6 += input[i];
		}
	}
	else {
		first6 = input;
	}

	ss.str("");

	// Convert the number to an integer.
	ss << first6;

	int number;
	ss >> number;

	// Insert into memory.
	m_memory[a_address] = number;
} /* void emulator::read(int &a_address) */

void emulator::write(int &a_address) {
	// Output the value at a memory location to the screen.
	cout << m_memory[a_address] << endl;
} /* void emulator::write(int &a_address) */

void emulator::branch(int &a_address, int &a_loc) {
	// Branch to a value of a memory location
	a_loc = a_address;
} /* void emulator::branch(int &a_address, int &a_loc) */

void emulator::branchMinus(int &a_address, int &a_acc, int &a_loc) {
	if (a_acc < 0) {
		// If the accumulator is negative, branch.
		a_loc = a_address;
	}
} /* void emulator::branchMinus(int &a_address, int &a_acc, int &a_loc) */

void emulator::branchZero(int &a_address, int &a_acc, int &a_loc) {
	if (a_acc = 0) {
		// If the accumulator is zero, branch.
		a_loc = a_address;
	}
} /* void emulator::branchZero(int &a_address, int &a_acc, int &a_loc) */

void emulator::branchPositive(int &a_address, int &a_acc, int &a_loc) {
	if (a_acc > 0) {
		// If the accumulator is positive, branch.
		a_loc = a_address;
	}
} /* void emulator::branchPositive(int &a_address, int &a_acc, int &a_loc) */

