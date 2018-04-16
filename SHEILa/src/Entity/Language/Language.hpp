//SHEILa======================================================================
// Name        : Language.hpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 28, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_LANGUAGE_LANGUAGE_HPP_
#define ENTITY_LANGUAGE_LANGUAGE_HPP_

#include "../Entity.hpp"

namespace sheila {

class Language : public SheilaClass<LANGUAGE_T> {
public:
	Language();
	virtual ~Language();
};

} /* namespace sheila */

#endif /* ENTITY_LANGUAGE_LANGUAGE_HPP_ */
