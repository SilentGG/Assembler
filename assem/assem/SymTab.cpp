//
//		Implementation of the symbol table class.
//
#include "stdafx.h"
#include "SymTab.h"

void SymbolTable::AddSymbol(string &a_symbol, int a_loc)
{
	map<string, int>::iterator st = m_symbolTable.find(a_symbol);

	if (st != m_symbolTable.end()) {
		// If the symbol is already in the symbol table, record it as multiply defined.
		st->second = multiplyDefinedSymbol;
		return;
	}

	// Record a the  location in the symbol table.
	m_symbolTable[a_symbol] = a_loc;
} /* void SymbolTable::AddSymbol(string &a_symbol, int a_loc); */

void SymbolTable::DisplaySymbolTable()
{
	cout << "Symbol#\tSymbol\tLocation" << endl;

	// Holds the symbol number
	int counter = 0;

	// Output every symbol in symbol table
	for (map<string, int>::iterator it = m_symbolTable.begin(); it != m_symbolTable.end(); ++it) {
		cout << counter << "\t" << it->first << "\t" << it->second << endl;
		counter++;
	}

	cout << endl;
} /* void SymbolTable::DisplaySymbolTable(); */

bool SymbolTable::LookupSymbol(string &a_symbol, int &a_loc) {

	map<string, int>::iterator st = m_symbolTable.find(a_symbol);

	if (st == m_symbolTable.end()) {
		// If the symbol isn't in the symbol table, the look up was unsuccessful
		return false;
	}

	a_loc = m_symbolTable[a_symbol];
	return true;
} /* bool SymbolTable::LookupSymbol(string &a_symbol, int &a_loc); */