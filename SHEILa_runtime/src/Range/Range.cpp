//SHEILa======================================================================
// Name        : Range.cpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 20, 2018
// Modified    :
//============================================================================

#include "Range.h"

namespace sheila {

Range::Range() {
	lower_bound = 0;
	upper_bound = 0;
}

Range::Range(uintmax_t l,uintmax_t u){
	lower_bound = l;
	upper_bound = u;
}

bool Range::contains(uintmax_t number){
	if ((number >= lower_bound) && (number <= upper_bound)){
		return true;
	} else {
		return false;
	}

}

Range::~Range() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */
