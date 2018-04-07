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

//==ENTITYDATAMEMBER==========================================================

EntityDataMember::EntityDataMember() {

}

EntityDataMember::~EntityDataMember() {

}

//==ENTITYMEMBERFUNCTION======================================================

EntityMemberFunction::EntityMemberFunction() {

}

EntityMemberFunction::~EntityMemberFunction() {

}

//==ENTITYDEFFILE=============================================================

EntityDefFile::EntityDefFile() {

}

int EntityDefFile::validate() {

}

EntityDefFile::~EntityDefFile() {

}

//==ENTITYHEADERFILE==========================================================

EntityHeaderFile::EntityHeaderFile() {

}

int EntityHeaderFile::validate() {

}

EntityHeaderFile::~EntityHeaderFile() {

}

//==ENTITYSOURCEFILE==========================================================

EntitySourceFile::EntitySourceFile() {

}

int EntitySourceFile::validate() {

}

EntitySourceFile::~EntitySourceFile() {

}

//==ENTITY====================================================================

std::vector<Entity> Entity::entities;

void Entity::buildEntity(std::string name, std::string desc){
	EntitySourceFile cpp;
	EntityHeaderFile inc;

	//TODO pass the necessary arguments to build the class


}

Entity::Entity() {
	_name = {"Entity"};
	_desc = {"A thing that has a name, and can be described"};
	_parents = {};
	_children = {};
}

/* Entity Operations */

void Entity::_E_eval(std::string){

}


std::string Entity::_E_repr(){

}

/* Inheritance */

bool Entity::hasParent(Entity e) {
	for (std::vector<Entity>::iterator it = _parents.begin();
			it != _parents.end(); ++it) {

		if ((*it)._getName() == e._getName()) {
			return true;
		} else if ((*it).hasParent(e)) {
			return true;
		}
	}

	return false;
}

bool Entity::hasChild(Entity e) {
	for (std::vector<Entity>::iterator it = _children.begin();
			it != _children.end(); ++it) {
		if ((*it)._getName() == e._getName()) {
			return true;
		} else if ((*it).hasChild(e)){
			return true;
		}
	}

	return false;
}

int Entity::addParent(Entity e, bool _virtual, cpp::AccessLevel _access) {

}

int Entity::addChild(Entity e, bool _virtual, cpp::AccessLevel _access) {

}

int Entity::editParent(Entity e, bool _virtual, cpp::AccessLevel _access) {

}

int Entity::editChild(Entity e, bool _virtual, cpp::AccessLevel _access) {

}

int Entity::removeParent(Entity e) {

}

int Entity::removeChild(Entity e) {

}

const std::vector<Entity>& Entity::_getParents() const {
	return _parents;
}

const std::vector<Entity>& Entity::_getChildren() const {
	return _children;
}

/* Member Functions */

bool Entity::hasMemberFunction(EntityMemberFunction f) {

}

int Entity::addMemberFunction(EntityMemberFunction f) {

}

int Entity::editMemberFunction(EntityMemberFunction f) {

}

int Entity::removeMemberFunction(EntityMemberFunction f){

}

const std::vector<EntityMemberFunction>& Entity::_getMemberFunctions() const {
	return _member_functions;
}

/* Data Members */

bool Entity::hasDataMember(EntityDataMember m) {

}

int Entity::addDataMember(EntityDataMember m) {

}

int Entity::editDataMember(EntityDataMember m) {

}

int Entity::removeDataMember(EntityDataMember m) {

}

const std::vector<EntityDataMember>& Entity::_getDataMembers() const {
	return _data_members;
}

/* Meta */

const std::vector<std::string>& Entity::_getName() const {
	return _name;
}

const std::vector<std::string>& Entity::_getDesc() const {
	return _desc;
}

std::string Entity::_getClasspath() {
	return std::string(SHEILA_WORKSPACE_DIR).append("/SHEILa/Entity/").append(_name[0]);
}

std::string Entity::_getInstancepath() {
	return std::string(SHEILA_MEM_DIR).append("/").append(_name[0]);
}



Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */


