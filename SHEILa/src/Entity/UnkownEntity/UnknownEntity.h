//SHEILa========================================================================
// Name        : UnknownEntity.h
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 12, 2018
// Modified    :
//==============================================================================

#ifndef SRC_ENTITY_UNKOWNENTITY_UNKNOWNENTITY_H_
#define SRC_ENTITY_UNKOWNENTITY_UNKNOWNENTITY_H_

#include "../Entity.h"

namespace sheila {

class UnknownEntity: public Entity {
public:
	UnknownEntity();
	virtual ~UnknownEntity();
protected:

	static std::time_t							_time_created;
	static std::time_t							_time_accessed;
	static std::time_t							_time_modified;
	static std::vector<long double>				_emotion_values;
	static std::vector<std::string> 			_name;
	static std::vector<std::string> 			_desc;
	static std::vector<std::string>				_cv_filters;
	static std::vector<Entity> 					_parents;
	static std::vector<Entity> 					_children;
	static std::vector<cpp::CppMemberFunction> 	_member_functions;
	static std::vector<cpp::CppDataMember> 		_data_members;
};

} /* namespace sheila */

#endif /* SRC_ENTITY_UNKOWNENTITY_UNKNOWNENTITY_H_ */
