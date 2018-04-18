//SHEILa========================================================================
// Name        : CppVariable.h
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 12, 2018
// Modified    :
//==============================================================================

#ifndef SRC_CPP_CPPVARIABLE_CPPVARIABLE_H_
#define SRC_CPP_CPPVARIABLE_CPPVARIABLE_H_

#include <string>

#include "../Cpp.h"

namespace sheila {
namespace cpp {

/*
 * An abstract model of a variable in C++
 */

class CppVariable : public CppFeature {
public:
	CppVariable();
	virtual ~CppVariable();

private:

	std::string type;
	std::string identifier;


};

} /* namespace cpp */
} /* namespace sheila */

#endif /* SRC_CPP_CPPVARIABLE_CPPVARIABLE_H_ */
