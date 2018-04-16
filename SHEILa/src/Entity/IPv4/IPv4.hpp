//SHEILa======================================================================
// Name        : IPv4.hpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 31, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_IPV4_IPV4_HPP_
#define ENTITY_IPV4_IPV4_HPP_

#include "../IPAddress/IPAddress.hpp"

namespace sheila {

/* Internet Protocol address using a 32-bit address */
class IPv4 : public IPAddress, public SheilaClass<IPv4_T> {
public:
	IPv4();
	IPv4(uint32_t address);
	IPv4(std::string address);
	IPv4(const char* address);
	IPv4(uint8_t a,uint8_t b,uint8_t c,uint8_t d);


	virtual ~IPv4();

	uint32_t getAddress();

	std::string toString();

protected:

	uint8_t a;
	uint8_t b;
	uint8_t c;
	uint8_t d;

private:

};

} /* namespace sheila */

#endif /* ENTITY_IPV4_IPV4_HPP_ */
