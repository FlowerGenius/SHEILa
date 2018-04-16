//SHEILa======================================================================
// Name        : OperatingSystem.hpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 28, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_OPERATINGSYSTEM_OPERATINGSYSTEM_HPP_
#define ENTITY_OPERATINGSYSTEM_OPERATINGSYSTEM_HPP_

#include "../Entity.hpp"

namespace sheila {

class OperatingSystem : public SheilaClass<OPERATING_SYSTEM_T> {
public:
	OperatingSystem();
	virtual ~OperatingSystem();
};

} /* namespace sheila */

#endif /* ENTITY_OPERATINGSYSTEM_OPERATINGSYSTEM_HPP_ */
