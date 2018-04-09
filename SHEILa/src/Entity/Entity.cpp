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

#include "Entity.h"


namespace sheila {

//==ENTITYDATAMEMBER==========================================================

EntityDataMember::EntityDataMember() {

}

const std::string& EntityDataMember::getIdentifier() const {
	return identifier;
}

void EntityDataMember::setIdentifier(const std::string& identifier) {
	this->identifier = identifier;
}

EntityDataMember::~EntityDataMember() {

}

//==ENTITYMEMBERFUNCTION======================================================

EntityMemberFunction::EntityMemberFunction() {

}

const std::string& EntityMemberFunction::getIdentifier() const {
	return identifier;
}

void EntityMemberFunction::setIdentifier(const std::string& identifier) {
	this->identifier = identifier;
}

EntityMemberFunction::~EntityMemberFunction() {

}

//==ENTITYDEFFILE=============================================================

EntityDefFile::EntityDefFile() {

}

int EntityDefFile::validate() {
	return 0;
}

EntityDefFile::~EntityDefFile() {

}

//==ENTITYHEADERFILE==========================================================

EntityHeaderFile::EntityHeaderFile() {

}

int EntityHeaderFile::validate() {
	return 0;
}

EntityHeaderFile::~EntityHeaderFile() {

}

//==ENTITYSOURCEFILE==========================================================

EntitySourceFile::EntitySourceFile() {

}

int EntitySourceFile::validate() {
	return 0;
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
	instance_id = 0;
}

/* Entity Operations */

void Entity::_E_eval(std::string){

}


std::string Entity::_E_repr(){
	return "";
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
	return 0;
}

int Entity::addChild(Entity e, bool _virtual, cpp::AccessLevel _access) {
	return 0;
}

int Entity::editParent(Entity e, bool _virtual, cpp::AccessLevel _access) {
	return 0;
}

int Entity::editChild(Entity e, bool _virtual, cpp::AccessLevel _access) {
	return 0;
}

int Entity::removeParent(Entity e) {
	return 0;
}

int Entity::removeChild(Entity e) {
	return 0;
}

const std::vector<Entity>& Entity::_getParents() const {
	return _parents;
}

const std::vector<Entity>& Entity::_getChildren() const {
	return _children;
}

/* Member Functions */

bool Entity::hasMemberFunction(EntityMemberFunction f) {
	for (std::vector<EntityMemberFunction>::iterator it = _member_functions.begin();
			it != _member_functions.end(); ++it) {

		if ((*it).getIdentifier() == f.getIdentifier()) {
			return true;
		}
	}

	return false;
}

int Entity::addMemberFunction(EntityMemberFunction f) {
	return 0;
}

int Entity::editMemberFunction(EntityMemberFunction f) {
	return 0;
}

int Entity::removeMemberFunction(EntityMemberFunction f){
	return 0;
}

const std::vector<EntityMemberFunction>& Entity::_getMemberFunctions() const {
	return _member_functions;
}

/* Data Members */

bool Entity::hasDataMember(EntityDataMember m) {
	for (std::vector<EntityDataMember>::iterator it = _data_members.begin();
			it != _data_members.end(); ++it) {

		if ((*it).getIdentifier() == m.getIdentifier()) {
			return true;
		}
	}

	return false;
}

int Entity::addDataMember(EntityDataMember m) {
	return 0;
}

int Entity::editDataMember(EntityDataMember m) {
	return 0;
}

int Entity::removeDataMember(EntityDataMember m) {
	return 0;
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

uintmax_t Entity::_getInstanceID() {
	return instance_id;
}

std::string Entity::_getClassPath() {
	return std::string(SHEILA_WORKSPACE_DIR).append("/SHEILa/Entity/").append(_name[0]);
}

std::string Entity::_getInstancePath() {
	return std::string(SHEILA_ENTITY_DIR).append("/").append(_name[0]);
}



Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */


