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

#include "../Cpp.h"

namespace sheila {
namespace cpp {

/*
 * A Method for a SHEILa Entity
 */
class CppMemberFunction {
public:
	CppMemberFunction();
	virtual ~CppMemberFunction();

	const std::string& getIdentifier() const {
		return identifier;
	}

	void setIdentifier(const std::string& identifier) {
		this->identifier = identifier;
	}

private:

	bool _const_;
	bool _inline_;
	bool _virtual_;
	bool _volatile_;
	bool _template_;

	AccessLevel access_level;
	StorageClass storage_class;

	std::string return_type;

	std::string identifier;

};
} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPPMEMBERFUNCTION_CPPMEMBERFUNCTION_H_ */
