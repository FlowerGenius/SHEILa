//SHEILa======================================================================
// Name        : Runtime.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 27, 2018
// Modified    :
//============================================================================

#ifndef RUNTIME_RUNTIME_H_
#define RUNTIME_RUNTIME_H_

#include <stdint.h>

namespace sheila {
namespace runtime {

class Runtime {
public:
	Runtime();
	virtual ~Runtime();

private:
	static uintmax_t instanceId;

};

} /* namespace runtime */
} /* namespace sheila */

#endif /* RUNTIME_RUNTIME_H_ */
