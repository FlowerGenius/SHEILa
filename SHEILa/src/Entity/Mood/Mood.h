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

#ifndef ENTITY_MOOD_MOOD_H_
#define ENTITY_MOOD_MOOD_H_

#include "../Emotion/Emotion.h"
#include "../Feeling/Feeling.h"
#include "../SHEILaCoreServer/SHEILaCoreServer.h"


#include <vector>
#include <iostream>

namespace sheila {

/*
 * A SHEILa Mood is a Plutchik emotional state, determined by the 8 central
 * Plutchik emotions: Anger, Disgust, Sadness, Surprise, Fear, Trust, Joy and
 * Anticipation.
 */
class Mood {
public:
	Mood();
	Mood(long double,long double,long double,long double,
			long double,long double,long double,long double);
	virtual ~Mood();

	long double getAngerStrength(void);
	void setAnger(long double);

	long double getDisgustStrength(void);
	void setDisgust(long double);

	long double getSadnessStrength(void);
	void setSadness(long double);

	long double getSurpriseStrength(void);
	void setSurprise(long double);

	long double getFearStrength(void);
	void setFear(long double);

	long double getTrustStrength(void);
	void setTrust(long double);

	long double getJoyStrength(void);
	void setJoy(long double);

	long double getAnticipationStrength(void);
	void setAnticipation(long double);

	std::string getFeeling();

private:
	Emotion anger;
	Emotion disgust;
	Emotion sadness;
	Emotion surprise;
	Emotion	fear;
	Emotion trust;
	Emotion	joy;
	Emotion	anticipation;
};

} /* namespace sheila */

#endif /* ENTITY_MOOD_MOOD_H_ */
