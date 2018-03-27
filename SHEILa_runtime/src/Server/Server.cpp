//SHEILa======================================================================
// Name        : Server.cpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 27, 2018
// Modified    :
//============================================================================

#include "Server.h"

namespace sheila {
namespace server {

/* The number of instances of this class in this program */
int Server::instanceId = 0;

/* The number of SHEILa runtimes connected to this server */
uintmax_t Server::active_runtimes;

Server::Server() {
	instanceId = instanceId + 1;
	if (instanceId > 1){
		//TODO Throw an error if there is already a server class
	}
}

Server::~Server() {
	// TODO Auto-generated destructor stub
}

} /* namespace server */
} /* namespace sheila */
