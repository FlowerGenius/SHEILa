//SHEILa========================================================================
// Name        : InstructionSetArchitecture.hpp
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 8, 2018
// Modified    :
//==============================================================================

#ifndef ENTITY_INSTRUCTIONSETARCHITECTURE_INSTRUCTIONSETARCHITECTURE_HPP_
#define ENTITY_INSTRUCTIONSETARCHITECTURE_INSTRUCTIONSETARCHITECTURE_HPP_

#include "../Entity.hpp"
#include "../Manufacturer/Manufacturer.hpp"

namespace sheila {

class InstructionSetArchitecture: public Entity {
public:

	static std::vector<InstructionSetArchitecture> instruction_set_architectures;

	InstructionSetArchitecture();
	virtual ~InstructionSetArchitecture();
protected:

	std::vector<Manufacturer> manufacturer;


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

#endif /* ENTITY_INSTRUCTIONSETARCHITECTURE_INSTRUCTIONSETARCHITECTURE_HPP_ */
