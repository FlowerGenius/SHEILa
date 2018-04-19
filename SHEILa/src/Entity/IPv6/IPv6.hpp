//SHEILa======================================================================
// Name        : IPv6.hpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 31, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_IPV6_IPV6_HPP_
#define ENTITY_IPV6_IPV6_HPP_

#include "../IPAddress/IPAddress.hpp"

namespace sheila {

/* Internet Protocol address using a 128-bit address */
class IPv6 : public IPAddress, public Entity<IPv6> {
public:
	IPv6();
	virtual ~IPv6();

	std::string toString();
private:

};

} /* namespace sheila */

#endif /* ENTITY_IPV6_IPV6_HPP_ */
