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

class Emotion {
public:
	Emotion();
	virtual ~Emotion();

	void setStrength(uintmax_t s){
		strength = s;
	}

	uintmax_t getStrength(void){
		return strength;
	}

	std::string getFeeling(void){
		if ( ((this->strength) >= 0) && ((this->strength) < (UINTMAX_MAX / 3)) ){
			return this->LOW_FEELING;
		} else if (((this->strength) >= (UINTMAX_MAX/3)) &&
				((this->strength) < (UINTMAX_MAX - (UINTMAX_MAX / 3)))){
			return this->MID_FEELING;
		} else if ( ((this->strength) <= UINTMAX_MAX) &&
				((this->strength) >= (UINTMAX_MAX - (UINTMAX_MAX / 3))) ){
			return this->HIGH_FEELING;
		} else {
			return "nothing";
		}
	}

protected:
	uintmax_t strength;
	std::string LOW_FEELING;
	std::string MID_FEELING;
	std::string HIGH_FEELING;
};

class Anger : public Emotion {
public:
	Anger();
	virtual ~Anger();
protected:

};

class Disgust : public Emotion {
public:
	Disgust();
	virtual ~Disgust();
protected:

};

class Sadness : public Emotion {
public:
	Sadness();
	virtual ~Sadness();
protected:

};

class Surprise : public Emotion {
public:
	Surprise();
	virtual ~Surprise();
protected:

};

class Fear : public Emotion {
public:
	Fear();
	virtual ~Fear();
protected:

};

class Trust : public Emotion {
public:
	Trust();
	virtual ~Trust();
protected:

};

class Joy : public Emotion {
public:
	Joy();
	virtual ~Joy();
protected:

};

class Anticipation : public Emotion {
public:
	Anticipation();
	virtual ~Anticipation();
protected:

};

#endif /* EMOTION_EMOTION_H_ */
