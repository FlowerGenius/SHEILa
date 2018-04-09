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

uintmax_t Runtime::instances = 0;

Runtime::Runtime() {
	instances += 1;

}

Runtime::~Runtime() {
	instances -= 1;
}



} /* namespace runtime */
} /* namespace sheila */
