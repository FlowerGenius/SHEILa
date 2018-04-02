//SHEILa======================================================================
// Name        : Entity.cpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : A thing that has a name, and can be described
// Module	   : SHEILa
// Created     : Mar 29, 2018
// Modified    :
//============================================================================

#include <Entity/Entity.h>


namespace sheila {

std::vector<Entity> Entity::entities;

Entity::Entity() {
	_name = {"Entity"};
	_desc = {"A thing that has a name, and can be described"};
}

void Entity::_E_eval(std::string){

}


std::string Entity::_E_repr(){

}

const std::vector<std::string>& Entity::_getName() const {
	return _name;
}

const std::vector<std::string>& Entity::_getDesc() const {
	return _desc;
}

const std::vector<Entity>& Entity::_getParents() const {
	return _parents;
}

const std::vector<Entity>& Entity::_getChildren() const {
	return _children;
}





Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */
