//SHEILa======================================================================
// Name        : IPv4.cpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 31, 2018
// Modified    :
//============================================================================

#include "IPv4.hpp"

namespace sheila {



IPv4::IPv4(){
	a = 0;
	b = 0;
	c = 0;
	d = 0;
}

IPv4::IPv4(uint32_t address){
	a = address >> 24;
	b = address >> 16;
	c = address >> 8;
	d = address;

}

IPv4::IPv4(std::string address){
	size_t pos;
	int n = 0;
	while ((pos = address.find('.')) != std::string::npos){

		switch(n){
		case 0:
			a = std::stoi(address.substr(0,pos));
			break;
		case 1:
			b = std::stoi(address.substr(0,pos));
			break;
		case 2:
			c = std::stoi(address.substr(0,pos));
			break;
		}

		address.erase(0,pos+1);
		n++;
	}

	d = std::stoi(address);

}

IPv4::IPv4(const char* address){
	std::string addr = std::string(address);

	size_t pos;
	int n = 0;
	while ((pos = addr.find('.')) != std::string::npos){

		switch(n){
		case 0:
			a = std::stoi(addr.substr(0,pos));
			break;
		case 1:
			b = std::stoi(addr.substr(0,pos));
			break;
		case 2:
			c = std::stoi(addr.substr(0,pos));
			break;
		}

		addr.erase(0,pos+1);
		n++;
	}

	d = std::stoi(addr);
}

IPv4::IPv4(uint8_t a,uint8_t b,uint8_t c,uint8_t d){
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;

}

uint32_t IPv4::getAddress(){
	return (a << 24) | (b << 16) | (c << 8) | d;
}

std::string IPv4::toString(){
	std::stringstream ss;
	ss << a << '.' << b << '.' << c << '.' << d;
	return ss.str();
}


IPv4::~IPv4(){

}

} /* namespace sheila */
