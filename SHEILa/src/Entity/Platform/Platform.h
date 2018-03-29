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
#include <stdint.h>
#include <vector>

#include "../Runtime/Runtime.h"
#include "../Mood/Mood.h"
#include "../IPAddress/IPAddress.h"

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

	sheila::ipaddress::IPv4 ipaddrv4;
	sheila::ipaddress::IPv6 ipaddrv6;
};

} /* namespace platform */
} /* namespace sheila */

#endif /* ENTITY_PLATFORM_PLATFORM_H_ */
