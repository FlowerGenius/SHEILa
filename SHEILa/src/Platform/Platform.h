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

#ifndef PLATFORM_PLATFORM_H_
#define PLATFORM_PLATFORM_H_

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

	sheila::ipaddress::IPv4 ipaddrv4;
	sheila::ipaddress::IPv6 ipaddrv6;
};

} /* namespace platform */
} /* namespace sheila */

#endif /* PLATFORM_PLATFORM_H_ */
