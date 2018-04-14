//SHEILa======================================================================
// Name        : Version.hpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 28, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_VERSION_VERSION_HPP_
#define ENTITY_VERSION_VERSION_HPP_

#include "../Entity.hpp"

#include <stdint.h>
#include <string>

namespace sheila {

class Version : public Entity {
public:
	Version();
	Version(std::string ver);
	Version(std::string ver, std::string name);
	Version(uint8_t majot, uint8_t minor, double revision);
	Version(uint8_t major, uint8_t minor, double revision, std::string name);
	virtual ~Version();

	std::string toString();

private:

	uint8_t maj;
	uint8_t min;

	double rev;

	std::string name;


};

} /* namespace sheila */

#endif /* ENTITY_VERSION_VERSION_HPP_ */
