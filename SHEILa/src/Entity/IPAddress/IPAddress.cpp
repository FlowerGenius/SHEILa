//SHEILa======================================================================
// Name        : IPAddress.cpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 27, 2018
// Modified    :
//============================================================================

#include "IPAddress.hpp"

namespace sheila {

template<>
std::string								SheilaClass<IPADDRESS_T>::_source_path_ =
__FILE__;

template<>
std::time_t								SheilaClass<IPADDRESS_T>::_time_created_ =
std::time(nullptr);

template<>
std::time_t								SheilaClass<IPADDRESS_T>::_time_accessed_ =
std::time(nullptr);

template<>
std::time_t								SheilaClass<IPADDRESS_T>::_time_modified_ =
std::time(nullptr);

template<>
std::vector<long double> SheilaClass<IPADDRESS_T>::_emotion_values_ =
{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};

template<>
std::vector<std::string> 				SheilaClass<IPADDRESS_T>::_name_ =
{"IPAddress","IP Address"};

template<>
std::vector<std::string> 				SheilaClass<IPADDRESS_T>::_desc_ =
{""};

template<>
std::vector<std::string>				SheilaClass<IPADDRESS_T>::_cv_filters_ =
{""};

template<>
std::vector<cpp::CppClass_advanced> 	SheilaClass<IPADDRESS_T>::_parents_ =
{};

template<>
std::vector<cpp::CppClass_advanced> 	SheilaClass<IPADDRESS_T>::_children_ =
{};

template<>
std::vector<cpp::CppStandardHeaderFile>	SheilaClass<IPADDRESS_T>::_cpp_include_files_ =
{};

template<>
std::vector<c::CStandardHeaderFile>		SheilaClass<IPADDRESS_T>::_c_include_files_ =
{};

template<>
std::vector<cpp::CppHeaderFile>			SheilaClass<IPADDRESS_T>::_include_files_ =
{};

//template<>
//std::vector<cpp::CppMacro>				_macros_;

//template<>
//std::vector<cpp::CppSymbol>				_symbols_;

template<>
std::vector<cpp::CppConstructor>		SheilaClass<IPADDRESS_T>::_constructors_ =
{};

template<>
std::vector<cpp::CppDestructor>			SheilaClass<IPADDRESS_T>::_destructors_ =
{};

template<>
std::vector<cpp::CppMemberFunction> 	SheilaClass<IPADDRESS_T>::_member_functions_ =
{};

template<>
std::vector<cpp::CppDataMember> 		SheilaClass<IPADDRESS_T>::_data_members_ =
{};

std::vector<IPAddress> IPAddress::ip_addresses;

IPAddress::IPAddress()  {
}

IPAddress::~IPAddress() {
	// TODO Auto-generated destructor stub
}


} /* namespace sheila */
