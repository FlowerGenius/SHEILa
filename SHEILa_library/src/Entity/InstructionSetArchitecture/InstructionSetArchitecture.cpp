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

#include "Entity/InstructionSetArchitecture.hpp"

namespace sheila {


std::vector<InstructionSetArchitecture> InstructionSetArchitecture::instruction_set_architectures;

InstructionSetArchitecture::InstructionSetArchitecture() {

	manufacturer = {Manufacturer()};
}

InstructionSetArchitecture::~InstructionSetArchitecture() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */
