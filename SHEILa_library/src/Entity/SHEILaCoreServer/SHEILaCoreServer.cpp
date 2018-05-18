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

#include "Entity/SHEILaCoreServer.hpp"

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

			feeling_s = testresponse.substr(0, pos);
			Feeling f;
			f._E_eval(feeling_s);
			temp_feelings.push_back(f);
			testresponse.erase(0, pos+1);

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

	return Mood({temp_anger,temp_disgust,temp_sadness,temp_surprise,temp_fear,temp_trust,temp_joy,temp_anticipation});
}

SHEILaCoreServer::~SHEILaCoreServer() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */
