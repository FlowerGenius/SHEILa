//SHEILa======================================================================
// Name        : SHEILaCoreServer.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Apr 2, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_SHEILACORESERVER_SHEILACORESERVER_H_
#define ENTITY_SHEILACORESERVER_SHEILACORESERVER_H_

#include "../Server/Server.h"
#include "../Feeling/Feeling.h"

class Mood;
#include "../Mood/Mood.h"


namespace sheila {

class SHEILaCoreServer: public Server {
public:
	SHEILaCoreServer();
	virtual ~SHEILaCoreServer();


	static Mood mood();

	static std::vector<Feeling> feelings();

	uintmax_t getActiveRuntimes();

protected:



};

} /* namespace sheila */

#endif /* ENTITY_SHEILACORESERVER_SHEILACORESERVER_H_ */
