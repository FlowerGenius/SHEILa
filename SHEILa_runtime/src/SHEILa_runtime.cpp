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
#include <atomic>


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

/*
 * Return true if a is at least n% different from b on the interval [lower_bound,upper_bound]
 */
bool percent_diff(double a ,double b ,double n ,double lower_bound,double upper_bound){

//	std::cout << ad << '\t' << bd << '\t' << lo << '\t' << hi << std::endl;


	if (n >= 0.0) { // n is a positive double
		if (((((a - b) - lower_bound) / upper_bound) * 100.0) >= n) {
			return true;
		}
	} else { // n is a negative double
		if (((((a - b) - lower_bound) / upper_bound) * 100.0) <= n) {
			return true;
		}
	}


	return false;
}



//Information about the central server this runtime will interface with
namespace server {

	std::atomic_bool FEELING_AVAILABLE;
	std::atomic_bool ACTIVE;

	std::atomic_uintmax_t active_runtimes;

	const char* IPv4 = "";
	const char* IPv6 = "";
	const char* MAC	 = "";

//	std::vector<Feeling> __feelings;


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
	std::vector<Feeling> feelings(){

		//TODO contact the server requesting all of the feelings one line at a time

		std::vector<Feeling> temp_feelings;

		std::stringstream ss;

		ss << "Anger" << '\t';						// Name
		ss << "Feeling heated and upset" << '\t';	// Description

		ss << "033.3333333:066.6666666" << '\t';	// [Anger] lower bound : upper bound
		ss << "000.0000000:066.6666666" << '\t';	// [Disgust] lower bound : upper bound
		ss << "000.0000000:066.6666666" << '\t';	// [Sadness] lower bound : upper bound
		ss << "000.0000000:066.6666666" << '\t';	// [Surprise] lower bound : upper bound
		ss << "000.0000000:066.6666666" << '\t';	// [Fear] lower bound : upper bound
		ss << "000.0000000:066.6666666" << '\t';	// [Trust] lower bound : upper bound
		ss << "000.0000000:066.6666666" << '\t';	// [Joy] lower bound : upper bound
		ss << "000.0000000:066.6666666" << '\t';	// [Anticipation] lower bound : upper bound

		ss << "+020.000000:+100.000000" << '\t';	// [Anger] Disgust % Diff
		ss << "+020.000000:+100.000000" << '\t';	// [Anger] Sadness % Diff
		ss << "+020.000000:+100.000000" << '\t';	// [Anger] Surprise % Diff
		ss << "+020.000000:+100.000000" << '\t';	// [Anger] Fear % Diff
		ss << "+020.000000:+100.000000" << '\t';	// [Anger] Trust % Diff
		ss << "+020.000000:+100.000000" << '\t';	// [Anger] Joy % Diff
		ss << "+020.000000:+100.000000" << '\t';	// [Anger] Anticipation % Diff

		ss << "+000.000000:+100.000000" << '\t';	// [Disgust] Sadness % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Disgust] Surprise % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Disgust] Fear % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Disgust] Trust % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Disgust] Joy % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Disgust] Anticipation % Diff

		ss << "+000.000000:+100.000000" << '\t';	// [Sadness] Surprise % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Sadness] Fear % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Sadness] Trust % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Sadness] Joy % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Sadness] Anticipation % Diff

		ss << "+000.000000:+100.000000" << '\t';	// [Surprise] Fear % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Surprise] Trust % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Surprise] Joy % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Surprise] Anticipation % Diff

		ss << "+000.000000:+100.000000" << '\t';	// [Fear] Trust % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Fear] Joy % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Fear] Anticipation % Diff

		ss << "+000.000000:+100.000000" << '\t';	// [Trust] Joy % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Trust] Anticipation % Diff

		ss << "+000.000000:+100.000000" << '\t';	// [Joy] Anticipation % Diff

		ss << '\n';

		ss << "Joy" << '\t';						// Name
		ss << "Feeling contented and joy" << '\t';	// Description

		ss << "000.0000000:066.6666666" << '\t';	// [Anger] lower bound : upper bound
		ss << "000.0000000:066.6666666" << '\t';	// [Disgust] lower bound : upper bound
		ss << "000.0000000:066.6666666" << '\t';	// [Sadness] lower bound : upper bound
		ss << "000.0000000:066.6666666" << '\t';	// [Surprise] lower bound : upper bound
		ss << "000.0000000:066.6666666" << '\t';	// [Fear] lower bound : upper bound
		ss << "000.0000000:066.6666666" << '\t';	// [Trust] lower bound : upper bound
		ss << "033.3333333:066.6666666" << '\t';	// [Joy] lower bound : upper bound
		ss << "000.0000000:066.6666666" << '\t';	// [Anticipation] lower bound : upper bound

		ss << "+000.000000:+100.000000" << '\t';	// [Anger] Disgust % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Anger] Sadness % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Anger] Surprise % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Anger] Fear % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Anger] Trust % Diff
		ss << "-020.000000:+100.000000" << '\t';	// [Anger] Joy % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Anger] Anticipation % Diff

		ss << "+000.000000:+100.000000" << '\t';	// [Disgust] Sadness % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Disgust] Surprise % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Disgust] Fear % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Disgust] Trust % Diff
		ss << "-020.000000:+100.000000" << '\t';	// [Disgust] Joy % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Disgust] Anticipation % Diff

		ss << "+000.000000:+100.000000" << '\t';	// [Sadness] Surprise % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Sadness] Fear % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Sadness] Trust % Diff
		ss << "-020.000000:+100.000000" << '\t';	// [Sadness] Joy % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Sadness] Anticipation % Diff

		ss << "+000.000000:+100.000000" << '\t';	// [Surprise] Fear % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Surprise] Trust % Diff
		ss << "-020.000000:+100.000000" << '\t';	// [Surprise] Joy % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Surprise] Anticipation % Diff

		ss << "+000.000000:+100.000000" << '\t';	// [Fear] Trust % Diff
		ss << "-020.000000:+100.000000" << '\t';	// [Fear] Joy % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Fear] Anticipation % Diff

		ss << "-020.000000:+100.000000" << '\t';	// [Trust] Joy % Diff
		ss << "+000.000000:+100.000000" << '\t';	// [Trust] Anticipation % Diff

		ss << "+020.000000:+100.000000" << '\t';	// [Joy] Anticipation % Diff

		ss << '\n';

		std::string testresponse = ss.str();

		//TODO Check if there are feelings waiting on the server

//		if (!FEELING_AVAILABLE) {
//			return Feeling::feelings;
//		} else {
//			Feeling::feelings.clear();
//		}

		size_t pos;
		std::string feeling_s;
		while ((pos = testresponse.find('\n')) != std::string::npos){

			std::string feeling_name;
			std::string feeling_desc;

			double temp_min1,temp_min2,temp_min3,temp_min4,temp_min5,temp_min6,temp_min7,temp_min8;
			double temp_max1,temp_max2,temp_max3,temp_max4,temp_max5,temp_max6,temp_max7,temp_max8;

			double min_diff_ang_dis = 0.0 ; double max_diff_ang_dis = 0.0 ;
			double min_diff_ang_sad = 0.0 ; double max_diff_ang_sad = 0.0 ;
			double min_diff_ang_sur = 0.0 ; double max_diff_ang_sur = 0.0 ;
			double min_diff_ang_fea = 0.0 ; double max_diff_ang_fea = 0.0 ;
			double min_diff_ang_tru = 0.0 ; double max_diff_ang_tru = 0.0 ;
			double min_diff_ang_joy = 0.0 ; double max_diff_ang_joy = 0.0 ;
			double min_diff_ang_ant = 0.0 ; double max_diff_ang_ant = 0.0 ;
			double min_diff_dis_sad = 0.0 ; double max_diff_dis_sad = 0.0 ;
			double min_diff_dis_sur = 0.0 ; double max_diff_dis_sur = 0.0 ;
			double min_diff_dis_fea = 0.0 ; double max_diff_dis_fea = 0.0 ;
			double min_diff_dis_tru = 0.0 ; double max_diff_dis_tru = 0.0 ;
			double min_diff_dis_joy = 0.0 ; double max_diff_dis_joy = 0.0 ;
			double min_diff_dis_ant = 0.0 ; double max_diff_dis_ant = 0.0 ;
			double min_diff_sad_sur = 0.0 ; double max_diff_sad_sur = 0.0 ;
			double min_diff_sad_fea = 0.0 ; double max_diff_sad_fea = 0.0 ;
			double min_diff_sad_tru = 0.0 ; double max_diff_sad_tru = 0.0 ;
			double min_diff_sad_joy = 0.0 ; double max_diff_sad_joy = 0.0 ;
			double min_diff_sad_ant = 0.0 ; double max_diff_sad_ant = 0.0 ;
			double min_diff_sur_fea = 0.0 ; double max_diff_sur_fea = 0.0 ;
			double min_diff_sur_tru = 0.0 ; double max_diff_sur_tru = 0.0 ;
			double min_diff_sur_joy = 0.0 ; double max_diff_sur_joy = 0.0 ;
			double min_diff_sur_ant = 0.0 ; double max_diff_sur_ant = 0.0 ;
			double min_diff_fea_tru = 0.0 ; double max_diff_fea_tru = 0.0 ;
			double min_diff_fea_joy = 0.0 ; double max_diff_fea_joy = 0.0 ;
			double min_diff_fea_ant = 0.0 ; double max_diff_fea_ant = 0.0 ;
			double min_diff_tru_joy = 0.0 ; double max_diff_tru_joy = 0.0 ;
			double min_diff_tru_ant = 0.0 ; double max_diff_tru_ant = 0.0 ;
			double min_diff_joy_ant = 0.0 ; double max_diff_joy_ant = 0.0 ;

			double diffs[] = {
					 min_diff_ang_dis,  max_diff_ang_dis,
					 min_diff_ang_sad,  max_diff_ang_sad,
					 min_diff_ang_sur,  max_diff_ang_sur,
					 min_diff_ang_fea,  max_diff_ang_fea,
					 min_diff_ang_tru,  max_diff_ang_tru,
					 min_diff_ang_joy,  max_diff_ang_joy,
					 min_diff_ang_ant,  max_diff_ang_ant,
					 min_diff_dis_sad,  max_diff_dis_sad,
					 min_diff_dis_sur,  max_diff_dis_sur,
					 min_diff_dis_fea,  max_diff_dis_fea,
					 min_diff_dis_tru,  max_diff_dis_tru,
					 min_diff_dis_joy,  max_diff_dis_joy,
					 min_diff_dis_ant,  max_diff_dis_ant,
					 min_diff_sad_sur,  max_diff_sad_sur,
					 min_diff_sad_fea,  max_diff_sad_fea,
					 min_diff_sad_tru,  max_diff_sad_tru,
					 min_diff_sad_joy,  max_diff_sad_joy,
					 min_diff_sad_ant,  max_diff_sad_ant,
					 min_diff_sur_fea,  max_diff_sur_fea,
					 min_diff_sur_tru,  max_diff_sur_tru,
					 min_diff_sur_joy,  max_diff_sur_joy,
					 min_diff_sur_ant,  max_diff_sur_ant,
					 min_diff_fea_tru,  max_diff_fea_tru,
					 min_diff_fea_joy,  max_diff_fea_joy,
					 min_diff_fea_ant,  max_diff_fea_ant,
					 min_diff_tru_joy,  max_diff_tru_joy,
					 min_diff_tru_ant,  max_diff_tru_ant,
					 min_diff_joy_ant,  max_diff_joy_ant
			};


			feeling_s = testresponse.substr(0, pos);
			size_t pos2;
			std::string feeling_s_s;
			int n = 0;
			while ((pos2 = feeling_s.find('\t')) != std::string::npos){
				feeling_s_s = feeling_s.substr(0,pos2);
				size_t pos3;
				switch(n){
				case 0:
					feeling_name = feeling_s_s;
					break;
				case 1:
					feeling_desc = feeling_s_s;
					break;
				case 2:
					pos3 = feeling_s_s.find(':');
					temp_min1 = std::stod(feeling_s_s.substr(0,pos3));
					temp_max1 = std::stod(feeling_s_s.substr(pos3+1));
					break;
				case 3:
					pos3 = feeling_s_s.find(':');
					temp_min2 = std::stod(feeling_s_s.substr(0,pos3));
					temp_max2 = std::stod(feeling_s_s.substr(pos3+1));
					break;
				case 4:
					pos3 = feeling_s_s.find(':');
					temp_min3 = std::stod(feeling_s_s.substr(0,pos3));
					temp_max3 = std::stod(feeling_s_s.substr(pos3+1));
					break;
				case 5:
					pos3 = feeling_s_s.find(':');
					temp_min4 = std::stod(feeling_s_s.substr(0,pos3));
					temp_max4 = std::stod(feeling_s_s.substr(pos3+1));
					break;
				case 6:
					pos3 = feeling_s_s.find(':');
					temp_min5 = std::stod(feeling_s_s.substr(0,pos3));
					temp_max5 = std::stod(feeling_s_s.substr(pos3+1));
					break;
				case 7:
					pos3 = feeling_s_s.find(':');
					temp_min6 = std::stod(feeling_s_s.substr(0,pos3));
					temp_max6 = std::stod(feeling_s_s.substr(pos3+1));
					break;
				case 8:
					pos3 = feeling_s_s.find(':');
					temp_min7 = std::stod(feeling_s_s.substr(0,pos3));
					temp_max7 = std::stod(feeling_s_s.substr(pos3+1));
					break;
				case 9:
					pos3 = feeling_s_s.find(':');
					temp_min8 = std::stod(feeling_s_s.substr(0,pos3));
					temp_max8 = std::stod(feeling_s_s.substr(pos3+1));
					break;
				default:
					pos3 = feeling_s_s.find(':');
					diffs[n-10] = std::stod(feeling_s_s.substr(0,pos3));
					diffs[n-9]	= std::stod(feeling_s_s.substr(pos3+1));
					break;
				}

				feeling_s.erase(0,pos2+1);
				n++;
			}
			testresponse.erase(0, pos+1);
			temp_feelings.push_back(Feeling(feeling_name, feeling_desc,
										(temp_min1 / 100.0) * UINTMAX_MAX,(temp_max1 / 100.0) * UINTMAX_MAX,
										(temp_min2 / 100.0) * UINTMAX_MAX,(temp_max2 / 100.0) * UINTMAX_MAX,
										(temp_min3 / 100.0) * UINTMAX_MAX,(temp_max3 / 100.0) * UINTMAX_MAX,
										(temp_min4 / 100.0) * UINTMAX_MAX,(temp_max4 / 100.0) * UINTMAX_MAX,
										(temp_min5 / 100.0) * UINTMAX_MAX,(temp_max5 / 100.0) * UINTMAX_MAX,
										(temp_min6 / 100.0) * UINTMAX_MAX,(temp_max6 / 100.0) * UINTMAX_MAX,
										(temp_min7 / 100.0) * UINTMAX_MAX,(temp_max7 / 100.0) * UINTMAX_MAX,
										(temp_min8 / 100.0) * UINTMAX_MAX,(temp_max8 / 100.0) * UINTMAX_MAX,
										 min_diff_ang_dis,  max_diff_ang_dis,
										 min_diff_ang_sad,  max_diff_ang_sad,
										 min_diff_ang_sur,  max_diff_ang_sur,
										 min_diff_ang_fea,  max_diff_ang_fea,
										 min_diff_ang_tru,  max_diff_ang_tru,
										 min_diff_ang_joy,  max_diff_ang_joy,
										 min_diff_ang_ant,  max_diff_ang_ant,
										 min_diff_dis_sad,  max_diff_dis_sad,
										 min_diff_dis_sur,  max_diff_dis_sur,
										 min_diff_dis_fea,  max_diff_dis_fea,
										 min_diff_dis_tru,  max_diff_dis_tru,
										 min_diff_dis_joy,  max_diff_dis_joy,
										 min_diff_dis_ant,  max_diff_dis_ant,
										 min_diff_sad_sur,  max_diff_sad_sur,
										 min_diff_sad_fea,  max_diff_sad_fea,
										 min_diff_sad_tru,  max_diff_sad_tru,
										 min_diff_sad_joy,  max_diff_sad_joy,
										 min_diff_sad_ant,  max_diff_sad_ant,
										 min_diff_sur_fea,  max_diff_sur_fea,
										 min_diff_sur_tru,  max_diff_sur_tru,
										 min_diff_sur_joy,  max_diff_sur_joy,
										 min_diff_sur_ant,  max_diff_sur_ant,
										 min_diff_fea_tru,  max_diff_fea_tru,
										 min_diff_fea_joy,  max_diff_fea_joy,
										 min_diff_fea_ant,  max_diff_fea_ant,
										 min_diff_tru_joy,  max_diff_tru_joy,
										 min_diff_tru_ant,  max_diff_tru_ant,
										 min_diff_joy_ant,  max_diff_joy_ant));
		}

		return temp_feelings;
	}

	/*
	 * Request the global mood from the server
	 */
	Mood mood(){

		//TODO contact the server requesting the global mood data

		std::stringstream ss;

		ss << "0.0:0.0:0.0:0.0:0.0:0.0:0.0:300.0" << std::endl;

		std::string testresponse = ss.str();

		uintmax_t temp_anger;
		uintmax_t temp_disgust;
		uintmax_t temp_sadness;
		uintmax_t temp_surprise;
		uintmax_t temp_fear;
		uintmax_t temp_trust;
		uintmax_t temp_joy;
		uintmax_t temp_anticipation;

		size_t pos;
		int n=0;
		std::string mood_s;
		while ((pos = testresponse.find(':')) != std::string::npos){
			mood_s = testresponse.substr(0,pos);
			switch(n){
			case 0:
				temp_anger = stouintmax(mood_s);
				break;
			case 1:
				temp_disgust = stouintmax(mood_s);
				break;
			case 2:
				temp_sadness = stouintmax(mood_s);
				break;
			case 3:
				temp_surprise = stouintmax(mood_s);
				break;
			case 4:
				temp_fear = stouintmax(mood_s);
				break;
			case 5:
				temp_trust = stouintmax(mood_s);
				break;
			case 6:
				temp_joy = stouintmax(mood_s);
				break;
			}
			testresponse.erase(0,pos+1);
			n++;
		}
		temp_anticipation = stouintmax(testresponse);

		return Mood(temp_anger,temp_disgust,temp_sadness,temp_surprise,temp_fear,temp_trust,temp_joy,temp_anticipation);
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

	sheila::runtime::mood.setJoy(UINTMAX_MAX / 2);
	sheila::runtime::mood.setTrust((UINTMAX_MAX / 2) - 300);

	std::cout << sheila::runtime::mood.getFeeling() << std::endl;
	while (sheila::runtime::active && sheila::platform::active){
		sheila::runtime::active = false;
	}
	return 0;
}
