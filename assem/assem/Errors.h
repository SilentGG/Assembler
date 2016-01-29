//
// Class to manage error reporting. Note: all members are static so we can access them anywhere.
// What other choices do we have to accomplish the same thing?
//
#ifndef _ERRORS_H
#define _ERRORS_H

#include <string>
#include <vector>

class Errors {

public:

	/**/
	/*
	Errors::InitErrorReporting() Errors::InitErrorReporting()

	NAME

	Errors::InitErrorReporting - Initializes error reports.

	SYNOPSIS

	static bool Errors::InitErrorReporting();

	DESCRIPTION

	This function resets the error report.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	1:41pm 12/24/2015

	*/
	/**/
	static void InitErrorReporting();

	/**/
	/*
	Errors::RecordError() Errors::RecordError()

	NAME

	Errors::RecordError - Records an error message.

	SYNOPSIS

	static void Errors::RecordError(string &a_emsg);
    a_emsg --> the error message.

	DESCRIPTION

	This function stores an error message.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	1:43pm 12/24/2015

	*/
	/**/
	static void RecordError(string &a_emsg);

	/**/
	/*
	Errors::DisplayErrors() Errors::DisplayErrors()

	NAME

	Errors::DisplayErrors - Displays the collected error message.

	SYNOPSIS

	static void Errors::DisplayErrors();

	DESCRIPTION

	This function displays all the stored errors.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	1:43pm 12/24/2015

	*/
	/**/
	static void DisplayErrors();

private:

	// Recorded errors.
	static vector<string> m_ErrorMsgs;
};
#endif