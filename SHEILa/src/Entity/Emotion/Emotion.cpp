//SHEILa======================================================================
// Name        : Emotion.cpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 19, 2018
// Modified    :
//============================================================================

#include <Entity/Emotion/Emotion.h>

namespace sheila {

const std::string Emotion::_name = "Emotion";

const std::string Emotion::_desc = "Any one(1) of eight(8) core emotions that can be used to represent any feeling";


Emotion::Emotion() {
	strength = 0;
}

Emotion::Emotion(long double strength) {
	this->strength = strength;
}

void Emotion::setStrength(long double strength) {
	this->strength = strength;
}

long double Emotion::getStrength(void) {
	return strength;
}


Emotion::~Emotion() {
	// TODO Auto-generated destructor stub
}


const std::string Anger::_name = "Anger";

const std::string Anger::_desc = "One(1) of eight(8) core emotions that can be used to represent any feeling";


Anger::Anger() {

}

Anger::Anger(long double strength) {
	this->strength = strength;
}

Anger::~Anger() {
}


const std::string Disgust::_name = "Disgust";

const std::string Disgust::_desc = "One(1) of eight(8) core emotions that can be used to represent any feeling";

Disgust::Disgust() {
}

Disgust::Disgust(long double strength) {
	this->strength = strength;
}

Disgust::~Disgust() {
}


const std::string Sadness::_name = "Sadness";

const std::string Sadness::_desc = "One(1) of eight(8) core emotions that can be used to represent any feeling";

Sadness::Sadness() {
}

Sadness::Sadness(long double strength) {
	this->strength = strength;
}

Sadness::~Sadness() {
}


const std::string Surprise::_name = "Surprise";

const std::string Surprise::_desc = "One(1) of eight(8) core emotions that can be used to represent any feeling";

Surprise::Surprise() {
}

Surprise::Surprise(long double strength) {
	this->strength = strength;
}

Surprise::~Surprise() {
}


const std::string Fear::_name = "Fear";

const std::string Fear::_desc = "One(1) of eight(8) core emotions that can be used to represent any feeling";

Fear::Fear() {
}

Fear::Fear(long double strength) {
	this->strength = strength;
}

Fear::~Fear() {
}


const std::string Trust::_name = "Trust";

const std::string Trust::_desc = "One(1) of eight(8) core emotions that can be used to represent any feeling";

Trust::Trust() {
}

Trust::Trust(long double strength) {
	this->strength = strength;
}

Trust::~Trust() {
}


const std::string Joy::_name = "Joy";

const std::string Joy::_desc = "One(1) of eight(8) core emotions that can be used to represent any feeling";

Joy::Joy() {
}

Joy::Joy(long double strength) {
	this->strength = strength;
}

Joy::~Joy() {
}


const std::string Anticipation::_name = "Anticipation";

const std::string Anticipation::_desc = "One(1) of eight(8) core emotions that can be used to represent any feeling";

Anticipation::Anticipation() {
}

Anticipation::Anticipation(long double strength) {
	this->strength = strength;
}

Anticipation::~Anticipation() {
}

} /* namespace sheila */
