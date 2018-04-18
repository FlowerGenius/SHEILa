//SHEILa======================================================================
// Name        : symbols.inc
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 31, 2018
// Modified    :
//============================================================================

#ifndef SYMBOLS_INC_
#define SYMBOLS_INC_

#define MIN_PERCENTAGE -100.0L
#define MAX_PERCENTAGE  100.0L

/* The location on the server of my core files */
#define SHEILA_WORKSPACE_DIR "/home/erin/Documents/SHEILa"

/* The location on the server of my memory storage */
#define SHEILA_ENTITY_DIR "/home/erin/Documents/SHEILa_etc/entities"

#ifndef LINE_MAX
	/* The maximuim line size in a source file */
	#define LINE_MAX 80
#endif

#ifndef PATH_MAX
	/* The maximum length of a file path */
	#define PATH_MAX 255
#endif

#ifndef HEADER_FEILD_LEN
	#define HEADER_FEILD_LEN (LINE_MAX - 20)
#endif

#ifndef BUILD_FOR_SHEILA_DAEMON
	#define BUILD_FOR_SHEILA_DAEMON 1
#endif

#endif /* SYMBOLS_INC_ */
