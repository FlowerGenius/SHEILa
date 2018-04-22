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
std::vector<cpp::Cpp::ClassType> 	Entity<_Te>::this_object_parents;

template<class _Te>
std::vector<cpp::Cpp::ClassType> 	Entity<_Te>::this_object_children;
#endif


} /* namespace sheila */


