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

#include "Emotion.hpp"

namespace sheila {

template<PlutchikEmotion _Te>
Emotion<_Te> Emotion<_Te>::global_value;

void Emotion_base::setStrength(long double strength) {
	this->strength = strength;
}

long double Emotion_base::getStrength(void) {
	return this->strength;
}


} /* namespace sheila */

