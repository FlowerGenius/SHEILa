//SHEILa======================================================================
// Name        : SHEILa_daemon.cpp
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 0.0.0
// Copyright   :
// Description : Server program for an instance of SHEILa
// Module	   : SHEILa_daemon
// Created     : March 29, 2018
// Modified    : March 29, 2018
//============================================================================

#include "SHEILa_daemon.hpp"


#include <atomic>
#include <string>
#include <vector>


typedef enum shutdown_conditions {
	MAINTENANCE_SHUTDOWN,
	MAINTENANCE_RESTART,
} ShutdownCondition;

std::atomic<ShutdownCondition> TERMINATION_SIGNAL;
std::atomic_bool TERMINATE;


//int setupEntity(sheila::SheilaEntityType e) {
//
//}
//
//int commitEntityToDisk(sheila::SheilaEntityType e){
//	;
//}
//
//int loadEntityFromDisk(sheila::SheilaEntityType e){
//	;
//}


/*
 * Uses the information from 'target' to build a shared object library that is
 * usable on 'target'
 */
int buildLibrary(sheila::Platform target) {
	//TODO Use the information from 'target' to build a library that will be
	//usable on 'target'
	return 0;
}

/*
 * Uses the information from 'target' to build a runtime executable that is
 * usable on 'target'
 */
int buildRuntime(sheila::Platform target) {
	//TODO Use the information from 'target' to build a runtime that will run
	//on 'target'
	return 0;
}

/*
 * Builds the daemon executable
 */
int buildDaemon() {
	system("cd /home/erin/Documents/SHEILa/SHEILa_daemon; echo -n '1. Current Directory is '; pwd");

	return 0;
}

/*
 * Start the server
 */
int server_init() {
	//TODO Initiate this server
	return 0;
}

/*
 * Recall all known networks
 */
int network_init() {
	//TODO Initiate known networks
	return 0;
}

/*
 * Recall all known platforms
 */
int platform_init() {
	//sheila::Platform::load(SHEILA_ENTITY_INSTANCE_LOC);
	//TODO Initiate known platforms
	return 0;
}

/*
 * Recall and connect to all known runtimes
 */
int runtime_init() {
	//TODO Initiate and connect to known runtimes
	return 0;
}

int main() {

//	while (!TERMINATE) {
//
//	}
	buildDaemon();

	sheila::Emotion e1 = sheila::Emotion();
	sheila::Emotion e2 = sheila::Emotion();


	sheila::cpp::CppSharedLib l;

	std::cout << l.getName() << std::endl;

//while (true){
//	std::cout << e2._getName()[0] << std::endl;
//}
	return 0;
}

// Identify unknown objects and add them to the queue

// When available, ask an information source for a name and brief description

// Create the directories:
//	SRC = ${SHEILA_WORKSPACE_LOC}/src/Entity
//  ENT = ${SHEILA_ENTITY_LOC}/{@name}[0]

/*
 * Create the skeleton files:
 *     C++ Source File: SRC/{@name}[0]/{@name}[0].cpp
 *     C++ Header File: SRC/{@name}[0]/{@name}[0].hpp
 *     CMake          : SRC/{@name}[0]/CMakeLists.txt
 *
 *     SheilaClass XML: ENT/{@name}[0].xml
 *
 */

/*
 * Modify the parent files:
 *     C++ Source File: SRC/Entity/Entity.cpp
 *     C++ Header File: SRC/Entity.hpp XXX Change typedefs and sheila_class
 *     CMake          : SRC/CMakeLists.txt
 *
 *     C/C++ inclusion: ${SHEILA_WORKSPACE_LOC}/src/includes.inc
 *
 *     SheilaClass XML: ${SHEILA_ENTITY_LOC}/entities.xml
 *     SheilaClass XML: ${SHEILA_ENTITY_LOC}/Entity.xml
 *
 */


