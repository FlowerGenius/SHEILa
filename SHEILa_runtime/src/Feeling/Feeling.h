//SHEILa======================================================================
// Name        : Feeling.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 20, 2018
// Modified    :
//============================================================================

#ifndef FEELING_FEELING_H_
#define FEELING_FEELING_H_

#include <string>
#include "../Range/Range.h"

namespace sheila {

class Feeling {
public:
	Feeling();
	Feeling(std::string name, std::string desc,
						uintmax_t anger_low, uintmax_t anger_hi,
						uintmax_t disgust_low, uintmax_t disgust_hi,
						uintmax_t sadness_low, uintmax_t sadness_hi,
						uintmax_t surprise_low, uintmax_t surprise_hi,
						uintmax_t fear_low, uintmax_t fear_hi,
						uintmax_t trust_low, uintmax_t trust_hi,
						uintmax_t joy_low, uintmax_t joy_hi,
						uintmax_t anticpation_low, uintmax_t anticipation_hi);
	virtual ~Feeling();
	const std::string& getDescription() const;
	const std::string& getName() const;

	Range anger_range;
	Range disgust_range;
	Range sadness_range;
	Range surprise_range;
	Range fear_range;
	Range trust_range;
	Range joy_range;
	Range anticipation_range;
protected:
	std::string name;
	std::string description;

};

} /* namespace sheila */

#endif /* FEELING_FEELING_H_ */
