//SHEILa========================================================================
// Name        : CppSourceFile.h
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 4, 2018
// Modified    :
//==============================================================================

#ifndef CPP_CPPSOURCEFILE_CPPSOURCEFILE_H_
#define CPP_CPPSOURCEFILE_CPPSOURCEFILE_H_

#include <string>
#include <vector>

#include "../Cpp.h"
#include "../CppHeaderFile/CppHeaderFile.h"


namespace sheila {
namespace cpp {

/*
 * The .cpp part of an Entity definition
 */
class CppSourceFile {
public:
	CppSourceFile();
	virtual ~CppSourceFile();
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

#endif /* CPP_CPPSOURCEFILE_CPPSOURCEFILE_H_ */
