//SHEILa======================================================================
// Name        : IPv6.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 31, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_IPADDRESS_IPV6_IPV6_H_
#define ENTITY_IPADDRESS_IPV6_IPV6_H_

#include <Entity/IPAddress/IPAddress.h>

namespace sheila {

/* Internet Protocol address using a 128-bit address */
class IPv6 :  public IPAddress {
public:
	IPv6();
	virtual ~IPv6();



	std::string toString();
private:

};

} /* namespace sheila */

#endif /* ENTITY_IPADDRESS_IPV6_IPV6_H_ */
