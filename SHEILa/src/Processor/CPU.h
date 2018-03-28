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

#ifndef PROCESSOR_CPU_H_
#define PROCESSOR_CPU_H_

#include <Processor/Processor.h>

namespace sheila {
namespace processor {

class CPU: public Processor {
public:
	CPU();
	virtual ~CPU();
};

} /* namespace processor */
} /* namespace sheila */

#endif /* PROCESSOR_CPU_H_ */
