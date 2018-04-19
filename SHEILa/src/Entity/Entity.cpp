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

#include "Entity.hpp"


namespace sheila {

#if (BUILD_FOR_SHEILA_DAEMON == 1)
template<class _Te>
std::vector<_Te>		 				Entity<_Te>::this_object_entities;

template<class _Te>
std::time_t								Entity<_Te>::this_object_accessed;

template<class _Te>
std::vector<long double>				Entity<_Te>::this_object_emotion_values;

template<class _Te>
std::vector<std::string>				Entity<_Te>::this_object_cv_filters;

template<class _Te>
std::vector<cpp::CppClass_advanced> 	Entity<_Te>::this_object_parents;

template<class _Te>
std::vector<cpp::CppClass_advanced> 	Entity<_Te>::this_object_children;
#endif

//std::vector<Entity> Entity::entities;
//
//int Entity::createNewEntity(
//		std::vector<std::string> names,
//		std::vector<std::string> descs,
//		std::vector<std::string> cvinf
//		) {
//
//	return 0;
//}
//
//Entity::Entity() {
//	_name 				= &Entity::_name_;
//	_desc 				= &Entity::_desc_;
//	_parents 			= &Entity::_parents_;
//	_children 			= &Entity::_children_;
//	_member_functions 	= &Entity::_member_functions_;
//	_data_members 		= &Entity::_data_members_;
//	_time_created 		= &Entity::_time_created_;
//	_time_modified 		= &Entity::_time_modified_;
//	_time_accessed 		= &Entity::_time_accessed_;
//	_cv_filters 		= &Entity::_cv_filters_;
//	_emotion_values 	= &Entity::_emotion_values_;
//
//	instance_id = 0;
//}

template<class _Tp>
Entity<_Tp>::Entity() {
	instance_id = 0;
}

template<class _Tp>
Entity<_Tp>::~Entity() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */


