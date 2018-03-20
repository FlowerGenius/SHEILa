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
	Feeling(std::string name, std::string desc, uintmax_t anger_low,
			uintmax_t anger_hi, signed char a1, signed char b1, signed char c1,
			signed char d1, signed char e1, signed char f1, signed char g1,
			signed char h1, uintmax_t disgust_low, uintmax_t disgust_hi,
			signed char a2, signed char b2, signed char c2, signed char d2,
			signed char e2, signed char f2, signed char g2, signed char h2,
			uintmax_t sadness_low, uintmax_t sadness_hi, signed char a3,
			signed char b3, signed char c3, signed char d3, signed char e3,
			signed char f3, signed char g3, signed char h3,
			uintmax_t surprise_low, uintmax_t surprise_hi, signed char a4,
			signed char b4, signed char c4, signed char d4, signed char e4,
			signed char f4, signed char g4, signed char h4, uintmax_t fear_low,
			uintmax_t fear_hi, signed char a5, signed char b5, signed char c5,
			signed char d5, signed char e5, signed char f5, signed char g5,
			signed char h5, uintmax_t trust_low, uintmax_t trust_hi,
			signed char a6, signed char b6, signed char c6, signed char d6,
			signed char e6, signed char f6, signed char g6, signed char h6,
			uintmax_t joy_low, uintmax_t joy_hi, signed char a7, signed char b7,
			signed char c7, signed char d7, signed char e7, signed char f7,
			signed char g7, signed char h7, uintmax_t anticpation_low,
			uintmax_t anticipation_hi, signed char a8, signed char b8,
			signed char c8, signed char d8, signed char e8, signed char f8,
			signed char g8, signed char h8);
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

	signed char a1, a2, a3, a4, a5, a6, a7, a8;
	signed char b1, b2, b3, b4, b5, b6, b7, b8;
	signed char c1, c2, c3, c4, c5, c6, c7, c8;
	signed char d1, d2, d3, d4, d5, d6, d7, d8;
	signed char e1, e2, e3, e4, e5, e6, e7, e8;
	signed char f1, f2, f3, f4, f5, f6, f7, f8;
	signed char g1, g2, g3, g4, g5, g6, g7, g8;
	signed char h1, h2, h3, h4, h5, h6, h7, h8;
protected:
	std::string name;
	std::string description;

};

} /* namespace sheila */

#endif /* FEELING_FEELING_H_ */
