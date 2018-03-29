//SHEILa======================================================================
// Name        : SourceMod.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : Parent class for the creation and modification of programs
// Module	   : SHEILa
// Created     : Mar 28, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_SOURCEMOD_SOURCEMOD_H_
#define ENTITY_SOURCEMOD_SOURCEMOD_H_

#include <Entity/Platform/Platform.h>

namespace sheila {

class SourceMod {
public:
	SourceMod();
	virtual ~SourceMod();
private:
	sheila::platform::Platform targetplatform;
};

} /* namespace sheila */

#endif /* ENTITY_SOURCEMOD_SOURCEMOD_H_ */
