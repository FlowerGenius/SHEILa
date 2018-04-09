//SHEILa========================================================================
// Name        : Manufacturer.h
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 8, 2018
// Modified    :
//==============================================================================

#ifndef ENTITY_MANUFACTURER_MANUFACTURER_H_
#define ENTITY_MANUFACTURER_MANUFACTURER_H_

#include "../Entity.h"

namespace sheila {

class Manufacturer: public Entity {
public:

	static std::vector<Manufacturer> manufacturers;

	Manufacturer();
	virtual ~Manufacturer();
private:
	std::string name;
	std::vector<Manufacturer> parent_companies;
	std::vector<Manufacturer> subsidiaries;
};

} /* namespace sheila */

#endif /* ENTITY_MANUFACTURER_MANUFACTURER_H_ */
