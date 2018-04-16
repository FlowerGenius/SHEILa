//SHEILa======================================================================
// Name        : Emotion.hpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 19, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_EMOTION_EMOTION_HPP_
#define ENTITY_EMOTION_EMOTION_HPP_

#include <stdint.h>
#include <string>
#include <vector>
#include "../Entity.hpp"

namespace sheila {

class Emotion : public SheilaClass<EMOTION_T> {
public:

	static std::vector<Emotion> entities;

	Emotion();
	Emotion(long double strength);
	virtual ~Emotion();

	void setStrength(long double strength);
	long double getStrength(void);

protected:

	long double strength;

private:


};

} /* namespace sheila */

#endif /* ENTITY_EMOTION_EMOTION_HPP_ */
