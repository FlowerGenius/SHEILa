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

#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_

#include <stdint.h>
#include <vector>
#include "IPAddress/IPAddress.h"
#include "Feeling/Feeling.h"
#include "Mood/Mood.h"

//#include "Network/Network.h"
//#include "Platform/Platform.h"
//#include "Runtime/Runtime.h"

namespace sheila {
namespace server {

class Server {
public:
	Server();
	virtual ~Server();

	static Mood mood();

	static std::vector<Feeling> feelings();

	uintmax_t getActiveRuntimes();


private:

	static int instanceId;

	uintmax_t active_runtimes;

	sheila::ipaddress::IPv4 ipaddrv4;
	sheila::ipaddress::IPv6 ipaddrv6;




};

} /* namespace server */
} /* namespace sheila */

#endif /* SERVER_SERVER_H_ */
