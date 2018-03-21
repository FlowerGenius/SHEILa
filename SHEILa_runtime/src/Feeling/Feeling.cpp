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
		uintmax_t anger_hi, double a1, double b1, double c1,
		double d1, double e1, double f1, double g1,
		double h1, uintmax_t disgust_low, uintmax_t disgust_hi,
		double a2, double b2, double c2, double d2,
		double e2, double f2, double g2, double h2,
		uintmax_t sadness_low, uintmax_t sadness_hi, double a3,
		double b3, double c3, double d3, double e3,
		double f3, double g3, double h3, uintmax_t surprise_low,
		uintmax_t surprise_hi, double a4, double b4, double c4,
		double d4, double e4, double f4, double g4,
		double h4, uintmax_t fear_low, uintmax_t fear_hi, double a5,
		double b5, double c5, double d5, double e5,
		double f5, double g5, double h5, uintmax_t trust_low,
		uintmax_t trust_hi, double a6, double b6, double c6,
		double d6, double e6, double f6, double g6,
		double h6, uintmax_t joy_low, uintmax_t joy_hi, double a7,
		double b7, double c7, double d7, double e7,
		double f7, double g7, double h7,
		uintmax_t anticpation_low, uintmax_t anticipation_hi, double a8,
		double b8, double c8, double d8, double e8,
		double f8, double g8, double h8) {
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
