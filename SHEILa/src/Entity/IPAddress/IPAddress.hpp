//SHEILa======================================================================
// Name        : IPAddress.hpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 27, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_IPADDRESS_IPADDRESS_HPP_
#define ENTITY_IPADDRESS_IPADDRESS_HPP_

#include <stdint.h>
#include <string>
#include <sstream>
#include <bitset>

#include "../Entity.hpp"

namespace sheila {
/** @brief The types of IPAddress
 *
 */
enum class IPAddressType {
	v4,//!< IP Address v4 : 32-bit address
	v6 //!< IP Address v6 : 128-bit address
};

/** @brief The base of all IPAddress Types
 *
 */
struct IPAddress_base : public Entity<IPAddress_base>{

	IPAddress_base();

	virtual ~IPAddress_base();
};

/** @brief An IP Address
 *
 */
template<IPAddressType version>
class IPAddress : public IPAddress_base {
public:

	/** @brief Creates an object representing an IP Address
	 *
	 */
	IPAddress(std::initializer_list<uint8_t> = {});
	IPAddress(uint32_t integer_address);


	/** @brief Destroys this IPAddress object
	 *
	 */
	virtual ~IPAddress();

	std::string toString();

	uint32_t getAddress();

	//virtual std::string toString();
private:

	std::vector<uint8_t> ip_id;

//	uint8_t a;
//	uint8_t b;
//	uint8_t c;
//	uint8_t d;
//
//	uint8_t e;
//	uint8_t f;
//	uint8_t g;
//	uint8_t h;
//
//	uint8_t i;
//	uint8_t j;
//	uint8_t k;
//	uint8_t l;
//
//	uint8_t m;
//	uint8_t n;
//	uint8_t o;
//	uint8_t p;

};

typedef IPAddress<IPAddressType::v4> IPv4;
typedef IPAddress<IPAddressType::v6> IPv6;

} /* namespace sheila */


#endif /* ENTITY_IPADDRESS_IPADDRESS_HPP_ */
