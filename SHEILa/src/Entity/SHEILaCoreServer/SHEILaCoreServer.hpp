//SHEILa======================================================================
// Name        : SHEILaCoreServer.hpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Apr 2, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_SHEILACORESERVER_SHEILACORESERVER_HPP_
#define ENTITY_SHEILACORESERVER_SHEILACORESERVER_HPP_

#include "../Server/Server.hpp"
#include "../Feeling/Feeling.hpp"
#include "../Mood/Mood.hpp"


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

#endif /* ENTITY_SHEILACORESERVER_SHEILACORESERVER_HPP_ */
