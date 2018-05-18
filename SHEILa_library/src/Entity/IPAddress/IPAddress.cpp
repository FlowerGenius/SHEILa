//SHEILa======================================================================
// Name        : IPAddress.cpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 27, 2018
// Modified    :
//============================================================================

#include "Entity/IPAddress.hpp"

namespace sheila {

IPAddress_base::IPAddress_base()  {
}

IPAddress_base::~IPAddress_base() {
	// TODO Auto-generated destructor stub
}

template<IPAddressType version>
IPAddress<version>::IPAddress(uint32_t address){
	ip_id.push_back(address >> 24);
	ip_id.push_back(address >> 16);
	ip_id.push_back(address >> 8);
	ip_id.push_back(address);
}

//IPv4::IPv4(std::string address){
//	size_t pos;
//	int n = 0;
//	while ((pos = address.find('.')) != std::string::npos){
//
//		switch(n){
//		case 0:
//			a = std::stoi(address.substr(0,pos));
//			break;
//		case 1:
//			b = std::stoi(address.substr(0,pos));
//			break;
//		case 2:
//			c = std::stoi(address.substr(0,pos));
//			break;
//		}
//
//		address.erase(0,pos+1);
//		n++;
//	}
//
//	d = std::stoi(address);
//
//}

//IPv4::IPv4(const char* address){
//	std::string addr = std::string(address);
//
//	size_t pos;
//	int n = 0;
//	while ((pos = addr.find('.')) != std::string::npos){
//
//		switch(n){
//		case 0:
//			a = std::stoi(addr.substr(0,pos));
//			break;
//		case 1:
//			b = std::stoi(addr.substr(0,pos));
//			break;
//		case 2:
//			c = std::stoi(addr.substr(0,pos));
//			break;
//		}
//
//		addr.erase(0,pos+1);
//		n++;
//	}
//
//	d = std::stoi(addr);
//}

template<IPAddressType version>
uint32_t IPAddress<version>::getAddress(){
	return (ip_id[0] << 24) | (ip_id[1] << 16) | (ip_id[2] << 8) | ip_id[3];
}

template<IPAddressType version>
std::string IPAddress<version>::toString(){
	std::stringstream ss;
	ss << ip_id[0] << '.' << ip_id[1] << '.' << ip_id[2] << '.' << ip_id[3];
	return ss.str();
}

} /* namespace sheila */
