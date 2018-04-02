//SHEILa======================================================================
// Name        : SHEILaCoreServer.cpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Apr 2, 2018
// Modified    :
//============================================================================

#include <Entity/Server/SHEILaCoreServer/SHEILaCoreServer.h>

namespace sheila {

SHEILaCoreServer::SHEILaCoreServer() {
	// TODO Auto-generated constructor stub

}

uintmax_t SHEILaCoreServer::getActiveRuntimes(){
	return 0;
}

std::vector<Feeling> SHEILaCoreServer::feelings(){
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

		ss << "-100.000000:+100.000000" << '\t';	// [Disgust] Sadness % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Disgust] Surprise % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Disgust] Fear % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Disgust] Trust % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Disgust] Joy % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Disgust] Anticipation % Diff

		ss << "-100.000000:+100.000000" << '\t';	// [Sadness] Surprise % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Sadness] Fear % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Sadness] Trust % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Sadness] Joy % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Sadness] Anticipation % Diff

		ss << "-100.000000:+100.000000" << '\t';	// [Surprise] Fear % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Surprise] Trust % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Surprise] Joy % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Surprise] Anticipation % Diff

		ss << "-100.000000:+100.000000" << '\t';	// [Fear] Trust % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Fear] Joy % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Fear] Anticipation % Diff

		ss << "-100.000000:+100.000000" << '\t';	// [Trust] Joy % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Trust] Anticipation % Diff

		ss << "-100.000000:+100.000000" << '\t';	// [Joy] Anticipation % Diff

		ss << '\n';

		ss << "Joy" << '\t';						// Name
		ss << "Feeling contented and joy" << '\t';	// Description

		ss << "000.0000000:066.666666666666666" << '\t';	// [Anger] lower bound : upper bound
		ss << "000.0000000:066.666666666666666" << '\t';	// [Disgust] lower bound : upper bound
		ss << "000.0000000:066.666666666666666" << '\t';	// [Sadness] lower bound : upper bound
		ss << "000.0000000:066.666666666666666" << '\t';	// [Surprise] lower bound : upper bound
		ss << "000.0000000:066.666666666666666" << '\t';	// [Fear] lower bound : upper bound
		ss << "000.0000000:066.666666666666666" << '\t';	// [Trust] lower bound : upper bound
		ss << "033.3333333:066.666666666666666" << '\t';	// [Joy] lower bound : upper bound
		ss << "000.0000000:066.666666666666666" << '\t';	// [Anticipation] lower bound : upper bound

		ss << "-100.000000:+100.000000" << '\t';	// [Anger] Disgust % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Anger] Sadness % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Anger] Surprise % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Anger] Fear % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Anger] Trust % Diff
		ss << "-100.000000:-020.000000" << '\t';	// [Anger] Joy % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Anger] Anticipation % Diff

		ss << "-100.000000:+100.000000" << '\t';	// [Disgust] Sadness % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Disgust] Surprise % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Disgust] Fear % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Disgust] Trust % Diff
		ss << "-100.000000:-020.000000" << '\t';	// [Disgust] Joy % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Disgust] Anticipation % Diff

		ss << "-100.000000:+100.000000" << '\t';	// [Sadness] Surprise % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Sadness] Fear % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Sadness] Trust % Diff
		ss << "-100.000000:-020.000000" << '\t';	// [Sadness] Joy % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Sadness] Anticipation % Diff

		ss << "-100.000000:+100.000000" << '\t';	// [Surprise] Fear % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Surprise] Trust % Diff
		ss << "-100.000000:-020.000000" << '\t';	// [Surprise] Joy % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Surprise] Anticipation % Diff

		ss << "-100.000000:+100.000000" << '\t';	// [Fear] Trust % Diff
		ss << "-100.000000:-020.000000" << '\t';	// [Fear] Joy % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Fear] Anticipation % Diff

		ss << "-100.000000:-020.000000" << '\t';	// [Trust] Joy % Diff
		ss << "-100.000000:+100.000000" << '\t';	// [Trust] Anticipation % Diff

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

			long double temp_min1,temp_min2,temp_min3,temp_min4,temp_min5,temp_min6,temp_min7,temp_min8;
			long double temp_max1,temp_max2,temp_max3,temp_max4,temp_max5,temp_max6,temp_max7,temp_max8;

			std::vector<long double> diffs;


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
					temp_min1 = std::stold(feeling_s_s.substr(0,pos3));
					temp_max1 = std::stold(feeling_s_s.substr(pos3+1));
					break;
				case 3:
					pos3 = feeling_s_s.find(':');
					temp_min2 = std::stold(feeling_s_s.substr(0,pos3));
					temp_max2 = std::stold(feeling_s_s.substr(pos3+1));
					break;
				case 4:
					pos3 = feeling_s_s.find(':');
					temp_min3 = std::stold(feeling_s_s.substr(0,pos3));
					temp_max3 = std::stold(feeling_s_s.substr(pos3+1));
					break;
				case 5:
					pos3 = feeling_s_s.find(':');
					temp_min4 = std::stold(feeling_s_s.substr(0,pos3));
					temp_max4 = std::stold(feeling_s_s.substr(pos3+1));
					break;
				case 6:
					pos3 = feeling_s_s.find(':');
					temp_min5 = std::stold(feeling_s_s.substr(0,pos3));
					temp_max5 = std::stold(feeling_s_s.substr(pos3+1));
					break;
				case 7:
					pos3 = feeling_s_s.find(':');
					temp_min6 = std::stold(feeling_s_s.substr(0,pos3));
					temp_max6 = std::stold(feeling_s_s.substr(pos3+1));
					break;
				case 8:
					pos3 = feeling_s_s.find(':');
					temp_min7 = std::stold(feeling_s_s.substr(0,pos3));
					temp_max7 = std::stold(feeling_s_s.substr(pos3+1));
					break;
				case 9:
					pos3 = feeling_s_s.find(':');
					temp_min8 = std::stold(feeling_s_s.substr(0,pos3));
					temp_max8 = std::stold(feeling_s_s.substr(pos3+1));
					break;
				default:
					pos3 = feeling_s_s.find(':');
					diffs.push_back(std::stold(feeling_s_s.substr(0,pos3)));
					diffs.push_back(std::stold(feeling_s_s.substr(pos3+1)));
					break;
				}

				feeling_s.erase(0,pos2+1);
				n++;
			}
			testresponse.erase(0, pos+1);
			temp_feelings.push_back(Feeling(feeling_name, feeling_desc,
										temp_min1,temp_max1,
										temp_min2,temp_max2,
										temp_min3,temp_max3,
										temp_min4,temp_max4,
										temp_min5,temp_max5,
										temp_min6,temp_max6,
										temp_min7,temp_max7,
										temp_min8,temp_max8,
										 diffs[0],  diffs[1],
										 diffs[2],  diffs[3],
										 diffs[4],  diffs[5],
										 diffs[6],  diffs[7],
										 diffs[8],  diffs[9],
										 diffs[10],  diffs[11],
										 diffs[12],  diffs[13],
										 diffs[14],  diffs[15],
										 diffs[16],  diffs[17],
										 diffs[18],  diffs[19],
										 diffs[20],  diffs[21],
										 diffs[22],  diffs[23],
										 diffs[24],	 diffs[25],
										 diffs[26],  diffs[27],
										 diffs[28],  diffs[29],
										 diffs[30],  diffs[31],
										 diffs[32],  diffs[33],
										 diffs[34],  diffs[35],
										 diffs[36],  diffs[37],
										 diffs[38],  diffs[39],
										 diffs[40],  diffs[41],
										 diffs[42],  diffs[43],
										 diffs[44],  diffs[45],
										 diffs[46],  diffs[47],
										 diffs[48],  diffs[49],
										 diffs[50],  diffs[51],
										 diffs[52],  diffs[53],
										 diffs[54],  diffs[55]));
		}

		return temp_feelings;
}

Mood SHEILaCoreServer::mood(){
	//TODO contact the server requesting the global mood data

	std::stringstream ss;

	ss << "0.0:0.0:0.0:0.0:0.0:0.0:0.0:300.0" << std::endl;

	std::string testresponse = ss.str();

	long double temp_anger;
	long double temp_disgust;
	long double temp_sadness;
	long double temp_surprise;
	long double temp_fear;
	long double temp_trust;
	long double temp_joy;
	long double temp_anticipation;

	size_t pos;
	int n=0;
	std::string mood_s;
	while ((pos = testresponse.find(':')) != std::string::npos){
		mood_s = testresponse.substr(0,pos);
		switch(n){
		case 0:
			temp_anger = stold(mood_s);
			break;
		case 1:
			temp_disgust = stold(mood_s);
			break;
		case 2:
			temp_sadness = stold(mood_s);
			break;
		case 3:
			temp_surprise = stold(mood_s);
			break;
		case 4:
			temp_fear = stold(mood_s);
			break;
		case 5:
			temp_trust = stold(mood_s);
			break;
		case 6:
			temp_joy = stold(mood_s);
			break;
		}
		testresponse.erase(0,pos+1);
		n++;
	}
	temp_anticipation = stold(testresponse);

	return Mood(temp_anger,temp_disgust,temp_sadness,temp_surprise,temp_fear,temp_trust,temp_joy,temp_anticipation);
}

SHEILaCoreServer::~SHEILaCoreServer() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */
