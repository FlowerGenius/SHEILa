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

#include "../Version/Version.hpp"
#include "../Runtime/Runtime.hpp"
#include "../Mood/Mood.hpp"
#include "../IPAddress/IPAddress.hpp"
#include "../Vendor/Vendor.hpp"
#include "../OperatingSystem/OperatingSystem.hpp"

#include <stdint.h>
#include <vector>
#include "../InstructionSetArchitecture/InstructionSetArchitecture.hpp"

namespace sheila {

class Platform : public SheilaClass<PLATFORM_T> {
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
