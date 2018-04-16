//SHEILa======================================================================
// Name        : IPAddress.hpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 27, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_IPADDRESS_IPADDRESS_HPP_
#define ENTITY_IPADDRESS_IPADDRESS_HPP_

#include <stdint.h>
#include <string>
#include <sstream>
#include <bitset>

#include "../Entity.hpp"

namespace sheila {

class IPAddress : public SheilaClass<IPADDRESS_T> {
public:

	static std::vector<IPAddress> ip_addresses;

	IPAddress();
	virtual ~IPAddress();

	//virtual std::string toString();
private:

};

} /* namespace sheila */

#include "../IPv4/IPv4.hpp"
#include "../IPv6/IPv6.hpp"

#endif /* ENTITY_IPADDRESS_IPADDRESS_HPP_ */
