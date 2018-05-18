//SHEILa========================================================================
// Name        : Schema.hpp
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 9, 2018
// Modified    :
//==============================================================================

#ifndef ENTITY_SCHEMA_SCHEMA_HPP_
#define ENTITY_SCHEMA_SCHEMA_HPP_

#include "Entity/Entity.hpp"

namespace sheila {

class Schema: public Entity<Schema> {
public:
	Schema();
	virtual ~Schema();
};

} /* namespace sheila */

#endif /* ENTITY_SCHEMA_SCHEMA_HPP_ */
