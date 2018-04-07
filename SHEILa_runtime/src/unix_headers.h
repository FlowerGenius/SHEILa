//SHEILa======================================================================
// Name        : unix_headers.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 19, 2018
// Modified    :
//============================================================================

#ifndef UNIX_HEADERS_H_
#define UNIX_HEADERS_H_

#ifdef __ANDROID__
	// This block contains code only to be included when being compiled for a
	// Android device
#elif linux || __linux || __linux__
	// This block contains code only to be included when being compiled for a
	// Linux system
	#include "linux_headers.h"
#elif __APPLE__ || __MACH__

#endif



#endif /* UNIX_HEADERS_H_ */
