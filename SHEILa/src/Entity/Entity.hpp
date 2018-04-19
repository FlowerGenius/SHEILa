//SHEILa========================================================================
// Name        : Entity.hpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Mar 29, 2018
// Modified    :
//==============================================================================

#ifndef ENTITY_ENTITY_HPP_
#define ENTITY_ENTITY_HPP_

#include <string>
#include <vector>
#include <typeinfo>
#include <ctime>

#include "../symbols.inc"
#include "../Cpp/language.inc"
#include "../ProgrammingLanguage/C/language.inc"

namespace sheila {

/*
 * An entity is a special data type, it represents the pair of files
 * required to build the class of the same name.
 */
template<class _Tp>
class Entity : private cpp::CppObject<_Tp> {
/*
 * All write operations are applied to the class and to it's XML file
 * All read operations access the XML file
 */
public:

	Entity() {
		instance_id = 0;
	}

	virtual ~Entity() {
		;
	}


protected:

	uintmax_t                instance_id;
	std::vector<std::string> instance_name; //line 1 of instance file
	std::vector<std::string> instance_desc; //line 2 of instance file
	std::vector<std::string> instance_picture_paths;
	std::vector<std::string> instance_video_paths;
	std::vector<std::string> instance_sound_paths;
	std::vector<std::string> instance_document_paths;
	std::vector<std::string> instance_program_paths;
	std::vector<long double> instance_emotion_values;
	std::vector<std::string> instance_cv_filters;

	virtual std::string _E_repr() {
		;
	}

	virtual void _E_eval(std::string) {
		;
	}

#if (BUILD_FOR_SHEILA_DAEMON == 1)
	static std::time_t								this_object_accessed;
	static std::vector<long double>					this_object_emotion_values;
	static std::vector<std::string>					this_object_cv_filters;
	static std::vector<cpp::CppClass_advanced> 		this_object_parents;
	static std::vector<cpp::CppClass_advanced> 		this_object_children;
	static std::vector<_Tp > 						this_object_entities;
#endif

};

} /* namespace sheila */

#endif /* ENTITY_ENTITY_HPP_ */
