//SHEILa======================================================================
// Name        : SHEILa.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 27, 2018
// Modified    :
//============================================================================

#ifndef SHEILA_H_
#define SHEILA_H_

#ifdef _WIN32
	#pragma once

	#ifdef SHEILA_LIBRARY_EXPORTS
		#define SHEILA_LIBRARY_API __declspec(dllexport)
	#else
		#define SHEILA_LIBRARY_API __declspec(dllimport)
	#endif
#else
	#define SHEILA_LIBRARY_API
#endif

#include "SHEILa_libraryConfig.h"

/*
 * SHEILa sees some object she does not recognize and asks "What is that?"
 *
 *	1. sees a chair, asks the user
 *
 * After correctly identifying the object, the user provides a name and
 * brief explanation of the object
 *
 *  2. User explains that it is a chair, it is used for sitting and
 *  	is classified as furniture
 *
 * If the new object is a type of object(s) that sheila already knows, she
 * creates a subclass that inherits the type(s).
 *
 * 	3a.	SHEILa creates Chair class inherited from all matching types and
 * 	 	places it in the Entity subdirectory
 *
 * If the new object is new type of objects{s} that describes known objects,
 * she modifies the classes of those objects(s) such that they inherit from
 * the new class.
 *
 * 	3b.	SHEILa creates Chair class and places it in the Entity
 * 		subdirectory, modifies potential child classes (e.g. ArmChair) to be
 * 		children of Chair.
 *
 * If the new object is completely novel, she creates a new class.
 *
 *	3c.	SHEILa creates Chair class and places it in Entity subdirectory.
 *
 *
 *
 */

/*
 * Any class that inherits from Entity must follow these rules:
 *
 * 1. 	The relationship from a child class to a parent class represents
 * 		an ('is a type of') dynamic, as in $CHILD is a type of $PARENT.
 *
 * 2.	The relationship from an instance of a class to it's class represents
 * 		a ('is a') dynamic, as in $CHILD_INSTANCE is a $CHILD.
 *
 * 3.	The relationship from a parent class to a child class represents
 * 		a ('can be a') dynamic, as in $PARENT can be a $CHILD.
 *
 *
 * 	Entity: IP Address
 * 	Variants: v4,v6
 *
 * 	if variants > 0 then Entity<IPAddress_base>
 * 	else Entity<IPAddress>
 *
 */

#include <CppLanguage/CppLanguage.h>

#include "Entity/Emotion.hpp"
#include "Entity/Feeling.hpp"
#include "Entity/InstructionSetArchitecture.hpp"
#include "Entity/IPAddress.hpp"
#include "Entity/Language.hpp"
#include "Entity/Manufacturer.hpp"
#include "Entity/Mood.hpp"
#include "Entity/Network.hpp"
#include "Entity/Number.hpp"
#include "Entity/OperatingSystem.hpp"
#include "Entity/Platform.hpp"
#include "Entity/ProgrammingLanguage.hpp"
#include "Entity/Range.hpp"
#include "Entity/Runtime.hpp"
#include "Entity/Schema.hpp"
#include "Entity/Server.hpp"
#include "Entity/Processor.hpp"
#include "Entity/SHEILaCoreServer.hpp"
#include "Entity/UnknownEntity.hpp"
#include "Entity/Vendor.hpp"
#include "Entity/Version.hpp"

#include "Entity/Entity.hpp"



#endif /* SHEILA_H_ */
