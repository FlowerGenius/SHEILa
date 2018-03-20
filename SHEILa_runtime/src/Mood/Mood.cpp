//SHEILa======================================================================
// Name        : Mood.cpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 19, 2018
// Modified    :
//============================================================================

#include "Mood.h"

Mood::Mood() {
	anger 			= new Anger();
	disgust 		= new Disgust();
	sadness 		= new Sadness();
	surprise 		= new Surprise();
	fear 			= new Fear();
	trust 			= new Trust();
	joy 			= new Joy();
	anticipation 	= new Anticipation();
}

Mood::Mood(	uintmax_t anger, uintmax_t disgust, uintmax_t sadness,
			uintmax_t surprise, uintmax_t fear, uintmax_t trust,
			uintmax_t joy, uintmax_t anticipation ) {
	this->anger 		= new Anger();
	this->disgust 		= new Disgust();
	this->sadness 		= new Sadness();
	this->surprise 		= new Surprise();
	this->fear 			= new Fear();
	this->trust 		= new Trust();
	this->joy 			= new Joy();
	this->anticipation 	= new Anticipation();
}

Mood::~Mood() {
	// TODO Auto-generated destructor stub
}

