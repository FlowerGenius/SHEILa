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

#ifndef ENTITY_NETWORK_NETWORK_H_
#define ENTITY_NETWORK_NETWORK_H_

#include <Entity/IPAddress/IPAddress.h>
#include <Entity/Mood/Mood.h>
#include <Entity/Platform/Platform.h>
#include <Entity/Runtime/Runtime.h>

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

#endif /* ENTITY_NETWORK_NETWORK_H_ */