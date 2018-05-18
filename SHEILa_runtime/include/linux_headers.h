//SHEILa======================================================================
// Name        : linux_headers.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 19, 2018
// Modified    :
//============================================================================

#ifndef LINUX_HEADERS_H_
#define LINUX_HEADERS_H_

#ifdef __x86_64 || __amd64 || __x86_64__ || __amd64__
	// This block contains code only to be included when being compiled for a
	// UNIX system with 64-bit AMD64 architecture
#elif __i386 || __i386__
	// This block contains code only to be included when being compiled for a
	// UNIX system with 32-bit i386 architecture.
#elif __arm__
	#ifdef __ARM_ARCH_5T__
	#elif  __ARM_ARCH_7A__
	#endif
#elif __powerpc64__
	// This block contains code only to be included when being compiled for a
	// UNIX system with 64-bit PowerPC architecture
#elif __aarch64__
	// This block contains code only to be included when being compiled for a
	// UNIX system with 64-bit AARCH64 architecture
#else
	#ifdef __STDC_HOSTED__
		#warning "SHEILa does not explicitly support processor architecture"
	#else
		#error "SHEILa does not support this processor architecture"
	#endif
#endif


#endif /* LINUX_HEADERS_H_ */
