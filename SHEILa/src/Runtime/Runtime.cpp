//SHEILa======================================================================
// Name        : Runtime.cpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 27, 2018
// Modified    :
//============================================================================

#include "Runtime.h"

namespace sheila {
namespace runtime {

uintmax_t Runtime::instanceId;

Runtime::Runtime() {
	instanceId = instanceId + 1;
	if (instanceId > 1){
		//TODO Throw an error if there is already a server class
	}
}

Runtime::~Runtime() {
	// TODO Auto-generated destructor stub
}

} /* namespace runtime */
} /* namespace sheila */
