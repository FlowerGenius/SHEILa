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
#include "../Feeling/Feeling.h"
#include <vector>
#include <iostream>

namespace sheila {

class Mood {
public:
	Mood();
	Mood(uintmax_t,uintmax_t,uintmax_t,uintmax_t,
			uintmax_t,uintmax_t,uintmax_t,uintmax_t);
	virtual ~Mood();

	uintmax_t getAngerStrength(void);
	void setAnger(uintmax_t);

	uintmax_t getDisgustStrength(void);
	void setDisgust(uintmax_t);

	uintmax_t getSadnessStrength(void);
	void setSadness(uintmax_t);

	uintmax_t getSurpriseStrength(void);
	void setSurprise(uintmax_t);

	uintmax_t getFearStrength(void);
	void setFear(uintmax_t);

	uintmax_t getTrustStrength(void);
	void setTrust(uintmax_t);

	uintmax_t getJoyStrength(void);
	void setJoy(uintmax_t);

	uintmax_t getAnticipationStrength(void);
	void setAnticipation(uintmax_t);

	std::string getFeeling();

private:
	Anger 			anger;
	Disgust 		disgust;
	Sadness 		sadness;
	Surprise 		surprise;
	Fear 			fear;
	Trust 			trust;
	Joy 			joy;
	Anticipation 	anticipation;
};

} /* namespace sheila */

#endif /* MOOD_MOOD_H_ */
