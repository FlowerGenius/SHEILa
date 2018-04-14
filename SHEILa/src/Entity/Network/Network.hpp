//SHEILa======================================================================
// Name        : Network.hpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 27, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_NETWORK_NETWORK_HPP_
#define ENTITY_NETWORK_NETWORK_HPP_

#include "../IPv4/IPv4.hpp"
#include "../IPv6/IPv6.hpp"
#include "../Mood/Mood.hpp"
#include "../Platform/Platform.hpp"
#include "../Runtime/Runtime.hpp"

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

#endif /* ENTITY_NETWORK_NETWORK_HPP_ */
