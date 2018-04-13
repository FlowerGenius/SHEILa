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

std::vector<long double>			Entity::_emotion_values_ = {
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0
};
std::vector<std::string> 			Entity::_name_ = {
		"Entity"
};
std::vector<std::string> 			Entity::_desc_ = {
		"A thing that has a name, and can be described"
};
std::vector<Entity> 				Entity::_children_ = {

};
std::vector<std::string>			Entity::_cv_filters_ = {

};
std::vector<Entity> 				Entity::_parents_ = {

};

std::time_t							Entity::_time_created_;
std::time_t							Entity::_time_accessed_;
std::time_t							Entity::_time_modified_;
std::vector<cpp::CppMemberFunction>	Entity::_member_functions_;
std::vector<cpp::CppDataMember> 	Entity::_data_members_;

std::vector<Entity> Entity::entities;

int Entity::createNewEntity(
		std::vector<std::string> names,
		std::vector<std::string> descs,
		std::vector<std::string> cvinf
		) {

	return 0;
}

Entity::Entity() {
	_name 				= &Entity::_name_;
	_desc 				= &Entity::_desc_;
	_parents 			= &Entity::_parents_;
	_children 			= &Entity::_children_;
	_member_functions 	= &Entity::_member_functions_;
	_data_members 		= &Entity::_data_members_;
	_time_created 		= &Entity::_time_created_;
	_time_modified 		= &Entity::_time_modified_;
	_time_accessed 		= &Entity::_time_accessed_;
	_cv_filters 		= &Entity::_cv_filters_;
	_emotion_values 	= &Entity::_emotion_values_;

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
	for (std::vector<Entity>::iterator it = _parents->begin();
			it != _parents->end(); ++it) {

		if ((*it)._getName() == e._getName()) {
			return true;
		} else if ((*it).hasParent(e)) {
			return true;
		}
	}

	return false;
}

bool Entity::hasChild(Entity e) {
	for (std::vector<Entity>::iterator it = _children->begin();
			it != _children->end(); ++it) {
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
	return (*_parents);
}

const std::vector<Entity>& Entity::_getChildren() const {
	return (*_children);
}

/* Preprocessor Cpp Standard Library Includes */

bool Entity::hasInclude(cpp::CppStandardHeaderFile) {
	return true;
}

int Entity::addInclude(cpp::CppStandardHeaderFile) {
	return 0;
}

int Entity::removeInclude(cpp::CppStandardHeaderFile) {
	return 0;
}

const std::vector<cpp::CppStandardHeaderFile>& Entity::_getCppIncludes() const {
	return (*_cpp_include_files);
}

/* Preprocessor C Standard Library Includes */

bool Entity::hasInclude(c::CStandardHeaderFile) {
	return true;
}

int Entity::addInclude(c::CStandardHeaderFile) {
	return 0;
}

int Entity::removeInclude(c::CStandardHeaderFile) {
	return 0;
}

const std::vector<c::CStandardHeaderFile>& Entity::_getCIncludes() const {
	return (*_c_include_files);
}

/* Preprocessor Included files */

bool Entity::hasInclude(cpp::CppHeaderFile) {
	return true;
}

int Entity::addInclude(cpp::CppHeaderFile) {
	return 0;
}

int Entity::removeInclude(cpp::CppHeaderFile) {
	return 0;
}

const std::vector<cpp::CppHeaderFile>& Entity::_getIncludes() const {
	return (*_include_files);
}

/* Preprocessor Macros */

bool Entity::hasMacro(cpp::CppMacro) {
	return true;
}

int Entity::addMacro(cpp::CppMacro) {
	return 0;
}

int Entity::editMacro(cpp::CppMacro) {
	return 0;
}

int Entity::removeMacro(cpp::CppMacro) {
	return 0;
}

const std::vector<cpp::CppMacro>& Entity::_getMacros() const {
	return (*_macros);
}

/* Preprocessor Symbols */

bool Entity::hasSymbol(cpp::CppSymbol) {
	return true;
}

int Entity::addSymbol(cpp::CppSymbol) {
	return 0;
}

int Entity::editSymbol(cpp::CppSymbol) {
	return 0;
}

int Entity::removeSymbol(cpp::CppSymbol) {
	return 0;
}

const std::vector<cpp::CppSymbol>& Entity::_getSymbols() const {
	return (*_symbols);
}


/* Constructors */

bool Entity::hasConstructor(cpp::CppConstructor) {
	return true;
}

int Entity::addConstructor(cpp::CppConstructor) {
	return 0;
}

int Entity::editConstructor(cpp::CppConstructor) {
	return 0;
}

int Entity::removeConstructor(cpp::CppConstructor) {
	return 0;
}

const std::vector<cpp::CppConstructor>& Entity::_getConstructors() const {
	return (*_constructors);
}


/* Destructors */


bool Entity::hasDestructor(cpp::CppDestructor) {
	return true;
}

int Entity::addDestructor(cpp::CppDestructor) {
	return 0;
}

int Entity::editDestructor(cpp::CppDestructor) {
	return 0;
}

int Entity::removeDestructor(cpp::CppDestructor) {
	return 0;
}

const std::vector<cpp::CppDestructor>& Entity::_getDestructors() const {
	return (*_destructors);
}

/* Member Functions */

bool Entity::hasMemberFunction(cpp::CppMemberFunction f) {
	for (std::vector<cpp::CppMemberFunction>::iterator it = _member_functions->begin();
			it != _member_functions->end(); ++it) {

		if ((*it).getIdentifier() == f.getIdentifier()) {
			return true;
		}
	}

	return false;
}

int Entity::addMemberFunction(cpp::CppMemberFunction f) {
	return 0;
}

int Entity::editMemberFunction(cpp::CppMemberFunction f) {
	return 0;
}

int Entity::removeMemberFunction(cpp::CppMemberFunction f){
	return 0;
}

const std::vector<cpp::CppMemberFunction>& Entity::_getMemberFunctions() const {
	return (*_member_functions);
}

/* Data Members */

bool Entity::hasDataMember(cpp::CppDataMember m) {
	for (std::vector<cpp::CppDataMember>::iterator it = _data_members->begin();
			it != _data_members->end(); ++it) {

		if ((*it).getIdentifier() == m.getIdentifier()) {
			return true;
		}
	}

	return false;
}

int Entity::addDataMember(cpp::CppDataMember m) {
	return 0;
}

int Entity::editDataMember(cpp::CppDataMember m) {
	return 0;
}

int Entity::removeDataMember(cpp::CppDataMember m) {
	return 0;
}

const std::vector<cpp::CppDataMember>& Entity::_getDataMembers() const {
	return (*_data_members);
}

/* Meta */

const std::vector<std::string>& Entity::_getName() const {
	return (*_name);
}

const std::vector<std::string>& Entity::_getDesc() const {
	return (*_desc);
}

uintmax_t Entity::_getInstanceID() {
	return instance_id;
}

std::string Entity::_getClassPath() {
	return std::string(SHEILA_WORKSPACE_DIR).append("/SHEILa/Entity/").append(_getName()[0]);
}

std::string Entity::_getInstancePath() {
	return std::string(SHEILA_ENTITY_DIR).append("/").append(_getName()[0]);
}



Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */


