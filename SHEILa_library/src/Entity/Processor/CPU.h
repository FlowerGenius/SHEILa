//SHEILa======================================================================
// Name        : CPU.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 28, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_PROCESSOR_CPU_H_
#define ENTITY_PROCESSOR_CPU_H_

#include "Processor.hpp"

namespace sheila {
namespace processor {

class CPU: public Processor {
public:
	CPU();
	virtual ~CPU();
};

} /* namespace processor */
} /* namespace sheila */

#endif /* ENTITY_PROCESSOR_CPU_H_ */
