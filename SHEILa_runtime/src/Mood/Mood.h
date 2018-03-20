//SHEILa======================================================================
// Name        : Mood.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 19, 2018
// Modified    :
//============================================================================

#ifndef MOOD_MOOD_H_
#define MOOD_MOOD_H_

#include "../Emotion/Emotion.h"

class Mood {
public:
	Mood();
	Mood(uintmax_t,uintmax_t,uintmax_t,uintmax_t,
			uintmax_t,uintmax_t,uintmax_t,uintmax_t);
	virtual ~Mood();

	void setAnger(uintmax_t a){
		this->anger->setStrength(a);
	}

	uintmax_t getAnger(void){
		return this->anger->getStrength();
	}


	Anger 			*anger;
	Disgust 		*disgust;
	Sadness 		*sadness;
	Surprise 		*surprise;
	Fear 			*fear;
	Trust 			*trust;
	Joy 			*joy;
	Anticipation 	*anticipation;
};

#endif /* MOOD_MOOD_H_ */
