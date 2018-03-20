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

#ifndef RANGE_RANGE_H_
#define RANGE_RANGE_H_

#include <stdint.h>

namespace sheila {

class Range {
public:
	Range();
	Range(uintmax_t l,uintmax_t u);
	virtual ~Range();

	bool contains(uintmax_t);

private:
	uintmax_t lower_bound;
	uintmax_t upper_bound;
};

} /* namespace sheila */

#endif /* RANGE_RANGE_H_ */
