//SHEILa======================================================================
// Name        : Version.cpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 28, 2018
// Modified    :
//============================================================================

#include <Version/Version.h>

namespace sheila {

Version::Version() {
	this->maj = 0;
	this->min = 0;
	this->rev = 0;
}

Version::Version(std::string ver) {
	size_t pos;
	int n = 0;
	while ((pos = ver.find('.')) != std::string::npos){

		switch(n){
		case 0:
			maj = std::stoi(ver.substr(0,pos));
			break;
		case 1:
			min = std::stoi(ver.substr(0,pos));
			break;
		}

		ver.erase(0,pos+1);
		n++;
	}

	rev = std::stod(ver);
	this->name = "";
}

Version::Version(std::string ver, std::string name) {
	size_t pos;
	int n = 0;
	while ((pos = ver.find('.')) != std::string::npos){

		switch(n){
		case 0:
			maj = std::stoi(ver.substr(0,pos));
			break;
		case 1:
			min = std::stoi(ver.substr(0,pos));
			break;
		}

		ver.erase(0,pos+1);
		n++;
	}

	rev = std::stod(ver);
	this->name = name;
}

Version::Version(uint8_t major, uint8_t minor, double revision) {
	this->maj = major;
	this->min = minor;
	this->rev = revision;
	this->name = "";
}

Version::Version(uint8_t major, uint8_t minor, double revision, std::string name) {
	this->maj = major;
	this->min = minor;
	this->rev = revision;
	this->name = name;
}

std::string Version::toString() {


}


Version::~Version() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */
