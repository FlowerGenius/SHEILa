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
			uintmax_t anger_hi, double a1, double b1, double c1,
			double d1, double e1, double f1, double g1,
			double h1, uintmax_t disgust_low, uintmax_t disgust_hi,
			double a2, double b2, double c2, double d2,
			double e2, double f2, double g2, double h2,
			uintmax_t sadness_low, uintmax_t sadness_hi, double a3,
			double b3, double c3, double d3, double e3,
			double f3, double g3, double h3,
			uintmax_t surprise_low, uintmax_t surprise_hi, double a4,
			double b4, double c4, double d4, double e4,
			double f4, double g4, double h4, uintmax_t fear_low,
			uintmax_t fear_hi, double a5, double b5, double c5,
			double d5, double e5, double f5, double g5,
			double h5, uintmax_t trust_low, uintmax_t trust_hi,
			double a6, double b6, double c6, double d6,
			double e6, double f6, double g6, double h6,
			uintmax_t joy_low, uintmax_t joy_hi, double a7, double b7,
			double c7, double d7, double e7, double f7,
			double g7, double h7, uintmax_t anticpation_low,
			uintmax_t anticipation_hi, double a8, double b8,
			double c8, double d8, double e8, double f8,
			double g8, double h8);
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

	double a1, a2, a3, a4, a5, a6, a7, a8;
	double b1, b2, b3, b4, b5, b6, b7, b8;
	double c1, c2, c3, c4, c5, c6, c7, c8;
	double d1, d2, d3, d4, d5, d6, d7, d8;
	double e1, e2, e3, e4, e5, e6, e7, e8;
	double f1, f2, f3, f4, f5, f6, f7, f8;
	double g1, g2, g3, g4, g5, g6, g7, g8;
	double h1, h2, h3, h4, h5, h6, h7, h8;
protected:
	std::string name;
	std::string description;

};

} /* namespace sheila */

#endif /* FEELING_FEELING_H_ */
