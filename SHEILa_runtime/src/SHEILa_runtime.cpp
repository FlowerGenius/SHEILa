//SHEILa======================================================================
// Name        : SHEILa_runtime.cpp
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 0.0.0
// Copyright   :
// Description : Client runtime for an instance of SHEILa
// Module	   : SHEILa_runtime
// Created     : March 19, 2018
// Modified    : March 19, 2018
//============================================================================


#include <SHEILa_library/SHEILa.h>

#include "headers.h"
#include <typeinfo>
#include <atomic>
#include <limits>
#include <cfloat>
#include <bitset>




namespace sheila {


long double sperc(long double p, long double val){
	return (p / 100.0) * val;
}

uintmax_t stouintmax(std::string str){

	if (typeid(uintmax_t) == typeid(unsigned long int)){
		return std::stoul(str);
	} else if (typeid(uintmax_t) == typeid(unsigned long long int)){
		return std::stoull(str);
	} else {
		return std::stoi(str);
	}
}




//Information about the central server this runtime will interface with
namespace server {

	std::atomic_bool FEELING_AVAILABLE;
	std::atomic_bool ACTIVE;

	std::atomic_uintmax_t active_runtimes;

	SHEILaCoreServer SERVER = SHEILaCoreServer();

}

//Information about the local network this platform is connected to
namespace network {
	Network NETWORK = Network();
}

//Information about the platform this runtime is active on
namespace platform {
	bool active = true;

	const char* IPv4 = "";
	const char* IPv6 = "";
	const char* host = "localhost";
	const char* MAC	 = "";

	uintmax_t active_runtimes = 0;

	Mood mood;

	//TODO Explore the devices and connect to some unless they are in use by another runtime

	/*
	 * Query the server for runtimes active on this platform.
	 */
	int find_active_runtimes(){
		return 0;
	}

	/*
	 * Search the system for devices that can be used to hear.
	 */
	int find_audio_input_devices(){
		return 0;
	}

	/*
	 * Search the system for devices that can be used to speak.
	 */
	int find_audio_output_devices(){
		return 0;
	}

	/*
	 * Search the system for devices that can be used to see.
	 */
	int find_video_input_devices(){
		return 0;
	}

	/*
	 * Search the system for devices that can be used to show.
	 */
	int find_video_output_devices(){
		return 0;
	}

	/*
	 * Search the system for devices that can be used to read.
	 */
	int find_text_input_devices(){
		return 0;
	}

	/*
	 * Search the system for devices that can be used to write.
	 */
	int find_text_output_devices(){
		return 0;
	}

}

namespace runtime {
	bool active = true;
	uintmax_t instanceID;
	Mood mood;

	/*
	 * Checks if this platform should do something
	 */
	int loop(){


		return 0;
	}

	int checks(){


		#ifdef __unix__
		
		if (isatty(fileno(stdin))){
			std::cout << "is a term" << std::endl;
		}
			
		#endif

		return 0;
	}

	int write(std::string, std::ostream output){
		return 0;
	}

	int say(std::string){
		return 0;
	}

	int show(){
		return 0;
	}

}
}

int main() {

//	sheila::runtime::mood.setAnger((sheila::sperc(34.0,100.0)));
//	sheila::runtime::mood.setDisgust((100.0 / 100.0));
//	sheila::runtime::mood.setSadness((100.0 / 100.0));
//
//	sheila::runtime::mood.setJoy(sheila::sperc(55.0,100.0));
//	sheila::runtime::mood.setTrust(sheila::sperc(25.0,100.00));
//
//
//	std::cout << sheila::runtime::mood.getFeeling() << std::endl;
//	//std::cout << sheila::Feeling::feelings[0].toString();
//
//	//sheila::runtime::checks();
//
//	while (sheila::runtime::active && sheila::platform::active){
//		sheila::runtime::active = false;
//	}
	if (true) {
		std::cout << "Ok" << std::endl;
	}
	//std::cout << sheila::SHEILaCoreServer::feelings()[0]._E_repr() << std::endl;

	return 0;
}
