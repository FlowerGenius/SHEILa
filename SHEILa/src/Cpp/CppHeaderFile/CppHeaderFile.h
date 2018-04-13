//SHEILa========================================================================
// Name        : CppHeaderFile.h
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 4, 2018
// Modified    :
//==============================================================================

#ifndef CPP_CPPHEADERFILE_CPPHEADERFILE_H_
#define CPP_CPPHEADERFILE_CPPHEADERFILE_H_

#include <string>
#include <vector>

#include "../Cpp.h"

namespace sheila {
namespace cpp {

typedef enum cpp_standard_library_headers {
	C_ASSERT,
	C_CTYPE,
	C_ERRNO,
	C_FLOAT,
	C_ISO646,
	C_LIMITS,
	C_LOCALE,
	C_MATH,
	C_SETJMP,
	C_SIGNAL,
	C_STDARG,
	C_STDDEF,
	C_STDIO,
	C_STDLIB,
	C_STRING,
	C_TIME,
	C_WCHAR,
	C_WCTYPE,
	ALGORITHM,
	BITSET,
	COMPLEX,
	DEQUE,
	EXCEPTION,
	FSTREAM,
	FUNCTIONAL,
	IOMANIP,
	IOS,
	IOSFWD,
	IOSTREAM,
	ISTREAM,
	ITERATOR,
	LIMITS,
	LIST,
	LOCALE,
	MAP,
	MEMORY,
	NEW,
	NUMERIC,
	OSTREAM,
	QUEUE,
	SET,
	SSTREAM,
	STACK,
	STDEXCEPT,
	STREAMBUF,
	STRING,
	TYPEINFO,
	UTILITY,
	VALARRAY,
	VECTOR
} CppStandardHeaderFile;

/*
 * The .h part of an Entity definition
 */
class CppHeaderFile {
public:
	CppHeaderFile();
	virtual ~CppHeaderFile();

private:
	std::string path;

	std::string author;
	std::string version;
	std::string brief_copyright;
	std::string brief_description;

	std::vector<CppHeaderFile> includes;
};

} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPPHEADERFILE_CPPHEADERFILE_H_ */
