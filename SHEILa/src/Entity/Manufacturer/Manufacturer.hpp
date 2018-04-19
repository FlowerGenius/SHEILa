//SHEILa========================================================================
// Name        : Manufacturer.hpp
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 8, 2018
// Modified    :
//==============================================================================

#ifndef ENTITY_MANUFACTURER_MANUFACTURER_HPP_
#define ENTITY_MANUFACTURER_MANUFACTURER_HPP_

#include "../Entity.hpp"

namespace sheila {

class Manufacturer: public Entity<Manufacturer> {
public:

	static std::vector<Manufacturer> manufacturers;

	Manufacturer();
	virtual ~Manufacturer();

protected:

	std::string name;
	std::vector<Manufacturer> parent_companies;
	std::vector<Manufacturer> subsidiaries;

private:

};

} /* namespace sheila */

#endif /* ENTITY_MANUFACTURER_MANUFACTURER_HPP_ */
