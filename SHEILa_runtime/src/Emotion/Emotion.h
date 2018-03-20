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
	Emotion(uintmax_t strength);
	virtual ~Emotion();

	void setStrength(uintmax_t strength);
	uintmax_t getStrength(void);

	std::string getFeeling(void);

protected:
	uintmax_t strength;
	std::string LOW_FEELING;
	std::string MID_FEELING;
	std::string HIGH_FEELING;
};

class Anger: public Emotion {
public:
	Anger();
	Anger(uintmax_t strength);
	virtual ~Anger();
protected:

};

class Disgust: public Emotion {
public:
	Disgust();
	Disgust(uintmax_t strength);
	virtual ~Disgust();
protected:

};

class Sadness: public Emotion {
public:
	Sadness();
	Sadness(uintmax_t strength);
	virtual ~Sadness();
protected:

};

class Surprise: public Emotion {
public:
	Surprise();
	Surprise(uintmax_t strength);
	virtual ~Surprise();
protected:

};

class Fear: public Emotion {
public:
	Fear();
	Fear(uintmax_t strength);
	virtual ~Fear();
protected:

};

class Trust: public Emotion {
public:
	Trust();
	Trust(uintmax_t strength);
	virtual ~Trust();
protected:

};

class Joy: public Emotion {
public:
	Joy();
	Joy(uintmax_t strength);
	virtual ~Joy();
protected:

};

class Anticipation: public Emotion {
public:
	Anticipation();
	Anticipation(uintmax_t strength);
	virtual ~Anticipation();
protected:

};

} /* namespace sheila */

#endif /* EMOTION_EMOTION_H_ */
