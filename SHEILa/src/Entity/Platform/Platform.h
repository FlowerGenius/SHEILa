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

#include "../Version/Version.h"
#include "../Runtime/Runtime.h"
#include "../Mood/Mood.h"
#include "../IPv4/IPv4.h"
#include "../IPv6/IPv6.h"
#include "../InstructionSetArchitecture/InstructionSetArchitecture.h"
#include "../Vendor/Vendor.h"
#include "../OperatingSystem/OperatingSystem.h"

#include <stdint.h>
#include <vector>

namespace sheila {

class Platform : public Entity {
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

#endif /* ENTITY_PLATFORM_PLATFORM_H_ */
