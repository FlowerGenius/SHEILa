//SHEILa======================================================================
// Name        : IPv6.cpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 31, 2018
// Modified    :
//============================================================================

#include "IPv6.h"

namespace sheila {

std::vector<long double>			IPv6::_emotion_values_ = {
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0
};
std::vector<std::string> 			IPv6::_name_ = {
		"IPv6"
};
std::vector<std::string> 			IPv6::_desc_ = {
		"A protocol for routing network traffic"
};
std::vector<Entity> 				IPv6::_children_ = {

};
std::vector<std::string>			IPv6::_cv_filters_ = {

};
std::vector<Entity> 				IPv6::_parents_ = {
		Entity(),
		IPAddress()
};

std::time_t							IPv6::_time_created_;
std::time_t							IPv6::_time_accessed_;
std::time_t							IPv6::_time_modified_;
std::vector<cpp::CppMemberFunction>	IPv6::_member_functions_;
std::vector<cpp::CppDataMember> 	IPv6::_data_members_;

IPv6::IPv6(){
	_name = &IPv6::_name_;
	_desc = &IPv6::_desc_;
}

std::string IPv6::toString(){
	return "";
}

IPv6::~IPv6(){

}

} /* namespace sheila */
