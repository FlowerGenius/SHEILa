//SHEILa======================================================================
// Name        : Platform.hpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 27, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_PLATFORM_PLATFORM_HPP_
#define ENTITY_PLATFORM_PLATFORM_HPP_

#include "Entity/Version.hpp"
#include "Entity/Runtime.hpp"
#include "Entity/Mood.hpp"
#include "Entity/IPAddress.hpp"
#include "Entity/Vendor.hpp"
#include "Entity/OperatingSystem.hpp"

#include <stdint.h>
#include <vector>
#include "Entity/InstructionSetArchitecture.hpp"
#include "Entity/Entity.hpp"

namespace sheila {

class Platform : public Entity<Platform> {
public:
	static std::vector<Platform> platforms;

	Platform();
	virtual ~Platform();

	Mood mood();

	uintmax_t getPlatformId();

private:

	bool active;
	uintmax_t platformId;

	std::string libsheila_path;

	InstructionSetArchitecture isa;
	Vendor vendor;
	OperatingSystem os;

	std::vector<sheila::runtime::Runtime> runtimes;

	sheila::IPv4 ipaddrv4;
	sheila::IPv6 ipaddrv6;
};

} /* namespace sheila */

#endif /* ENTITY_PLATFORM_PLATFORM_HPP_ */
