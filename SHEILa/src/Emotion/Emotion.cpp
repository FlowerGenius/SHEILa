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


Emotion::~Emotion() {
	// TODO Auto-generated destructor stub
}

Anger::Anger() {
}

Anger::Anger(long double strength) {
	this->strength = strength;
}

Anger::~Anger() {
}

Disgust::Disgust() {
}

Disgust::Disgust(long double strength) {
	this->strength = strength;
}

Disgust::~Disgust() {
}

Sadness::Sadness() {
}

Sadness::Sadness(long double strength) {
	this->strength = strength;
}

Sadness::~Sadness() {
}

Surprise::Surprise() {
}

Surprise::Surprise(long double strength) {
	this->strength = strength;
}

Surprise::~Surprise() {
}

Fear::Fear() {
}

Fear::Fear(long double strength) {
	this->strength = strength;
}

Fear::~Fear() {
}

Trust::Trust() {
}

Trust::Trust(long double strength) {
	this->strength = strength;
}

Trust::~Trust() {
}

Joy::Joy() {
}

Joy::Joy(long double strength) {
	this->strength = strength;
}

Joy::~Joy() {
}

Anticipation::Anticipation() {
}

Anticipation::Anticipation(long double strength) {
	this->strength = strength;
}

Anticipation::~Anticipation() {
}

} /* namespace sheila */
