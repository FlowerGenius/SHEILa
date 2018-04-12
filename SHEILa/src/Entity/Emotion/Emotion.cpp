//SHEILa======================================================================
// Name        : Emotion.cpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 19, 2018
// Modified    :
//============================================================================

#include "Emotion.h"

namespace sheila {

std::vector<long double>			Emotion::_emotion_values = {
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0
};
std::vector<std::string> 			Emotion::_name = {
		"Emotion"
};
std::vector<std::string> 			Emotion::_desc = {
		""
};
std::vector<Entity> 				Emotion::_children = {

};
std::vector<std::string>			Emotion::_cv_filters = {

};
std::vector<Entity> 				Emotion::_parents = {
		Entity()
};

std::time_t							Emotion::_time_created;
std::time_t							Emotion::_time_accessed;
std::time_t							Emotion::_time_modified;
std::vector<cpp::CppMemberFunction>	Emotion::_member_functions;
std::vector<cpp::CppDataMember> 	Emotion::_data_members;

Emotion::Emotion() {
	_name = {"Emotion"};
	_desc.push_back("");

	strength = 0;
}

Emotion::Emotion(long double strength) {
	_name = {"Emotion"};
	_desc.push_back("");


	this->strength = strength;
}

void Emotion::setStrength(long double strength) {

	if(strength >= double(-100.0L) && strength <= double(100.0L)){

	}
	this->strength = strength;
}

long double Emotion::getStrength(void) {
	return strength;
}


Emotion::~Emotion() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */
