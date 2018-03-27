//SHEILa======================================================================
// Name        : Emotion.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 19, 2018
// Modified    :
//============================================================================

#ifndef EMOTION_EMOTION_H_
#define EMOTION_EMOTION_H_

#include <stdint.h>
#include <string>

namespace sheila {

class Emotion {
public:
	Emotion();
	Emotion(long double strength);
	virtual ~Emotion();

	void setStrength(long double strength);
	long double getStrength(void);

	std::string getFeeling(void);

protected:
	long double strength;
	std::string LOW_FEELING;
	std::string MID_FEELING;
	std::string HIGH_FEELING;
};

class Anger: public Emotion {
public:
	Anger();
	Anger(long double strength);
	virtual ~Anger();
protected:

};

class Disgust: public Emotion {
public:
	Disgust();
	Disgust(long double strength);
	virtual ~Disgust();
protected:

};

class Sadness: public Emotion {
public:
	Sadness();
	Sadness(long double strength);
	virtual ~Sadness();
protected:

};

class Surprise: public Emotion {
public:
	Surprise();
	Surprise(long double strength);
	virtual ~Surprise();
protected:

};

class Fear: public Emotion {
public:
	Fear();
	Fear(long double strength);
	virtual ~Fear();
protected:

};

class Trust: public Emotion {
public:
	Trust();
	Trust(long double strength);
	virtual ~Trust();
protected:

};

class Joy: public Emotion {
public:
	Joy();
	Joy(long double strength);
	virtual ~Joy();
protected:

};

class Anticipation: public Emotion {
public:
	Anticipation();
	Anticipation(long double strength);
	virtual ~Anticipation();
protected:

};

} /* namespace sheila */

#endif /* EMOTION_EMOTION_H_ */
