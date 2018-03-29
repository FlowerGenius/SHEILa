//SHEILa======================================================================
// Name        : Entity.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 29, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_ENTITY_H_
#define ENTITY_ENTITY_H_

#include <string>

namespace sheila {

class Entity {
public:

	/* Promises that each subclass of entity has variable "name" */
	static const std::string  _name;

	/* Promises that each subclass of entity has variable "desc" */
	static const std::string  _desc;

	Entity();
	virtual ~Entity();

protected:

	/* Returns a string representation of this instance such that it can be
	 * restored using "eval()"
	 */
	virtual std::string repr();

	/* Turns this instance of Entity into a copy of the instance stored using
	 * "repr()"
	 */
	virtual void eval(std::string);



};

} /* namespace sheila */

#endif /* ENTITY_ENTITY_H_ */
