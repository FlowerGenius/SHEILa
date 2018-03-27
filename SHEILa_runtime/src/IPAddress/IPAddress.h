//SHEILa======================================================================
// Name        : IPAddress.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 27, 2018
// Modified    :
//============================================================================

#ifndef IPADDRESS_IPADDRESS_H_
#define IPADDRESS_IPADDRESS_H_

#include <stdint.h>
#include <string>
#include <sstream>
#include <bitset>

namespace sheila {
namespace ipaddress {


class IPAddress {
public:
	IPAddress();
	virtual ~IPAddress();

	//virtual std::string toString();
};

/* Internet Protocol address using a 32-bit address */
class IPv4 : public IPAddress {
public:
	IPv4();
	IPv4(uint32_t address);
	IPv4(std::string address);
	IPv4(const char* address);
	IPv4(uint8_t a,uint8_t b,uint8_t c,uint8_t d);


	virtual ~IPv4();

	uint32_t getAddress();

	std::string toString();

private:
	uint8_t a;
	uint8_t b;
	uint8_t c;
	uint8_t d;
};

/* Internet Protocol address using a 128-bit address */
class IPv6 : public IPAddress {
public:
	IPv6();
	virtual ~IPv6();



	std::string toString();
private:

};


} /* namespace ipaddress */
} /* namespace sheila */

#endif /* IPADDRESS_IPADDRESS_H_ */
