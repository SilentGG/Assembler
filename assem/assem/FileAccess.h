//
//		File access to source file.
//
#ifndef _FILEACCESS_H  // This is the way that multiple inclusions are defended against often used in UNIX
#define _FILEACCESS_H // We use pramas in Visual Studio.  See other include files

#include <fstream>
#include <stdlib.h>
#include <string>

class FileAccess {

public:

	/**/
	/*
	FileAccess::FileAccess() FileAccess::FileAccess()

	NAME

	FileAccess::FileAccess - Opens the file.

	SYNOPSIS

	FileAccess::FileAccess(int argc, char *argv[]);
	argc --> the number of arguments.
	argv --> the arguments.

	DESCRIPTION

	This function opens the file.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	1:49pm 12/24/2015

	*/
	/**/
	FileAccess(int argc, char *argv[]);

	/**/
	/*
	FileAccess::~FileAccess() FileAccess::~FileAccess()

	NAME

	FileAccess::~FileAccess - Closes the file.

	SYNOPSIS

	FileAccess::~FileAccess();

	DESCRIPTION

	This function closes the file.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	1:49pm 12/24/2015

	*/
	/**/
	~FileAccess();

	/**/
	/*
	FileAccess::GetNextLine() FileAccess::GetNextLine()

	NAME

	FileAccess::GetNextLine - Get the next line from the source file.

	SYNOPSIS

	bool FileAccess::GetNextLine(string &a_buff);
	a_buff --> the line read from the file.

	DESCRIPTION

	This function read a line from the file.

	RETURNS

	Returns false if at end of file.
	Returns true if successful.

	AUTHOR

	Joe Gramuglia

	DATE

	1:52pm 12/24/2015

	*/
	/**/
	bool GetNextLine(string &a_buff);

	/**/
	/*
	FileAccess::rewind() FileAccess::rewind()

	NAME

	FileAccess::rewind - Put the file pointer back to the beginning of the file.

	SYNOPSIS

	void FileAccess::rewind();

	DESCRIPTION

	This function put the file pointer back to the beginning of the file.

	RETURNS

	Returns void.

	AUTHOR

	Joe Gramuglia

	DATE

	1:55pm 12/24/2015

	*/
	/**/
	void rewind();

private:

	// Source file object.
	ifstream m_sfile;
};
#endif
