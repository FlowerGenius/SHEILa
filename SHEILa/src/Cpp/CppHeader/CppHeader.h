/*SHEILa========================================================================
 * Name        : CppHeader.h
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 17, 2018
 * Modified    :
 *==============================================================================
 */
#ifndef SRC_CPP_CPPHEADER_CPPHEADER_H_
#define SRC_CPP_CPPHEADER_CPPHEADER_H_

#include "../CppFile/CppFile.h"
#include "../../ProgrammingLanguage/C/CHeader/CHeader.h"

namespace sheila {
namespace cpp {

/*
 * An abstract model of a header file in C++
 */
class CppHeader :  public CppFile {
public:

	/*
	 * All header file extensions specific to C++, though a C++ header file
	 * may also have a C header file extension
	 */
	enum class CppHeaderExtensions : std::string {
		HH = ".hh",
		HPP = ".hpp",
		HXX = ".hxx"
	};

	CppHeader();

	bool isStandard() const { return standard; }

	virtual ~CppHeader();



private:
	/*
	 * True if this header is part of the C or CPP standard libraries
	 */
	bool standard;

};

} /* namespace cpp */
} /* namespace sheila */

#endif /* SRC_CPP_CPPHEADER_CPPHEADER_H_ */
