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

/** @brief An abstract model of a feature of the C++ programming language.
 *  @author FlowerGenius
 *
 *  DOC come up with description
 */
class CppFeature {
public:

	/** @brief Initializes the @a activated data member by default
	 *  @author FlowerGenius
	 *
	 *  Important Note: This constructor is part of a pure virtual abstract
	 *  base class and as such should never be called excepting that a derived
	 *  class calls it as part of the derivation chain.
	 *
	 */
	CppFeature() { activated = true; }

	/** @brief Destroys this CppFeature object
	 *  @author FlowerGenius
	 *
	 *  Important Note: This destructor is part of a pure virtual abstract
	 *  base class and as such should never be called excepting that a derived
	 *  class calls it as part of the derivation chain.
	 *
	 */
	virtual ~CppFeature(){}

	/** @brief Pure virtual member function promising the ability of derived
	 *  types of @c CppFeature to be represented in C++ syntax.
	 *  @author FlowerGenius
	 *  @return C++ string representing this feature in C++ syntax.
	 *
	 *  Since a @c CppFeature is a C++ lexical component, it must
	 *  be able to be represented in valid and portable C++ syntax such that
	 *  it can be inserted into a C++ file and form functioning code.
	 *
	 */
	virtual std::string cpp_str() = 0;

	/** @brief Pure virtual member function promising the ability of derived
	 *  types of @c CppFeature to be represented in XML syntax.
	 *  @author FlowerGenius
	 *  @return C++ string representing this feature in XML syntax.
	 *
	 *  Since a @c CppFeature is a C++ lexical component, it can be
	 *  represented using XML.
	 *
	 *  In the C++ program structure model that is defined in the classes found
	 *  in this library, any feature of C++ that can be represented in C++
	 *  syntax can also be represented in a strictly typed specialization of
	 *  XML that can be used to form a meta-level understanding of a C++
	 *  program and each of it's individual components.
	 *
	 *  TL;DR Any feature of C++ can be represented as an XML tag as well.
	 *
	 */
	virtual std::string xml_str() = 0;

protected:

	/** @brief Represents the commented/uncommented state of the feature */
	bool activated;
};

/** @brief Dummy class representing the C++ programming language.
 *  @author FlowerGenius
 *
 *  Stores actions and members which are part of the implementation of the
 *  language.
 *
 *  Important Note: This class is not mean to be instantiated, it is simply
 *  a scoped wrapper for functions and operations specific to C++.
 *
 */
class Cpp {
public:

	enum class ArtifactType {
		EXECUTABLE,
		STATIC_LIBRARY,
		SHARED_LIBRARY
	};

	static bool isReservedWord(std::string);
	static std::string accessLevel(AccessLevel);
	static std::string storageClass(StorageClass);
	static std::string fundamentalType(FundamentalType);

	Cpp() {};
	virtual ~Cpp() {};

private:

	static std::vector<std::string> reserved_words;

};

} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPP_H_ */
