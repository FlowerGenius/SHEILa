//SHEILa======================================================================
// Name        : Emotion.cpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 19, 2018
// Modified    :
//============================================================================

#include "Emotion.hpp"

namespace sheila {

template<>
xml::XmlFile* 						Entity<EMOTION_T>::_objdef_file_;

template<>
cpp::CppSourceFile* 				cpp::CppObject<EMOTION_T>::_source_file_;

template<>
std::vector<cpp::CppHeaderFile*> 	cpp::CppObject<EMOTION_T>::_header_files_;



Emotion::Emotion() {


	strength = 0;
}

Emotion::Emotion(long double strength) {

	this->strength = strength;
}

void Emotion::setStrength(long double strength) {

	if(strength >= double(-100.0L) && strength <= double(100.0L)){

	}
	this->strength = strength;


}

long double Emotion::getStrength(void) {
	return strength;
}


Emotion::~Emotion() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */
