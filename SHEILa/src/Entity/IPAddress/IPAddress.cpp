//SHEILa======================================================================
// Name        : IPAddress.cpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 27, 2018
// Modified    :
//============================================================================

#include "IPAddress.h"

namespace sheila {

std::vector<long double>			IPAddress::_emotion_values_ = {
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0
};
std::vector<std::string> 			IPAddress::_name_ = {
		"IPv4"
};
std::vector<std::string> 			IPAddress::_desc_ = {
		"A protocol for routing network traffic"
};
std::vector<Entity> 				IPAddress::_children_ = {

};
std::vector<std::string>			IPAddress::_cv_filters_ = {

};
std::vector<Entity> 				IPAddress::_parents_ = {
		Entity()
};

std::time_t							IPAddress::_time_created_;
std::time_t							IPAddress::_time_accessed_;
std::time_t							IPAddress::_time_modified_;
std::vector<cpp::CppMemberFunction>	IPAddress::_member_functions_;
std::vector<cpp::CppDataMember> 	IPAddress::_data_members_;

std::vector<IPAddress> IPAddress::ip_addresses;

IPAddress::IPAddress() {
	_name = &IPAddress::_name_;
	_desc = &IPAddress::_desc_;
}

IPAddress::~IPAddress() {
	// TODO Auto-generated destructor stub
}


} /* namespace sheila */
