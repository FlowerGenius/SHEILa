//SHEILa======================================================================
// Name        : Mood.cpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 19, 2018
// Modified    :
//============================================================================

#include <Entity/Mood/Mood.h>
#include <Entity/Server/SHEILaCoreServer/SHEILaCoreServer.h>

namespace sheila {

	std::string em(int i){
		switch(i){
		case -1:
			return "Range";
		case 0:
			return "Anger";
		case 1:
			return "Disgust";
		case 2:
			return "Sadness";
		case 3:
			return "Surprise";
		case 4:
			return "Fear";
		case 5:
			return "Trust";
		case 6:
			return "Joy";
		case 7:
			return "Anticipation";
		default:
			return "Undefined";
		}

	}

	enum {
			ANGER,
			DISGUST,
			SADNESS,
			SURPRISE,
			FEAR,
			TRUST,
			JOY,
			ANTICIPATION
		};


Mood::Mood() {
}

Mood::Mood(long double anger, long double disgust, long double sadness,
		long double surprise, long double fear, long double trust, long double joy,
		long double anticipation) {
	this->anger 		= Emotion(anger);
	this->disgust 		= Emotion(disgust);
	this->sadness 		= Emotion(sadness);
	this->surprise 		= Emotion(surprise);
	this->fear 			= Emotion(fear);
	this->trust 		= Emotion(trust);
	this->joy 			= Emotion(joy);
	this->anticipation 	= Emotion(anticipation);
}

long double Mood::getAngerStrength(void) {
	return this->anger.getStrength();
}

void Mood::setAnger(long double anger) {
	this->anger.setStrength(anger);
}

long double Mood::getDisgustStrength(void) {
	return this->disgust.getStrength();
}

void Mood::setDisgust(long double disgust) {
	this->disgust.setStrength(disgust);
}

long double Mood::getSadnessStrength(void) {
	return this->sadness.getStrength();
}

void Mood::setSadness(long double sadness) {
	this->sadness.setStrength(sadness);
}

long double Mood::getSurpriseStrength(void) {
	return this->surprise.getStrength();
}

void Mood::setSurprise(long double surprise) {
	this->surprise.setStrength(surprise);
}

long double Mood::getFearStrength(void) {
	return this->fear.getStrength();
}

void Mood::setFear(long double fear) {
	this->fear.setStrength(fear);
}

long double Mood::getTrustStrength(void) {
	return this->trust.getStrength();
}

void Mood::setTrust(long double trust) {
	this->trust.setStrength(trust);
}

long double Mood::getJoyStrength(void) {
	return this->joy.getStrength();
}

void Mood::setJoy(long double joy) {
	this->joy.setStrength(joy);
}

long double Mood::getAnticipationStrength(void) {
	return this->anticipation.getStrength();
}

void Mood::setAnticipation(long double anticipation) {
	this->anticipation.setStrength(anticipation);
}

// A feeling represents a set of 8 ranges, one for each emotion,
// if the current emotional state lies within one of the predefined ranges
// then SHEILa is experiencing that feeling
std::string Mood::getFeeling() {

	bool match,atleast,atmost,inrange;

	std::vector<long double> temp_emotions = {
			getAngerStrength(),
			getDisgustStrength(),
			getSadnessStrength(),
			getSurpriseStrength(),
			getFearStrength(),
			getTrustStrength(),
			getJoyStrength(),
			getAnticipationStrength()
	};

	std::vector<Feeling> temp_feelings = SHEILaCoreServer::feelings();
	std::vector<Feeling> allfeelings;

	for (std::vector<Feeling>::iterator it = temp_feelings.begin(); it != temp_feelings.end(); ++it) {

		match = true;

		for (char i = 0; i <= 7;i++){

			switch(i){
			case ANGER:
				inrange = (*it).ang_range.contains(getAngerStrength());
				break;
			case DISGUST:
				inrange = (*it).dis_range.contains(getDisgustStrength());
				break;
			case SADNESS:
				inrange = (*it).sad_range.contains(getSadnessStrength());
				break;
			case SURPRISE:
				inrange = (*it).sur_range.contains(getSurpriseStrength());
				break;
			case FEAR:
				inrange = (*it).fea_range.contains(getFearStrength());
				break;
			case TRUST:
				inrange = (*it).tru_range.contains(getTrustStrength());
				break;
			case JOY:
				inrange = (*it).joy_range.contains(getJoyStrength());
				break;
			case ANTICIPATION:
				inrange = (*it).ant_range.contains(getAnticipationStrength());
				break;
			}

			for (char n = 0; n <= 7;n++){
				if (i!=n){

					atleast = (temp_emotions[i]  >= temp_emotions[n] + (*it).getDiff(i,n).first);
					atmost  = (temp_emotions[i]  <= temp_emotions[n] + (*it).getDiff(i,n).second);

					if ( !atleast || !atmost || !inrange){
						match = false;
					}
				}
			}
		}

		if (match) {
			allfeelings.push_back(*it);
		}

	}

	if (allfeelings.size() == 1){
		return allfeelings.at(0).getName();
	} else {
		return "I don't know";
	}
}

Mood::~Mood() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */
