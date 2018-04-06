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

#include <Cpp/Cpp.h>


namespace sheila {
namespace cpp {

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
