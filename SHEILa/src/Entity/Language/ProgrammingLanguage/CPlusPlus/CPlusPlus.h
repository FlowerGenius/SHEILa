//SHEILa======================================================================
// Name        : CPlusPlus.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 31, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_LANGUAGE_PROGRAMMINGLANGUAGE_CPLUSPLUS_CPLUSPLUS_H_
#define ENTITY_LANGUAGE_PROGRAMMINGLANGUAGE_CPLUSPLUS_CPLUSPLUS_H_

#include <Entity/Language/ProgrammingLanguage/ProgrammingLanguage.h>

namespace sheila {

class CPlusPlus: public virtual ProgrammingLanguage {
public:
	CPlusPlus();
	virtual ~CPlusPlus();
};

} /* namespace sheila */

#endif /* ENTITY_LANGUAGE_PROGRAMMINGLANGUAGE_CPLUSPLUS_CPLUSPLUS_H_ */