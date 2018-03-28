//SHEILa======================================================================
// Name        : GPU.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 28, 2018
// Modified    :
//============================================================================

#ifndef PROCESSOR_GPU_H_
#define PROCESSOR_GPU_H_

#include <Processor/Processor.h>

namespace sheila {
namespace processor {

class GPU: public Processor {
public:
	GPU();
	virtual ~GPU();
};

} /* namespace processor */
} /* namespace sheila */

#endif /* PROCESSOR_GPU_H_ */
