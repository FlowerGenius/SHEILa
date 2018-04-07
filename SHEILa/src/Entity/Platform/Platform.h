//SHEILa======================================================================
// Name        : Platform.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 27, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_PLATFORM_PLATFORM_H_
#define ENTITY_PLATFORM_PLATFORM_H_

#include <Entity/Version/Version.h>
#include <Entity/Runtime/Runtime.h>
#include <Entity/Mood/Mood.h>
#include <Entity/IPv4/IPv4.h>
#include <Entity/IPv6/IPv6.h>

#include <stdint.h>
#include <vector>

namespace sheila {

class Platform : public Entity {
public:
	Platform();
	virtual ~Platform();



	Mood mood();

	uintmax_t getPlatformId();

private:

	static std::vector<Platform> platforms;

	bool active;
	uintmax_t platformId;

	std::string libsheila_path;
	std::string CPU;
	std::string GPU;
	std::string os;

	std::vector<sheila::runtime::Runtime> runtimes;

	sheila::Version os_version;

	sheila::IPv4 ipaddrv4;
	sheila::IPv6 ipaddrv6;
};

} /* namespace sheila */

#endif /* ENTITY_PLATFORM_PLATFORM_H_ */
