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

namespace sheila {
namespace server {

class Server {
public:
	Server();
	virtual ~Server();

	static uintmax_t getActiveRuntimes();

private:

	static int instanceId;

	static uintmax_t active_runtimes;
};

} /* namespace server */
} /* namespace sheila */

#endif /* SERVER_SERVER_H_ */
