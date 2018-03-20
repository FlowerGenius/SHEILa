//SHEILa======================================================================
// Name        : Feeling.cpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 20, 2018
// Modified    :
//============================================================================

#include "Feeling.h"

namespace sheila {

Feeling::Feeling() {

}

Feeling::Feeling(std::string name, std::string desc, uintmax_t anger_low,
		uintmax_t anger_hi, signed char a1, signed char b1, signed char c1,
		signed char d1, signed char e1, signed char f1, signed char g1,
		signed char h1, uintmax_t disgust_low, uintmax_t disgust_hi,
		signed char a2, signed char b2, signed char c2, signed char d2,
		signed char e2, signed char f2, signed char g2, signed char h2,
		uintmax_t sadness_low, uintmax_t sadness_hi, signed char a3,
		signed char b3, signed char c3, signed char d3, signed char e3,
		signed char f3, signed char g3, signed char h3, uintmax_t surprise_low,
		uintmax_t surprise_hi, signed char a4, signed char b4, signed char c4,
		signed char d4, signed char e4, signed char f4, signed char g4,
		signed char h4, uintmax_t fear_low, uintmax_t fear_hi, signed char a5,
		signed char b5, signed char c5, signed char d5, signed char e5,
		signed char f5, signed char g5, signed char h5, uintmax_t trust_low,
		uintmax_t trust_hi, signed char a6, signed char b6, signed char c6,
		signed char d6, signed char e6, signed char f6, signed char g6,
		signed char h6, uintmax_t joy_low, uintmax_t joy_hi, signed char a7,
		signed char b7, signed char c7, signed char d7, signed char e7,
		signed char f7, signed char g7, signed char h7,
		uintmax_t anticpation_low, uintmax_t anticipation_hi, signed char a8,
		signed char b8, signed char c8, signed char d8, signed char e8,
		signed char f8, signed char g8, signed char h8) {
	this->name = name;
	this->description = desc;
	this->anger_range = Range(anger_low, anger_hi);
	this->disgust_range = Range(disgust_low, disgust_hi);
	this->sadness_range = Range(sadness_low, sadness_hi);
	this->surprise_range = Range(surprise_low, surprise_hi);
	this->fear_range = Range(fear_low, fear_hi);
	this->trust_range = Range(trust_low, trust_hi);
	this->joy_range = Range(joy_low, joy_hi);
	this->anticipation_range = Range(anticpation_low, anticipation_hi);

	this->a1 = a1;
	this->a2 = a2;
	this->a3 = a3;
	this->a4 = a4;
	this->a5 = a5;
	this->a6 = a6;
	this->a7 = a7;
	this->a8 = a8;

	this->b1 = b1;
	this->b2 = b2;
	this->b3 = b3;
	this->b4 = b4;
	this->b5 = b5;
	this->b6 = b6;
	this->b7 = b7;
	this->b8 = b8;

	this->c1 = c1;
	this->c2 = c2;
	this->c3 = c3;
	this->c4 = c4;
	this->c5 = c5;
	this->c6 = c6;
	this->c7 = c7;
	this->c8 = c8;

	this->d1 = d1;
	this->d2 = d2;
	this->d3 = d3;
	this->d4 = d4;
	this->d5 = d5;
	this->d6 = d6;
	this->d7 = d7;
	this->d8 = d8;

	this->e1 = e1;
	this->e2 = e2;
	this->e3 = e3;
	this->e4 = e4;
	this->e5 = e5;
	this->e6 = e6;
	this->e7 = e7;
	this->e8 = e8;

	this->f1 = f1;
	this->f2 = f2;
	this->f3 = f3;
	this->f4 = f4;
	this->f5 = f5;
	this->f6 = f6;
	this->f7 = f7;
	this->f8 = f8;

	this->g1 = g1;
	this->g2 = g2;
	this->g3 = g3;
	this->g4 = g4;
	this->g5 = g5;
	this->g6 = g6;
	this->g7 = g7;
	this->g8 = g8;

	this->h1 = h1;
	this->h2 = h2;
	this->h3 = h3;
	this->h4 = h4;
	this->h5 = h5;
	this->h6 = h6;
	this->h7 = h7;
	this->h8 = h8;

}

Feeling::~Feeling() {
	// TODO Auto-generated destructor stub
}

const std::string& Feeling::getDescription() const {
	return description;
}

const std::string& Feeling::getName() const {
	return name;
}

} /* namespace sheila */
