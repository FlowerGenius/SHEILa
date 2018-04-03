//SHEILa======================================================================
// Name        : Server.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 27, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_SERVER_SERVER_H_
#define ENTITY_SERVER_SERVER_H_

#include <Entity/IPv4/IPv4.h>
#include <Entity/IPv6/IPv6.h>
#include <stdint.h>
#include <vector>

namespace sheila {

class Server {
public:
	Server();
	virtual ~Server();

protected:

	sheila::IPv4 ipaddrv4;
	sheila::IPv6 ipaddrv6;

};

} /* namespace sheila */

#endif /* ENTITY_SERVER_SERVER_H_ */
