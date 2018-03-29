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

#ifndef ENTITY_EMOTION_EMOTION_H_
#define ENTITY_EMOTION_EMOTION_H_

#include <stdint.h>
#include <string>
#include <vector>
#include <Entity/Entity.h>

namespace sheila {

class Emotion : public Entity {
public:

	/* Promises that each subclass of entity has variable "name" */
	static const std::string _name;

	/* Promises that each subclass of entity has variable "desc" */
	static const std::string _desc;

	Emotion();
	Emotion(long double strength);
	virtual ~Emotion();

	void setStrength(long double strength);
	long double getStrength(void);

protected:

	long double strength;
};

class Anger: public Emotion {
public:

	/* Promises that each subclass of entity has variable "name" */
	static const std::string _name;

	/* Promises that each subclass of entity has variable "desc" */
	static const std::string _desc;

	Anger();
	Anger(long double strength);
	virtual ~Anger();

protected:

};

class Disgust: public Emotion {
public:

	/* Promises that each subclass of entity has variable "name" */
	static const std::string _name;

	/* Promises that each subclass of entity has variable "desc" */
	static const std::string _desc;

	Disgust();
	Disgust(long double strength);
	virtual ~Disgust();
protected:

};

class Sadness: public Emotion {
public:

	/* Promises that each subclass of entity has variable "name" */
	static const std::string _name;

	/* Promises that each subclass of entity has variable "desc" */
	static const std::string _desc;

	Sadness();
	Sadness(long double strength);
	virtual ~Sadness();
protected:

};

class Surprise: public Emotion {
public:

	/* Promises that each subclass of entity has variable "name" */
	static const std::string _name;

	/* Promises that each subclass of entity has variable "desc" */
	static const std::string _desc;

	Surprise();
	Surprise(long double strength);
	virtual ~Surprise();
protected:

};

class Fear: public Emotion {
public:

	/* Promises that each subclass of entity has variable "name" */
	static const std::string _name;

	/* Promises that each subclass of entity has variable "desc" */
	static const std::string _desc;

	Fear();
	Fear(long double strength);
	virtual ~Fear();
protected:

};

class Trust: public Emotion {
public:

	/* Promises that each subclass of entity has variable "name" */
	static const std::string _name;

	/* Promises that each subclass of entity has variable "desc" */
	static const std::string _desc;

	Trust();
	Trust(long double strength);
	virtual ~Trust();
protected:

};

class Joy: public Emotion {
public:

	/* Promises that each subclass of entity has variable "name" */
	static const std::string _name;

	/* Promises that each subclass of entity has variable "desc" */
	static const std::string _desc;

	Joy();
	Joy(long double strength);
	virtual ~Joy();
protected:

};

class Anticipation: public Emotion {
public:

	/* Promises that each subclass of entity has variable "name" */
	static const std::string _name;

	/* Promises that each subclass of entity has variable "desc" */
	static const std::string _desc;

	Anticipation();
	Anticipation(long double strength);
	virtual ~Anticipation();
protected:

};

} /* namespace sheila */

#endif /* ENTITY_EMOTION_EMOTION_H_ */
