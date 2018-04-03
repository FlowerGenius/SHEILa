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



#include "symbols.inc"
#include "includes.inc"

#endif /* SHEILA_H_ */
