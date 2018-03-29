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

#include <Entity/Runtime/Runtime.h>

namespace sheila {
namespace runtime {

uintmax_t Runtime::instances = 0;

Runtime::Runtime() {
	instances += 1;

}

const uintmax_t Runtime::getInstanceId() const {
	return instanceId;
}

Runtime::~Runtime() {
	instances -= 1;
}



} /* namespace runtime */
} /* namespace sheila */
