//SHEILa========================================================================
// Name        : Manufacturer.cpp
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 8, 2018
// Modified    :
//==============================================================================

#include "Manufacturer.hpp"

namespace sheila {

std::vector<long double>			Manufacturer::_emotion_values_ = {
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0
};
std::vector<std::string> 			Manufacturer::_name_ = {
		"Manufacturer"
};
std::vector<std::string> 			Manufacturer::_desc_ = {
		"a company or collective that manufactures goods"
};
std::vector<Entity> 				Manufacturer::_children_ = {

};
std::vector<std::string>			Manufacturer::_cv_filters_ = {

};
std::vector<Entity> 				Manufacturer::_parents_ = {
		Entity()
};

std::time_t							Manufacturer::_time_created_;
std::time_t							Manufacturer::_time_accessed_;
std::time_t							Manufacturer::_time_modified_;
std::vector<cpp::CppMemberFunction>	Manufacturer::_member_functions_;
std::vector<cpp::CppDataMember> 	Manufacturer::_data_members_;

std::vector<Manufacturer> Manufacturer::manufacturers;

Manufacturer::Manufacturer() {
	_name = &Manufacturer::_name_;
	_desc = &Manufacturer::_desc_;

	name = "unknown";
}

Manufacturer::~Manufacturer() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */
