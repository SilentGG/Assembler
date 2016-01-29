//
//		Symbol table class.
//
#pragma once



// This class is our symbol table.
class SymbolTable {

public:
	const int multiplyDefinedSymbol = -999;

	/**/
	/*
	SymbolTable::AddSymbol() SymbolTable::AddSymbol()

	NAME

	SymbolTable::insertMemory - Add a new symbol to the symbol table.

	SYNOPSIS

	void AddSymbol(string &a_symbol, int a_loc);
	a_symbol --> the symbol to add.
	a_loc    --> the location of the symbol.

	DESCRIPTION

	This function adds a symbol to the symbol table.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	2:38pm 12/24/2015

	*/
	/**/
	void AddSymbol(string &a_symbol, int a_loc);

	/**/
	/*
	SymbolTable::DisplaySymbolTable() SymbolTable::DisplaySymbolTable()

	NAME

	SymbolTable::DisplaySymbolTable - Display the symbol table.

	SYNOPSIS

	void DisplaySymbolTable();

	DESCRIPTION

	This function displays the symbol table.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	2:39pm 12/24/2015

	*/
	/**/
	void DisplaySymbolTable();

	/**/
	/*
	SymbolTable::LookupSymbol() SymbolTable::LookupSymbol()

	NAME

	SymbolTable::LookupSymbol - Lookup a symbol in the symbol table.

	SYNOPSIS

	bool LookupSymbol(string &a_symbol, int &a_loc);
	a_symbol --> the symbol to look up.
	a_loc    --> the location of the symbol.

	DESCRIPTION

	This function displays the symbol table.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	2:40pm 12/24/2015

	*/
	/**/
	bool LookupSymbol(string &a_symbol, int &a_loc);

private:

	// This is the actual symbol table.  The symbol is the key to the map.
	map<string, int> m_symbolTable;

};