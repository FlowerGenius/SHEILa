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

#ifndef ENTITY_PROCESSOR_GPU_H_
#define ENTITY_PROCESSOR_GPU_H_

#include <Entity/Processor/Processor.h>

namespace sheila {
namespace processor {

class GPU: public Processor {
public:
	GPU();
	virtual ~GPU();
};

} /* namespace processor */
} /* namespace sheila */

#endif /* ENTITY_PROCESSOR_GPU_H_ */
