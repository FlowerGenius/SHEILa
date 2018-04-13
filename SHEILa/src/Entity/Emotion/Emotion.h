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

	Emotion();
	Emotion(long double strength);
	virtual ~Emotion();

	void setStrength(long double strength);
	long double getStrength(void);



protected:

	long double strength;

private:

	static std::time_t							_time_created_;
	static std::time_t							_time_accessed_;
	static std::time_t							_time_modified_;
	static std::vector<long double>				_emotion_values_;
	static std::vector<std::string> 			_name_;
	static std::vector<std::string> 			_desc_;
	static std::vector<std::string>				_cv_filters_;
	static std::vector<Entity> 					_parents_;
	static std::vector<Entity> 					_children_;
	static std::vector<cpp::CppMemberFunction> 	_member_functions_;
	static std::vector<cpp::CppDataMember> 		_data_members_;

};


} /* namespace sheila */

#endif /* ENTITY_EMOTION_EMOTION_H_ */
