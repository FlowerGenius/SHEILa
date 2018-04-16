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
std::string								SheilaClass<EMOTION_T>::_source_path_ =
__FILE__;

template<>
std::time_t								SheilaClass<EMOTION_T>::_time_created_ =
std::time(nullptr);

template<>
std::time_t								SheilaClass<EMOTION_T>::_time_accessed_ =
std::time(nullptr);

template<>
std::time_t								SheilaClass<EMOTION_T>::_time_modified_ =
std::time(nullptr);

template<>
std::vector<long double> SheilaClass<EMOTION_T>::_emotion_values_ =
{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};

template<>
std::vector<std::string> 				SheilaClass<EMOTION_T>::_name_ =
{"Emotion"};

template<>
std::vector<std::string> 				SheilaClass<EMOTION_T>::_desc_ =
{""};

template<>
std::vector<std::string>				SheilaClass<EMOTION_T>::_cv_filters_ =
{""};

template<>
std::vector<cpp::CppClass_advanced> 	SheilaClass<EMOTION_T>::_parents_ =
{};

template<>
std::vector<cpp::CppClass_advanced> 	SheilaClass<EMOTION_T>::_children_ =
{};

template<>
std::vector<cpp::CppStandardHeaderFile>	SheilaClass<EMOTION_T>::_cpp_include_files_ =
{};

template<>
std::vector<c::CStandardHeaderFile>		SheilaClass<EMOTION_T>::_c_include_files_ =
{};

template<>
std::vector<cpp::CppHeaderFile>			SheilaClass<EMOTION_T>::_include_files_ =
{};

//template<>
//std::vector<cpp::CppMacro>				_macros_;

//template<>
//std::vector<cpp::CppSymbol>				_symbols_;

template<>
std::vector<cpp::CppConstructor>		SheilaClass<EMOTION_T>::_constructors_ =
{};

template<>
std::vector<cpp::CppDestructor>			SheilaClass<EMOTION_T>::_destructors_ =
{};

template<>
std::vector<cpp::CppMemberFunction> 	SheilaClass<EMOTION_T>::_member_functions_ =
{};

template<>
std::vector<cpp::CppDataMember> 		SheilaClass<EMOTION_T>::_data_members_ =
{};



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
