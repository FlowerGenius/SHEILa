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
#include "IPAddress/IPAddress.h"

namespace sheila {
namespace runtime {

class Runtime {
public:
	Runtime();
	virtual ~Runtime();

	const uintmax_t getInstanceId() const;

private:
	static uintmax_t instances;
	const uintmax_t instanceId = instances + 1;

	sheila::ipaddress::IPv4 ipv4;
	sheila::ipaddress::IPv6 ipv6;

};

} /* namespace runtime */
} /* namespace sheila */

#endif /* RUNTIME_RUNTIME_H_ */
