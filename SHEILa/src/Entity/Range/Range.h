//SHEILa======================================================================
// Name        : Range.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 20, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_RANGE_RANGE_H_
#define ENTITY_RANGE_RANGE_H_

#include <stdint.h>

namespace sheila {

class Range {
public:
	Range();
	Range(long double l,long double u);
	virtual ~Range();

	bool contains(long double);

	long double lo(){
		return lower_bound;
	}
	long double hi(){
		return upper_bound;
	}

private:
	long double lower_bound;
	long double upper_bound;
};

} /* namespace sheila */

#endif /* ENTITY_RANGE_RANGE_H_ */
