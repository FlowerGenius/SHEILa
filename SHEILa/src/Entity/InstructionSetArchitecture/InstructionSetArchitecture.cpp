//SHEILa========================================================================
// Name        : InstructionSetArchitecture.cpp
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 8, 2018
// Modified    :
//==============================================================================

#include "InstructionSetArchitecture.hpp"

namespace sheila {

template<>
std::string								Entity<INSTRUCTION_SET_ARCHITECTURE_T>::_sourcefile_path_ =
__FILE__;

template<>
std::time_t								Entity<INSTRUCTION_SET_ARCHITECTURE_T>::_time_created_ =
std::time(nullptr);

template<>
std::time_t								Entity<INSTRUCTION_SET_ARCHITECTURE_T>::_time_accessed_ =
std::time(nullptr);

template<>
std::time_t								Entity<INSTRUCTION_SET_ARCHITECTURE_T>::_time_modified_ =
std::time(nullptr);

template<>
std::vector<long double> 				Entity<INSTRUCTION_SET_ARCHITECTURE_T>::_emotion_values_ =
{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};

template<>
std::vector<std::string> 				Entity<INSTRUCTION_SET_ARCHITECTURE_T>::_name_ =
{"InstructionSetArchitecture","Instruction Set Architecture","ISA"};

template<>
std::vector<std::string> 				Entity<INSTRUCTION_SET_ARCHITECTURE_T>::_desc_ =
{""};

template<>
std::vector<std::string>				Entity<INSTRUCTION_SET_ARCHITECTURE_T>::_cv_filters_ =
{""};

template<>
std::vector<cpp::CppClass_advanced> 	Entity<INSTRUCTION_SET_ARCHITECTURE_T>::_parents_ =
{};

template<>
std::vector<cpp::CppClass_advanced> 	Entity<INSTRUCTION_SET_ARCHITECTURE_T>::_children_ =
{};

template<>
std::vector<cpp::CppStandardHeaderFile>	Entity<INSTRUCTION_SET_ARCHITECTURE_T>::_cpp_include_files_ =
{};

template<>
std::vector<c::CStandardHeaderFile>		Entity<INSTRUCTION_SET_ARCHITECTURE_T>::_c_include_files_ =
{};

template<>
std::vector<cpp::CppHeaderFile>			Entity<INSTRUCTION_SET_ARCHITECTURE_T>::_include_files_ =
{};

//template<>
//std::vector<cpp::CppMacro>				_macros_;

//template<>
//std::vector<cpp::CppSymbol>				_symbols_;

template<>
std::vector<cpp::CppConstructor>		Entity<INSTRUCTION_SET_ARCHITECTURE_T>::_constructors_ =
{};

template<>
std::vector<cpp::CppDestructor>			Entity<INSTRUCTION_SET_ARCHITECTURE_T>::_destructors_ =
{};

template<>
std::vector<cpp::CppMemberFunction> 	Entity<INSTRUCTION_SET_ARCHITECTURE_T>::_member_functions_ =
{};

template<>
std::vector<cpp::CppDataMember> 		Entity<INSTRUCTION_SET_ARCHITECTURE_T>::_data_members_ =
{};

std::vector<InstructionSetArchitecture> InstructionSetArchitecture::instruction_set_architectures;

InstructionSetArchitecture::InstructionSetArchitecture() {

	manufacturer = {Manufacturer()};
}

InstructionSetArchitecture::~InstructionSetArchitecture() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */
