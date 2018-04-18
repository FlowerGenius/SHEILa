//SHEILa========================================================================
// Name        : Manufacturer.cpp
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 8, 2018
// Modified    :
//==============================================================================

#include "Manufacturer.hpp"

namespace sheila {

template<>
std::vector<long double>			Entity<MANUFACTURER_T>::_emotion_values_ = {
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0
};

template<>
std::vector<std::string> 			Entity<MANUFACTURER_T>::_name_ = {
		"Manufacturer"
};

template<>
std::vector<std::string> 			Entity<MANUFACTURER_T>::_desc_ = {
		"a company or collective that manufactures goods"
};

std::vector<Manufacturer> Manufacturer::manufacturers;

Manufacturer::Manufacturer() {

	name = "unknown";
}

Manufacturer::~Manufacturer() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */
