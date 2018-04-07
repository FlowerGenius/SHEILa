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

#include "../IPv4/IPv4.h"
#include "../IPv6/IPv6.h"
#include "../Mood/Mood.h"
#include "../Platform/Platform.h"
#include "../Runtime/Runtime.h"

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
	std::vector<sheila::Platform> platforms;

	sheila::IPv4 ipaddrv4;
	sheila::IPv6 ipaddrv6;

};

} /* namespace network */
} /* namespace sheila */

#endif /* ENTITY_NETWORK_NETWORK_H_ */
