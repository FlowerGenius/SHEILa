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

class InstructionSetArchitecture: public Entity<InstructionSetArchitecture> {
public:

	static std::vector<InstructionSetArchitecture> instruction_set_architectures;

	InstructionSetArchitecture();
	virtual ~InstructionSetArchitecture();
protected:

	std::vector<Manufacturer> manufacturer;


private:


};

} /* namespace sheila */

#endif /* ENTITY_INSTRUCTIONSETARCHITECTURE_INSTRUCTIONSETARCHITECTURE_HPP_ */
