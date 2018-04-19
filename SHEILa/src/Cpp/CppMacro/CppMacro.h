//SHEILa========================================================================
// Name        : CppMacro.h
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 12, 2018
// Modified    :
//==============================================================================

#ifndef CPP_CPPMACRO_CPPMACRO_H_
#define CPP_CPPMACRO_CPPMACRO_H_

#include <string>
#include <vector>
#include <iostream>

#include "../Cpp.h"

namespace sheila {
namespace cpp {

class CppMacro : public CppFeature {
public:

	/*
	 * Set the macro located at the address of the pointer to defined
	 */
	static int define_macro(CppMacro *mptr) { return mptr->define(); }

	/*
	 * Set the macro located at the address of the pointer to undefined
	 */
	static int undefine_macro(CppMacro *mptr) { return mptr->undefine(); }

	CppMacro();

	CppMacro(std::string id, std::string value, std::vector<std::string> = {});

	/*
	 * Test for whether the macro is defined
	 */
	bool isDefined() { return (this->defined && this->activated); }

	/*
	 * Set the macro as defined
	 */
	int define() { defined = true; return (this->defined == true); }

	/*
	 * Set the macro as undefined
	 */
	int undefine() { defined = false; return (this->defined == false); }

	const std::string& getIdentifier() const { return identifier; }
	const std::string& getStatement() const { return statement; }
	const std::vector<std::string>& getArguments() const {return arguments; }


	std::string cpp_str();

	std::string xml_str();

	virtual ~CppMacro();

private:

	bool defined;
	std::string identifier;
	std::vector<std::string> arguments;
	std::string statement;

};

} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPPMACRO_CPPMACRO_H_ */
