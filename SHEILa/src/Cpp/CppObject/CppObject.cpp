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

//template<unsigned long long int _N>
//CppSourceFile* CppObject<_N>::_source_file_;
//
//template<unsigned long long int _N>
//std::vector<CppHeaderFile*> CppObject<_N>::_header_files_;


template<unsigned long long int _N>
CppObject<_N>::CppObject() {


	object_source = nullptr;
}

template<unsigned long long int _N>
CppObject<_N>::~CppObject() {

}

} /* namespace cpp */
} /* namespace sheila */
