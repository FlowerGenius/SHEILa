/*SHEILa========================================================================
 * Name        : CppObject.cpp
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 16, 2018
 * Modified    :
 *==============================================================================
 */
#include "CppObject.h"

namespace sheila {
namespace cpp {

#if (BUILD_FOR_SHEILA_DAEMON == 1)
template<class _N>
std::vector<std::string> CppObject<_N>::this_object_names;

template<class _N>
std::vector<std::string> CppObject<_N>::this_object_authors;

template<class _N>
std::vector<std::string> CppObject<_N>::this_object_versions;

template<class _N>
std::vector<std::string> CppObject<_N>::this_object_copyrights;

template<class _N>
std::vector<std::string> CppObject<_N>::this_object_descriptions;

template<class _N>
std::vector<std::string> CppObject<_N>::this_object_modules;

template<class _N>
std::string              CppObject<_N>::this_object_created;

template<class _N>
std::vector<std::string> CppObject<_N>::this_object_modified;

template<class _N>
CppSource* 				 CppObject<_N>::this_object_source;

template<class _N>
std::vector<CppHeader*>  CppObject<_N>::this_object_headers;
#endif


//template<class _N>
//CppObject<_N>::CppObject() {
//
//	object_source = nullptr;
//}
//
//template<class _N>
//CppObject<_N>::~CppObject() {
//
//}

} /* namespace cpp */
} /* namespace sheila */
