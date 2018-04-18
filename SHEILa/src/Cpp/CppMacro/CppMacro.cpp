//SHEILa========================================================================
// Name        : CppMacro.cpp
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 12, 2018
// Modified    :
//==============================================================================

#include "CppMacro.h"

namespace sheila {
namespace cpp {

CppMacro::CppMacro() {

	std::cerr << "C++ macro object initialized without being declared" << std::endl;
	defined = false;

}

CppMacro::CppMacro(std::string id, std::string value,
		std::vector<std::string> allocator) {
	this->identifier = id;
	this->statement = value;

	if (allocator.size() > 0) {
		arguments(allocator);
	}

	this->defined = true;
}

std::string CppMacro::cpp_str() {

	return "";
}

std::string CppMacro::xml_str() {

	// TODO xml_str for CppMacro

	return "";
}


CppMacro::~CppMacro() {
	// TODO Auto-generated destructor stub
}

} /* namespace cpp */
} /* namespace sheila */

