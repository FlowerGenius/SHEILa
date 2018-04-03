//SHEILa======================================================================
// Name        : ProgrammingLanguage.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 31, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_PROGRAMMINGLANGUAGE_PROGRAMMINGLANGUAGE_H_
#define ENTITY_PROGRAMMINGLANGUAGE_PROGRAMMINGLANGUAGE_H_

#include <Entity/Language/Language.h>

namespace sheila {

class ProgrammingLanguage: public virtual Language {
public:
	ProgrammingLanguage();
	virtual ~ProgrammingLanguage();
};

} /* namespace sheila */

#endif /* ENTITY_PROGRAMMINGLANGUAGE_PROGRAMMINGLANGUAGE_H_ */
