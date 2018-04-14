//SHEILa========================================================================
// Name        : InstructionSetArchitecture.cpp
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 8, 2018
// Modified    :
//==============================================================================

#include "InstructionSetArchitecture.hpp"

namespace sheila {

std::vector<long double>			InstructionSetArchitecture::_emotion_values_ = {
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0
};
std::vector<std::string> 			InstructionSetArchitecture::_name_ = {
		"InstructionSetArchitecture",
		"ISA"
};
std::vector<std::string> 			InstructionSetArchitecture::_desc_ = {
		"an abstract model of a computer"
};
std::vector<Entity> 				InstructionSetArchitecture::_children_ = {

};
std::vector<std::string>			InstructionSetArchitecture::_cv_filters_ = {

};
std::vector<Entity> 				InstructionSetArchitecture::_parents_ = {
		Entity()
};

std::time_t							InstructionSetArchitecture::_time_created_;
std::time_t							InstructionSetArchitecture::_time_accessed_;
std::time_t							InstructionSetArchitecture::_time_modified_;
std::vector<cpp::CppMemberFunction>	InstructionSetArchitecture::_member_functions_;
std::vector<cpp::CppDataMember> 	InstructionSetArchitecture::_data_members_;

std::vector<InstructionSetArchitecture> InstructionSetArchitecture::instruction_set_architectures;

InstructionSetArchitecture::InstructionSetArchitecture() {
	_name = &InstructionSetArchitecture::_name_;
	_desc = &InstructionSetArchitecture::_desc_;
	manufacturer = {Manufacturer()};
}

InstructionSetArchitecture::~InstructionSetArchitecture() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */
