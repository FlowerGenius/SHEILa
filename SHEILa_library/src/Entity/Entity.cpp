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

#include "Entity/Entity.hpp"


namespace sheila {

#if (BUILD_FOR_SHEILA_DAEMON == 1)

#ifdef ENTITY_TEMPLATE
//template<class _Te>
//std::vector<_Te>		 				Entity<_Te>::this_object_entities = {};
#endif

#ifdef ENTITY_TEMPLATE
template<class _Te>
std::time_t								Entity<_Te>::this_object_accessed;
#endif

#ifdef ENTITY_TEMPLATE
template<class _Te>
std::vector<long double>				Entity<_Te>::this_object_emotion_values = {};
#endif

#ifdef ENTITY_TEMPLATE
template<class _Te>
std::vector<std::string>				Entity<_Te>::this_object_cv_filters = {};
#endif

#ifdef ENTITY_TEMPLATE
template<class _Te>
std::vector<Cpp::Structure::Files::OutFiles::Object_base> 	Entity<_Te>::this_object_parents = {};
#endif

#ifdef ENTITY_TEMPLATE
template<class _Te>
std::vector<Cpp::Structure::Files::OutFiles::Object_base> 	Entity<_Te>::this_object_children = {};
#endif

#endif

#ifndef ENTITY_TEMPLATE
Entity::Entity() {

}

Entity::~Entity() {

}
#endif

} /* namespace sheila */


