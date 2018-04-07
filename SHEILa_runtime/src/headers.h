//SHEILa======================================================================
// Name        : headers.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 19, 2018
// Modified    :
//============================================================================

#ifndef HEADERS_H_
#define HEADERS_H_


#ifdef __cplusplus
	#include <iostream>
	#include <sstream>
	#include <vector>
#endif


#ifdef _WIN32 || _WIN64
	// This block contains code to be included only when being compiled
	// for Microsoft Windows
	#include "windows_headers.h"
#else ifdef unix || __unix || __unix__
	// This block contains code to be included only when being compiled
	// for a UNIX system
	#include <unistd.h>
#endif

#endif /* HEADERS_H_ */
