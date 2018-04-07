//SHEILa======================================================================
// Name        : IPAddress.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 27, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_IPADDRESS_IPADDRESS_H_
#define ENTITY_IPADDRESS_IPADDRESS_H_

#include <stdint.h>
#include <string>
#include <sstream>
#include <bitset>

#include "../Entity.h"

namespace sheila {

class IPAddress : public Entity {
public:

	IPAddress();
	virtual ~IPAddress();

	//virtual std::string toString();
};

} /* namespace sheila */

#endif /* ENTITY_IPADDRESS_IPADDRESS_H_ */
