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
#include <Entity/IPAddress/IPv4/IPv4.h>
#include <Entity/IPAddress/IPv6/IPv6.h>

#include <stdint.h>
#include <vector>

namespace sheila {
namespace platform {

class Platform {
public:
	Platform();
	virtual ~Platform();

	Mood mood();

	uintmax_t getPlatformId();

private:

	bool active;
	uintmax_t platformId;

	static std::vector<Platform> platforms;
	std::vector<sheila::runtime::Runtime> runtimes;

	std::string CPU;
	std::string GPU;
	std::string os;
	sheila::Version os_version;

	sheila::IPv4 ipaddrv4;
	sheila::IPv6 ipaddrv6;
};

} /* namespace platform */
} /* namespace sheila */

#endif /* ENTITY_PLATFORM_PLATFORM_H_ */
