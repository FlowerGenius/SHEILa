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

Feeling::Feeling(std::string name, std::string desc,
					uintmax_t anger_low, uintmax_t anger_hi,
					uintmax_t disgust_low, uintmax_t disgust_hi,
					uintmax_t sadness_low, uintmax_t sadness_hi,
					uintmax_t surprise_low, uintmax_t surprise_hi,
					uintmax_t fear_low, uintmax_t fear_hi,
					uintmax_t trust_low, uintmax_t trust_hi,
					uintmax_t joy_low, uintmax_t joy_hi,
					uintmax_t anticpation_low, uintmax_t anticipation_hi){
	this->name = name;
	this->description = desc;
	this->anger_range =  Range(anger_low, anger_hi);
	this->disgust_range = Range(disgust_low, disgust_hi);
	this->sadness_range = Range(sadness_low, sadness_hi);
	this->surprise_range = Range(surprise_low, surprise_hi);
	this->fear_range = Range(fear_low, fear_hi);
	this->trust_range = Range(trust_low, trust_hi);
	this->joy_range = Range(joy_low, joy_hi);
	this->anticipation_range = Range(anticpation_low, anticipation_hi);

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
