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
#include "Mood/Mood.h"


namespace sheila {


//Information about the central server this runtime will interface with
namespace server {
	bool active = false;

	const char* IPv4 = "";
	const char* IPv6 = "";
	const char* MAC	 = "";

	uintmax_t active_runtimes = 0;

	Mood mood;

	std::vector<Feeling> feelings;

	/*
	 * Query the server for all active runtimes.
	 */
	int find_active_runtimes(){
		return 0;
	}

	/*
	 * Load all known possible feelings into a vector
	 */
	int load_feelings(){
		feelings.push_back(Feeling("Anger","",
									(UINTMAX_MAX / 3), (UINTMAX_MAX / 3) * 2,0,0,0,0,0,0,
									0,0,0,0,0,0,0,0));
		feelings.push_back(Feeling("Joy","",
											0,0,0,0,0,0,0,0,
											0,0,0,0,(UINTMAX_MAX / 3), (UINTMAX_MAX / 3) * 2,0,0));




		return 0;
	}

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

}
}

int main() {
	sheila::server::load_feelings();

	sheila::runtime::mood.setJoy(UINTMAX_MAX / 2);
	std::cout << sheila::runtime::mood.getFeeling() << std::endl;
	while (sheila::runtime::active && sheila::platform::active){
		sheila::runtime::active = false;
	}
	return 0;
}
