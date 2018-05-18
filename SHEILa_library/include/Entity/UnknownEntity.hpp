//SHEILa========================================================================
// Name        : UnknownEntity.h
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 12, 2018
// Modified    :
//==============================================================================

#ifndef SRC_ENTITY_UNKNOWNENTITY_UNKNOWNENTITY_H_
#define SRC_ENTITY_UNKNOWNENTITY_UNKNOWNENTITY_H_

#include "Entity/Entity.hpp"

namespace sheila {

class UnknownEntity {
public:
	UnknownEntity();
	virtual ~UnknownEntity();
protected:

private:
	std::string proposed_class_name;
	std::string proposed_enum_name;


};

} /* namespace sheila */

#endif /* SRC_ENTITY_UNKNOWNENTITY_UNKNOWNENTITY_H_ */
