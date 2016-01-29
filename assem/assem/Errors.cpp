#include "stdafx.h"
#include "Errors.h"

void Errors::InitErrorReporting() {
	// Reset the vector.
	m_ErrorMsgs.clear();
} /* void Errors::InitErrorReporting(); */

void Errors::RecordError(string &a_emsg) {
	// Add error to vector.
	m_ErrorMsgs.push_back(a_emsg);
} /* void Errors::RecordError(string &a_emsg); */

void Errors::DisplayErrors() {
	// Output every error message.
	for (int i = 0; i < m_ErrorMsgs.size(); i++) {
		cout << m_ErrorMsgs[i] << ", ";
	}
} /* void Errors::DisplayErrors(); */

vector<string> Errors::m_ErrorMsgs;