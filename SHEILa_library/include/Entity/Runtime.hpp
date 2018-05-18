//SHEILa======================================================================
// Name        : Runtime.hpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 27, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_RUNTIME_RUNTIME_HPP_
#define ENTITY_RUNTIME_RUNTIME_HPP_

#include "Entity/IPAddress.hpp"
#include <stdint.h>

namespace sheila {
namespace runtime {

class Runtime {
public:
	Runtime();
	virtual ~Runtime();

private:
	static uintmax_t instances;
	const uintmax_t instanceId = instances + 1;

	sheila::IPv4 ipv4;
	sheila::IPv6 ipv6;

};

} /* namespace runtime */
} /* namespace sheila */

#endif /* ENTITY_RUNTIME_RUNTIME_HPP_ */
