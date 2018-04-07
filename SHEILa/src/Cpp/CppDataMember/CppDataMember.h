//SHEILa========================================================================
// Name        : CppDataMember.h
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 4, 2018
// Modified    :
//==============================================================================

#ifndef CPP_CPPDATAMEMBER_CPPDATAMEMBER_H_
#define CPP_CPPDATAMEMBER_CPPDATAMEMBER_H_

#include "../Cpp.h"


namespace sheila {
namespace cpp {

/*
 * A variable in a SHEILa Entity
 */
class CppDataMember {
public:
	CppDataMember();
	virtual ~CppDataMember();

private:

	bool _const_;
	bool _inline_;
	bool _volatile_;

	AccessLevel access_level;
	StorageClass storage_class;

	std::string type;

	std::string identifier;

};

} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPPDATAMEMBER_CPPDATAMEMBER_H_ */
