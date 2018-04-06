//SHEILa========================================================================
// Name        : CppMemberFunction.h
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 4, 2018
// Modified    :
//==============================================================================

#ifndef CPP_CPPMEMBERFUNCTION_CPPMEMBERFUNCTION_H_
#define CPP_CPPMEMBERFUNCTION_CPPMEMBERFUNCTION_H_

#include <Cpp/Cpp.h>

namespace sheila {
namespace cpp {

/*
 * A Method for a SHEILa Entity
 */
class CppMemberFunction {
public:
	CppMemberFunction();
	virtual ~CppMemberFunction();


private:

	bool _const;
	bool _inline;
	bool _virtual;
	bool _volatile;
	bool _template;

	AccessLevel access_level;
	StorageClass storage_class;

	std::string return_type;

	std::string identifier;

};
} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPPMEMBERFUNCTION_CPPMEMBERFUNCTION_H_ */
