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

#include "Manufacturer.h"

namespace sheila {

std::vector<Manufacturer> Manufacturer::manufacturers;

Manufacturer::Manufacturer() {
	_name = {"Manufacturer"};
	_desc = {"a company or collective that manufactures goods"};

	name = "unknown";
}

Manufacturer::~Manufacturer() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */
