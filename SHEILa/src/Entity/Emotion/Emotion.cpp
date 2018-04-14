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

#include "Emotion.hpp"

namespace sheila {

std::vector<long double>			Emotion::_emotion_values_ = {
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0
};
std::vector<std::string> 			Emotion::_name_ = {
		"Emotion"
};
std::vector<std::string> 			Emotion::_desc_ = {
		""
};
std::vector<Entity> 				Emotion::_children_ = {

};
std::vector<std::string>			Emotion::_cv_filters_ = {

};
std::vector<Entity> 				Emotion::_parents_ = {
		Entity()
};

std::time_t							Emotion::_time_created_;
std::time_t							Emotion::_time_accessed_;
std::time_t							Emotion::_time_modified_;
std::vector<cpp::CppMemberFunction>	Emotion::_member_functions_;
std::vector<cpp::CppDataMember> 	Emotion::_data_members_;

Emotion::Emotion() {
	_name 				= &Emotion::_name_;
	_desc 				= &Emotion::_desc_;
	_parents 			= &Emotion::_parents_;
	_children 			= &Emotion::_children_;
	_member_functions 	= &Emotion::_member_functions_;
	_data_members 		= &Emotion::_data_members_;
	_time_created 		= &Emotion::_time_created_;
	_time_modified 		= &Emotion::_time_modified_;
	_time_accessed 		= &Emotion::_time_accessed_;
	_cv_filters 		= &Emotion::_cv_filters_;
	_emotion_values 	= &Emotion::_emotion_values_;

	strength = 0;
}

Emotion::Emotion(long double strength) {
	_name 				= &Emotion::_name_;
	_desc 				= &Emotion::_desc_;
	_parents 			= &Emotion::_parents_;
	_children 			= &Emotion::_children_;
	_member_functions 	= &Emotion::_member_functions_;
	_data_members 		= &Emotion::_data_members_;
	_time_created 		= &Emotion::_time_created_;
	_time_modified 		= &Emotion::_time_modified_;
	_time_accessed 		= &Emotion::_time_accessed_;
	_cv_filters 		= &Emotion::_cv_filters_;
	_emotion_values 	= &Emotion::_emotion_values_;


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
