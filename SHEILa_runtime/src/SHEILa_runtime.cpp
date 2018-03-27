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


#include "headers.h"
#include <typeinfo>
#include "Mood/Mood.h"
#include "Server/Server.h"
#include "Runtime/Runtime.h";
#include <atomic>
#include <limits>
#include <cfloat>
#include <unistd.h>
#include <bitset>



namespace sheila {



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

	Server SERVER = Server();

}

//Information about the local network this platform is connected to
namespace network {
	bool active = false;

	const char* IPv4 = "";
	const char* IPv6 = "";
	const char* MAC	 = "";

	uintmax_t active_runtimes = 0;

	Mood mood;

	/*
	 * Query the server for runtimes active on this network.
	 */
	int find_active_runtimes(){
		return 0;
	}

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

		if (isatty(fileno(stdin))){
			std::cout << "is a term" << std::endl;
		}

		return 0;
	}

	int write(std::string, std::ostream output){

	}

	int say(std::string){

	}

	int show(){

	}

}
}

int main() {


	sheila::runtime::mood.setJoy(100.0 / 2);
	sheila::runtime::mood.setTrust((100.0 / 4));

	std::cout << sheila::runtime::mood.getFeeling() << std::endl;
	//std::cout << sheila::Feeling::feelings[0].toString();

	//sheila::runtime::checks();

	while (sheila::runtime::active && sheila::platform::active){
		sheila::runtime::active = false;
	}


	return 0;
}
