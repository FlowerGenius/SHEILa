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

#include "Emotion.h"

namespace sheila {

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

std::string Emotion::getFeeling(void) {
	if (((this->strength) >= 0) && ((this->strength) < (UINTMAX_MAX / 3))) {
		return this->LOW_FEELING;
	} else if (((this->strength) >= (UINTMAX_MAX / 3))
			&& ((this->strength) < (UINTMAX_MAX - (UINTMAX_MAX / 3)))) {
		return this->MID_FEELING;
	} else if (((this->strength) <= UINTMAX_MAX)
			&& ((this->strength) >= (UINTMAX_MAX - (UINTMAX_MAX / 3)))) {
		return this->HIGH_FEELING;
	} else {
		return "nothing";
	}
}

Emotion::~Emotion() {
	// TODO Auto-generated destructor stub
}

Anger::Anger() {
	LOW_FEELING = "annoyance";
	MID_FEELING = "anger";
	HIGH_FEELING = "rage";
}

Anger::Anger(long double strength) {
	this->strength = strength;
}

Anger::~Anger() {
}

Disgust::Disgust() {
	LOW_FEELING = "boredom";
	MID_FEELING = "disgust";
	HIGH_FEELING = "loathing";
}

Disgust::Disgust(long double strength) {
	this->strength = strength;
}

Disgust::~Disgust() {
}

Sadness::Sadness() {
	LOW_FEELING = "pensiveness";
	MID_FEELING = "sadness";
	HIGH_FEELING = "grief";
}

Sadness::Sadness(long double strength) {
	this->strength = strength;
}

Sadness::~Sadness() {
}

Surprise::Surprise() {
	LOW_FEELING = "distraction";
	MID_FEELING = "surprise";
	HIGH_FEELING = "amazement";
}

Surprise::Surprise(long double strength) {
	this->strength = strength;
}

Surprise::~Surprise() {
}

Fear::Fear() {
	LOW_FEELING = "apprehension";
	MID_FEELING = "fear";
	HIGH_FEELING = "terror";
}

Fear::Fear(long double strength) {
	this->strength = strength;
}

Fear::~Fear() {
}

Trust::Trust() {
	LOW_FEELING = "acceptance";
	MID_FEELING = "trust";
	HIGH_FEELING = "admiration";
}

Trust::Trust(long double strength) {
	this->strength = strength;
}

Trust::~Trust() {
}

Joy::Joy() {
	LOW_FEELING = "serenity";
	MID_FEELING = "joy";
	HIGH_FEELING = "ecstasy";
}

Joy::Joy(long double strength) {
	this->strength = strength;
}

Joy::~Joy() {
}

Anticipation::Anticipation() {
	LOW_FEELING = "vigilance";
	MID_FEELING = "anticipation";
	HIGH_FEELING = "interest";
}

Anticipation::Anticipation(long double strength) {
	this->strength = strength;
}

Anticipation::~Anticipation() {
}

} /* namespace sheila */
