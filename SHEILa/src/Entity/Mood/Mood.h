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

#include <Entity/Emotion/Emotion.h>
#include <Entity/Feeling/Feeling.h>
#include <vector>
#include <iostream>

namespace sheila {

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

#endif /* ENTITY_MOOD_MOOD_H_ */
