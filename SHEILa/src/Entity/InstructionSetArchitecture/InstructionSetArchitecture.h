//SHEILa========================================================================
// Name        : InstructionSetArchitecture.h
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 8, 2018
// Modified    :
//==============================================================================

#ifndef ENTITY_INSTRUCTIONSETARCHITECTURE_INSTRUCTIONSETARCHITECTURE_H_
#define ENTITY_INSTRUCTIONSETARCHITECTURE_INSTRUCTIONSETARCHITECTURE_H_

#include "../Entity.h"
#include "../Manufacturer/Manufacturer.h"

namespace sheila {

class InstructionSetArchitecture: public Entity {
public:

	static std::vector<InstructionSetArchitecture> instruction_set_architectures;

	InstructionSetArchitecture();
	virtual ~InstructionSetArchitecture();
private:
	std::vector<Manufacturer> manufacturer;
};

} /* namespace sheila */

#endif /* ENTITY_INSTRUCTIONSETARCHITECTURE_INSTRUCTIONSETARCHITECTURE_H_ */
