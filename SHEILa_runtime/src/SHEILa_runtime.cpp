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

	std::vector<Feeling> feelings;

	/*
	 * Query the server for all active runtimes.
	 */
	int find_active_runtimes(){

		//TODO contact the server requesting the list of all active runtimes

		return 0;
	}

	/*
	 * Load all known possible feelings into a vector
	 */
	int load_feelings(){

		//TODO contact the server requesting all of the feelings one line at a time

		std::stringstream ss;

		ss << "Anger" << '\t';
		ss << "Feeling heated and upset" << '\t';
		ss << "6148914691236517205:12297829382473034410:0.0:0.0:0.0:0.0:0.0:0.0:0.0:0.0" << '\t';
		ss << "0:0:0.0:0.0:0.0:0.0:0.0:0.0:0.0:0.0" << '\t';
		ss << "0:0:0.0:0.0:0.0:0.0:0.0:0.0:0.0:0.0" << '\t';
		ss << "0:0:0.0:0.0:0.0:0.0:0.0:0.0:0.0:0.0" << '\t';
		ss << "0:0:0.0:0.0:0.0:0.0:0.0:0.0:0.0:0.0" << '\t';
		ss << "0:0:0.0:0.0:0.0:0.0:0.0:0.0:0.0:0.0" << '\t';
		ss << "0:0:0.0:0.0:0.0:0.0:0.0:0.0:0.0:0.0" << '\t';
		ss << "0:0:0.0:0.0:0.0:0.0:0.0:0.0:0.0:0.0" << '\t' << '\n';
		ss << "Joy" << '\t';
		ss << "Feeling bright and well" << '\t';
		ss << "0:0:0.0:0.0:0.0:0.0:0.0:0.0:0.0:0.0" << '\t';
		ss << "0:0:0.0:0.0:0.0:0.0:0.0:0.0:0.0:0.0" << '\t';
		ss << "0:0:0.0:0.0:0.0:0.0:0.0:0.0:0.0:0.0" << '\t';
		ss << "0:0:0.0:0.0:0.0:0.0:0.0:0.0:0.0:0.0" << '\t';
		ss << "0:0:0.0:0.0:0.0:0.0:0.0:0.0:0.0:0.0" << '\t';
		ss << "0:0:0.0:0.0:0.0:0.0:0.0:0.0:0.0:0.0" << '\t';
		ss << "6148914691236517205:12297829382473034410:0.0:0.0:0.0:0.0:0.0:0.0:0.0:0.0" << '\t';
		ss << "0:0:0.0:0.0:0.0:0.0:0.0:0.0:0.0:0.0" << '\t' << '\n';

		std::string testresponse = ss.str();

		size_t pos;
		std::string feeling_s;
		while ((pos = testresponse.find('\n')) != std::string::npos){

			std::string feeling_name;
			std::string feeling_desc;

			uintmax_t temp_min1,temp_min2,temp_min3,temp_min4,temp_min5,temp_min6,temp_min7,temp_min8;
			uintmax_t temp_max1,temp_max2,temp_max3,temp_max4,temp_max5,temp_max6,temp_max7,temp_max8;

			double a1, a2, a3, a4, a5, a6, a7, a8;
			double b1, b2, b3, b4, b5, b6, b7, b8;
			double c1, c2, c3, c4, c5, c6, c7, c8;
			double d1, d2, d3, d4, d5, d6, d7, d8;
			double e1, e2, e3, e4, e5, e6, e7, e8;
			double f1, f2, f3, f4, f5, f6, f7, f8;
			double g1, g2, g3, g4, g5, g6, g7, g8;
			double h1, h2, h3, h4, h5, h6, h7, h8;

			feeling_s = testresponse.substr(0, pos);
			size_t pos2;
			std::string feeling_s_s;
			int n = 0;
			while ((pos2 = feeling_s.find('\t')) != std::string::npos){
				feeling_s_s = feeling_s.substr(0,pos2);
				size_t pos3,pos4,pos5,pos6,pos7,pos8,pos9,pos10,pos11,pos12;
				switch(n){
				case 0:
					feeling_name = feeling_s_s;
					break;
				case 1:
					feeling_desc = feeling_s_s;
					break;
				case 2:
					pos3 = feeling_s_s.find(':');
					temp_min1 = std::stoull(feeling_s_s.substr(0,pos3));
					feeling_s_s.erase(0,pos3+1);

					pos4 = feeling_s_s.find(':');
					temp_max1 = std::stoull(feeling_s_s.substr(0,pos4));
					feeling_s_s.erase(0,pos4+1);

					pos5 = feeling_s_s.find(':');
					a1 = std::stod(feeling_s_s.substr(0,pos5));
					feeling_s_s.erase(0,pos5+1);

					pos6 = feeling_s_s.find(':');
					b1 = std::stod(feeling_s_s.substr(0,pos6));
					feeling_s_s.erase(0,pos6+1);

					pos7 = feeling_s_s.find(':');
					c1 = std::stod(feeling_s_s.substr(0,pos7));
					feeling_s_s.erase(0,pos7+1);

					pos8 = feeling_s_s.find(':');
					d1 = std::stod(feeling_s_s.substr(0,pos8));
					feeling_s_s.erase(0,pos8+1);

					pos9 = feeling_s_s.find(':');
					e1 = std::stod(feeling_s_s.substr(0,pos9));
					feeling_s_s.erase(0,pos9+1);

					pos10 = feeling_s_s.find(':');
					f1 = std::stod(feeling_s_s.substr(0,pos10));
					feeling_s_s.erase(0,pos10+1);

					pos11 = feeling_s_s.find(':');
					g1 = std::stod(feeling_s_s.substr(0,pos11));
					feeling_s_s.erase(0,pos11+1);

					h1 = std::stod(feeling_s_s.substr(0,-1));

					break;
				case 3:
					pos3 = feeling_s_s.find(':');
					temp_min2 = std::stoull(feeling_s_s.substr(0,pos3));
					feeling_s_s.erase(0,pos3+1);

					pos4 = feeling_s_s.find(':');
					temp_max2 = std::stoull(feeling_s_s.substr(0,pos4));
					feeling_s_s.erase(0,pos4+1);

					pos5 = feeling_s_s.find(':');
					a2 = std::stod(feeling_s_s.substr(0,pos5));
					feeling_s_s.erase(0,pos5+1);

					pos6 = feeling_s_s.find(':');
					b2 = std::stod(feeling_s_s.substr(0,pos6));
					feeling_s_s.erase(0,pos6+1);

					pos7 = feeling_s_s.find(':');
					c2 = std::stod(feeling_s_s.substr(0,pos7));
					feeling_s_s.erase(0,pos7+1);

					pos8 = feeling_s_s.find(':');
					d2 = std::stod(feeling_s_s.substr(0,pos8));
					feeling_s_s.erase(0,pos8+1);

					pos9 = feeling_s_s.find(':');
					e2 = std::stod(feeling_s_s.substr(0,pos9));
					feeling_s_s.erase(0,pos9+1);

					pos10 = feeling_s_s.find(':');
					f2 = std::stod(feeling_s_s.substr(0,pos10));
					feeling_s_s.erase(0,pos10+1);

					pos11 = feeling_s_s.find(':');
					g2 = std::stod(feeling_s_s.substr(0,pos11));
					feeling_s_s.erase(0,pos11+1);

					h2 = std::stod(feeling_s_s.substr(0,-1));

					break;
				case 4:
					pos3 = feeling_s_s.find(':');
					temp_min3 = std::stoull(feeling_s_s.substr(0,pos3));
					feeling_s_s.erase(0,pos3+1);

					pos4 = feeling_s_s.find(':');
					temp_max3 = std::stoull(feeling_s_s.substr(0,pos4));
					feeling_s_s.erase(0,pos4+1);

					pos5 = feeling_s_s.find(':');
					a3 = std::stod(feeling_s_s.substr(0,pos5));
					feeling_s_s.erase(0,pos5+1);

					pos6 = feeling_s_s.find(':');
					b3 = std::stod(feeling_s_s.substr(0,pos6));
					feeling_s_s.erase(0,pos6+1);

					pos7 = feeling_s_s.find(':');
					c3 = std::stod(feeling_s_s.substr(0,pos7));
					feeling_s_s.erase(0,pos7+1);

					pos8 = feeling_s_s.find(':');
					d3 = std::stod(feeling_s_s.substr(0,pos8));
					feeling_s_s.erase(0,pos8+1);

					pos9 = feeling_s_s.find(':');
					e3 = std::stod(feeling_s_s.substr(0,pos9));
					feeling_s_s.erase(0,pos9+1);

					pos10 = feeling_s_s.find(':');
					f3 = std::stod(feeling_s_s.substr(0,pos10));
					feeling_s_s.erase(0,pos10+1);

					pos11 = feeling_s_s.find(':');
					g3 = std::stod(feeling_s_s.substr(0,pos11));
					feeling_s_s.erase(0,pos11+1);

					h3 = std::stod(feeling_s_s.substr(0,-1));

					break;
				case 5:
					pos3 = feeling_s_s.find(':');
					temp_min4 = std::stoull(feeling_s_s.substr(0,pos3));
					feeling_s_s.erase(0,pos3+1);

					pos4 = feeling_s_s.find(':');
					temp_max4 = std::stoull(feeling_s_s.substr(0,pos4));
					feeling_s_s.erase(0,pos4+1);

					pos5 = feeling_s_s.find(':');
					a4 = std::stod(feeling_s_s.substr(0,pos5));
					feeling_s_s.erase(0,pos5+1);

					pos6 = feeling_s_s.find(':');
					b4 = std::stod(feeling_s_s.substr(0,pos6));
					feeling_s_s.erase(0,pos6+1);

					pos7 = feeling_s_s.find(':');
					c4 = std::stod(feeling_s_s.substr(0,pos7));
					feeling_s_s.erase(0,pos7+1);

					pos8 = feeling_s_s.find(':');
					d4 = std::stod(feeling_s_s.substr(0,pos8));
					feeling_s_s.erase(0,pos8+1);

					pos9 = feeling_s_s.find(':');
					e4 = std::stod(feeling_s_s.substr(0,pos9));
					feeling_s_s.erase(0,pos9+1);

					pos10 = feeling_s_s.find(':');
					f4 = std::stod(feeling_s_s.substr(0,pos10));
					feeling_s_s.erase(0,pos10+1);

					pos11 = feeling_s_s.find(':');
					g4 = std::stod(feeling_s_s.substr(0,pos11));
					feeling_s_s.erase(0,pos11+1);

					h3 = std::stod(feeling_s_s.substr(0,-1));

					break;
				case 6:
					pos3 = feeling_s_s.find(':');
					temp_min5 = std::stoull(feeling_s_s.substr(0,pos3));
					feeling_s_s.erase(0,pos3+1);

					pos4 = feeling_s_s.find(':');
					temp_max5 = std::stoull(feeling_s_s.substr(0,pos4));
					feeling_s_s.erase(0,pos4+1);

					pos5 = feeling_s_s.find(':');
					a5 = std::stod(feeling_s_s.substr(0,pos5));
					feeling_s_s.erase(0,pos5+1);

					pos6 = feeling_s_s.find(':');
					b5 = std::stod(feeling_s_s.substr(0,pos6));
					feeling_s_s.erase(0,pos6+1);

					pos7 = feeling_s_s.find(':');
					c5 = std::stod(feeling_s_s.substr(0,pos7));
					feeling_s_s.erase(0,pos7+1);

					pos8 = feeling_s_s.find(':');
					d5 = std::stod(feeling_s_s.substr(0,pos8));
					feeling_s_s.erase(0,pos8+1);

					pos9 = feeling_s_s.find(':');
					e5 = std::stod(feeling_s_s.substr(0,pos9));
					feeling_s_s.erase(0,pos9+1);

					pos10 = feeling_s_s.find(':');
					f5 = std::stod(feeling_s_s.substr(0,pos10));
					feeling_s_s.erase(0,pos10+1);

					pos11 = feeling_s_s.find(':');
					g5 = std::stod(feeling_s_s.substr(0,pos11));
					feeling_s_s.erase(0,pos11+1);

					h5 = std::stod(feeling_s_s.substr(0,-1));

					break;
				case 7:
					pos3 = feeling_s_s.find(':');
					temp_min6 = std::stoull(feeling_s_s.substr(0,pos3));
					feeling_s_s.erase(0,pos3+1);

					pos4 = feeling_s_s.find(':');
					temp_max6 = std::stoull(feeling_s_s.substr(0,pos4));
					feeling_s_s.erase(0,pos4+1);

					pos5 = feeling_s_s.find(':');
					a6 = std::stod(feeling_s_s.substr(0,pos5));
					feeling_s_s.erase(0,pos5+1);

					pos6 = feeling_s_s.find(':');
					b6 = std::stod(feeling_s_s.substr(0,pos6));
					feeling_s_s.erase(0,pos6+1);

					pos7 = feeling_s_s.find(':');
					c6 = std::stod(feeling_s_s.substr(0,pos7));
					feeling_s_s.erase(0,pos7+1);

					pos8 = feeling_s_s.find(':');
					d6 = std::stod(feeling_s_s.substr(0,pos8));
					feeling_s_s.erase(0,pos8+1);

					pos9 = feeling_s_s.find(':');
					e6 = std::stod(feeling_s_s.substr(0,pos9));
					feeling_s_s.erase(0,pos9+1);

					pos10 = feeling_s_s.find(':');
					f6 = std::stod(feeling_s_s.substr(0,pos10));
					feeling_s_s.erase(0,pos10+1);

					pos11 = feeling_s_s.find(':');
					g6 = std::stod(feeling_s_s.substr(0,pos11));
					feeling_s_s.erase(0,pos11+1);

					h6 = std::stod(feeling_s_s.substr(0,-1));

					break;
				case 8:
					pos3 = feeling_s_s.find(':');
					temp_min7 = std::stoull(feeling_s_s.substr(0,pos3));
					feeling_s_s.erase(0,pos3+1);

					pos4 = feeling_s_s.find(':');
					temp_max7 = std::stoull(feeling_s_s.substr(0,pos4));
					feeling_s_s.erase(0,pos4+1);

					pos5 = feeling_s_s.find(':');
					a7 = std::stod(feeling_s_s.substr(0,pos5));
					feeling_s_s.erase(0,pos5+1);

					pos6 = feeling_s_s.find(':');
					b7 = std::stod(feeling_s_s.substr(0,pos6));
					feeling_s_s.erase(0,pos6+1);

					pos7 = feeling_s_s.find(':');
					c7 = std::stod(feeling_s_s.substr(0,pos7));
					feeling_s_s.erase(0,pos7+1);

					pos8 = feeling_s_s.find(':');
					d7 = std::stod(feeling_s_s.substr(0,pos8));
					feeling_s_s.erase(0,pos8+1);

					pos9 = feeling_s_s.find(':');
					e7 = std::stod(feeling_s_s.substr(0,pos9));
					feeling_s_s.erase(0,pos9+1);

					pos10 = feeling_s_s.find(':');
					f7 = std::stod(feeling_s_s.substr(0,pos10));
					feeling_s_s.erase(0,pos10+1);

					pos11 = feeling_s_s.find(':');
					g7 = std::stod(feeling_s_s.substr(0,pos11));
					feeling_s_s.erase(0,pos11+1);

					h7 = std::stod(feeling_s_s.substr(0,-1));

					break;
				case 9:
					pos3 = feeling_s_s.find(':');
					temp_min8 = std::stoull(feeling_s_s.substr(0,pos3));
					feeling_s_s.erase(0,pos3+1);

					pos4 = feeling_s_s.find(':');
					temp_max8 = std::stoull(feeling_s_s.substr(0,pos4));
					feeling_s_s.erase(0,pos4+1);

					pos5 = feeling_s_s.find(':');
					a8 = std::stod(feeling_s_s.substr(0,pos5));
					feeling_s_s.erase(0,pos5+1);

					pos6 = feeling_s_s.find(':');
					b8 = std::stod(feeling_s_s.substr(0,pos6));
					feeling_s_s.erase(0,pos6+1);

					pos7 = feeling_s_s.find(':');
					c8 = std::stod(feeling_s_s.substr(0,pos7));
					feeling_s_s.erase(0,pos7+1);

					pos8 = feeling_s_s.find(':');
					d8 = std::stod(feeling_s_s.substr(0,pos8));
					feeling_s_s.erase(0,pos8+1);

					pos9 = feeling_s_s.find(':');
					e8 = std::stod(feeling_s_s.substr(0,pos9));
					feeling_s_s.erase(0,pos9+1);

					pos10 = feeling_s_s.find(':');
					f8 = std::stod(feeling_s_s.substr(0,pos10));
					feeling_s_s.erase(0,pos10+1);

					pos11 = feeling_s_s.find(':');
					g8 = std::stod(feeling_s_s.substr(0,pos11));
					feeling_s_s.erase(0,pos11+1);

					h8 = std::stod(feeling_s_s.substr(0,-1));

					break;
				}

				feeling_s.erase(0,pos2+1);
				n++;
			}
			testresponse.erase(0, pos+1);
			feelings.push_back(Feeling(feeling_name, feeling_desc,
										temp_min1,temp_max1,a1,b1,c1,d1,e1,f1,g1,h1,
										temp_min2,temp_max2,a2,b2,c2,d2,e2,f2,g2,h2,
										temp_min3,temp_max3,a3,b3,c3,d3,e3,f3,g3,h3,
										temp_min4,temp_max4,a4,b4,c4,d4,e4,f4,g4,h4,
										temp_min5,temp_max5,a5,b5,c5,d5,e5,f5,g5,h5,
										temp_min6,temp_max6,a6,b6,c6,d6,e6,f6,g6,h6,
										temp_min7,temp_max7,a7,b7,c7,d7,e7,f7,g7,h7,
										temp_min8,temp_max8,a8,b8,c8,d8,e8,f8,g8,h8));
		}

		return 0;
	}

	/*
	 * Request the global mood from the server
	 */
	Mood mood(){

		//TODO contact the server requesting the global mood data

		return Mood();
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
