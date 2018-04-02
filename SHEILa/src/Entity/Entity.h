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

#include <symbols.inc>

#include <string>
#include <vector>
#include <typeinfo>


namespace sheila {

class Entity {
public:

	static std::vector<Entity> entities;

	template <class _T>
	static std::string repr(_T e) {
		return e._E_repr();
	}

	Entity();
	virtual ~Entity();

	bool hasParent(Entity);

	bool hasChild(Entity);

	int makeParentOf(Entity);

	int makeChildOf(Entity);

	virtual const std::vector<std::string>& _getName() const;
	virtual const std::vector<std::string>& _getDesc() const;
	virtual const std::vector<Entity>& _getParents() const;
	virtual const std::vector<Entity>& _getChildren() const;




protected:


	/* Promises that each subclass of entity has variable "name" */
	std::vector<std::string> _name;

	/* Promises that each subclass of entity has variable "desc" */
	std::vector<std::string> _desc;

	std::vector<Entity> _parents;

	std::vector<Entity> _children;

	/* The location on the server database of where this class and it's
	 * header file are located.
	 */
	std::string  _classpath;

	/* The location on the server database of where substantive instances
	 * of this class will be stored.
	 */
	std::string _instancepath;


//	std::vector<Entity> _children;

	/* Returns a string representation of this instance such that it can be
	 * restored using "eval()"
	 */
	virtual std::string _E_repr();

	/* Turns this instance of Entity into a copy of the instance stored using
	 * "repr()"
	 */
	virtual void _E_eval(std::string);



};

} /* namespace sheila */

#endif /* ENTITY_ENTITY_H_ */
