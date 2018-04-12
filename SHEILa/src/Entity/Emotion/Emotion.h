//SHEILa======================================================================
// Name        : Emotion.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 19, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_EMOTION_EMOTION_H_
#define ENTITY_EMOTION_EMOTION_H_

#include <stdint.h>
#include <string>
#include <vector>
#include "../Entity.h"

namespace sheila {

class Emotion : public Entity {
public:

	static std::vector<Entity> entities;

	static bool hasParent(Entity);

	Emotion();
	Emotion(long double strength);
	virtual ~Emotion();

	void setStrength(long double strength);
	long double getStrength(void);

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

	long double strength;

};


} /* namespace sheila */

#endif /* ENTITY_EMOTION_EMOTION_H_ */
