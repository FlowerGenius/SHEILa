//SHEILa========================================================================
// Name        : Cpp.h
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 4, 2018
// Modified    :
//==============================================================================

#ifndef CPP_CPP_H_
#define CPP_CPP_H_

#include <string>
#include <vector>

#include "../ProgrammingLanguage/C/language.inc"
#include "../symbols.inc"


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

typedef enum AccessLevels {
	PRIVATE,
	PROTECTED,
	PUBLIC
} AccessLevel;

typedef enum StorageClasses {
	STATIC,
	EXTERN,
	MUTABLE,
	AUTO,
	REGISTER
} StorageClass;

typedef enum FundamentalTypes {
	VOID = -1,
	BOOL,
	CHAR,
	WCHAR,
	SHORT,
	INT,
	LONG,
	FLOAT,
	DOUBLE,
	LONG_DOUBLE
} FundamentalType;

class CppFeature {
public:
	CppFeature() {

	}

	virtual ~CppFeature(){

	}

protected:

};

class Cpp {
public:

	static bool isReservedWord(std::string);
	static std::string accessLevel(AccessLevel);
	static std::string storageClass(StorageClass);
	static std::string fundamentalType(FundamentalType);
//	static std::string classType(ClassType);

	Cpp();
	virtual ~Cpp();

private:

	static std::vector<std::string> reserved_words;

};

} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPP_H_ */
