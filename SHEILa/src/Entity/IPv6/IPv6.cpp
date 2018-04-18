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

#include "IPv6.hpp"

namespace sheila {

template<>
std::vector<long double>			Entity<IPv6_T>::_emotion_values_ = {
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0
};

template<>
std::vector<std::string> 			Entity<IPv6_T>::_name_ = {
		"IPv6"
};

template<>
std::vector<std::string> 			Entity<IPv6_T>::_desc_ = {
		"A protocol for routing network traffic"
};

template<>
std::vector<cpp::CppClass_advanced> Entity<IPv6_T>::_parents_ = {
		IPAddress()
};


IPv6::IPv6() {

}

std::string IPv6::toString(){
	return "";
}

IPv6::~IPv6(){

}

} /* namespace sheila */
