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

	Emotion();
	Emotion(long double strength);
	virtual ~Emotion();

	void setStrength(long double strength);
	long double getStrength(void);

protected:

	long double strength;
};


} /* namespace sheila */

#endif /* ENTITY_EMOTION_EMOTION_H_ */
