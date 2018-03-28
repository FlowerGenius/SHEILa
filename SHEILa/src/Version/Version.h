//SHEILa======================================================================
// Name        : Version.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 28, 2018
// Modified    :
//============================================================================

#ifndef VERSION_VERSION_H_
#define VERSION_VERSION_H_

#include <stdint.h>
#include <string>

namespace sheila {

class Version {
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

#endif /* VERSION_VERSION_H_ */
