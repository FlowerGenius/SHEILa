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

#include <Entity/Range/Range.h>

namespace sheila {

Range::Range() {
	lower_bound = 0;
	upper_bound = 0;
}

Range::Range(long double l,long double u){
	lower_bound = l;
	upper_bound = u;
}

bool Range::contains(long double number){
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
