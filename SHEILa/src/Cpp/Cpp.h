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

namespace sheila {
namespace cpp {

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

typedef enum ClassTypes {
	CLASS,
	STRUCT,
	UNION
} ClassType;


class Cpp {
public:

	static bool isReservedWord(std::string);
	static std::string accessLevel(AccessLevel);
	static std::string storageClass(StorageClass);
	static std::string fundamentalType(FundamentalType);
	static std::string classType(ClassType);

	Cpp();
	virtual ~Cpp();

private:

	static std::vector<std::string> reserved_words;

};

} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPP_H_ */
