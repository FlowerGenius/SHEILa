//SHEILa======================================================================
// Name        : Network.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 27, 2018
// Modified    :
//============================================================================

#ifndef NETWORK_NETWORK_H_
#define NETWORK_NETWORK_H_

#include "IPAddress/IPAddress.h"
#include "Mood/Mood.h"
#include "Runtime/Runtime.h"
#include "Platform/Platform.h"

namespace sheila {
namespace network {

class Network {
public:
	Network();
	virtual ~Network();

	Mood mood();

	uintmax_t getNetworkId();

private:

	bool active;
	uintmax_t networkId;

	static std::vector<Network> networks;
	std::vector<sheila::platform::Platform> platforms;

	sheila::ipaddress::IPv4 ipaddrv4;
	sheila::ipaddress::IPv6 ipaddrv6;

};

} /* namespace network */
} /* namespace sheila */

#endif /* NETWORK_NETWORK_H_ */
