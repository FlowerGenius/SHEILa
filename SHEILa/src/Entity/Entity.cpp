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

const std::string Entity::_name = "Entity";

const std::string Entity::_desc = "A thing that has a name, and can be described";

Entity::Entity() {
	// TODO Auto-generated constructor stub

}

std::string Entity::repr(){

}

void Entity::eval(std::string){

}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */
