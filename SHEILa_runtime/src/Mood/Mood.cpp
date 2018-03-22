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

#include "Mood.h"

namespace sheila {
	extern bool percent_diff(double a ,double b ,double n ,double lower_bound,double upper_bound);

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

namespace server {
	extern std::vector<Feeling> feelings();
}


Mood::Mood() {
}

Mood::Mood(uintmax_t anger, uintmax_t disgust, uintmax_t sadness,
		uintmax_t surprise, uintmax_t fear, uintmax_t trust, uintmax_t joy,
		uintmax_t anticipation) {
	this->anger = Anger(anger);
	this->disgust = Disgust(disgust);
	this->sadness = Sadness(sadness);
	this->surprise = Surprise(surprise);
	this->fear = Fear(fear);
	this->trust = Trust(trust);
	this->joy = Joy(joy);
	this->anticipation = Anticipation(anticipation);
}

uintmax_t Mood::getAngerStrength(void) {
	return this->anger.getStrength();
}

void Mood::setAnger(uintmax_t anger) {
	this->anger.setStrength(anger);
}

uintmax_t Mood::getDisgustStrength(void) {
	return this->disgust.getStrength();
}

void Mood::setDisgust(uintmax_t disgust) {
	this->disgust.setStrength(disgust);
}

uintmax_t Mood::getSadnessStrength(void) {
	return this->sadness.getStrength();
}

void Mood::setSadness(uintmax_t sadness) {
	this->sadness.setStrength(sadness);
}

uintmax_t Mood::getSurpriseStrength(void) {
	return this->surprise.getStrength();
}

void Mood::setSurprise(uintmax_t surprise) {
	this->surprise.setStrength(surprise);
}

uintmax_t Mood::getFearStrength(void) {
	return this->fear.getStrength();
}

void Mood::setFear(uintmax_t fear) {
	this->fear.setStrength(fear);
}

uintmax_t Mood::getTrustStrength(void) {
	return this->trust.getStrength();
}

void Mood::setTrust(uintmax_t trust) {
	this->trust.setStrength(trust);
}

uintmax_t Mood::getJoyStrength(void) {
	return this->joy.getStrength();
}

void Mood::setJoy(uintmax_t joy) {
	this->joy.setStrength(joy);
}

uintmax_t Mood::getAnticipationStrength(void) {
	return this->anticipation.getStrength();
}

void Mood::setAnticipation(uintmax_t anticipation) {
	this->anticipation.setStrength(anticipation);
}

// A feeling represents a set of 8 ranges, one for each emotion,
// if the current emotional state lies within one of the predefined ranges
// then SHEILa is experiencing that feeling
std::string Mood::getFeeling() {

	std::vector<uintmax_t> temp_emotions = {
			getAngerStrength(),
			getDisgustStrength(),
			getSadnessStrength(),
			getSurpriseStrength(),
			getFearStrength(),
			getTrustStrength(),
			getJoyStrength(),
			getAnticipationStrength()
	};

	std::vector<Feeling> temp_feelings = server::feelings();
	std::vector<Feeling> allfeelings;

	for (std::vector<Feeling>::iterator it = temp_feelings.begin(); it != temp_feelings.end(); ++it) {
		bool match = true;

		std::vector<Range> temp_ranges = {
				(*it).ang_range,
				(*it).dis_range,
				(*it).sad_range,
				(*it).sur_range,
				(*it).fea_range,
				(*it).tru_range,
				(*it).joy_range,
				(*it).ant_range
		};

//		bool test[8][9]{
//			{
//				(*it).anger_range.contains(temp_emotions[ANGER]),
//				sheila::percent_diff(temp_emotions[ANGER],temp_emotions[ANGER],(*it).a(1),temp_ranges[ANGER].lo(),temp_ranges[ANGER].hi()),
//				sheila::percent_diff(temp_emotions[ANGER],temp_emotions[DISGUST],(*it).b(1),temp_ranges[ANGER].lo(),temp_ranges[ANGER].hi()),
//				sheila::percent_diff(temp_emotions[ANGER],temp_emotions[SADNESS],(*it).c(1),temp_ranges[ANGER].lo(),temp_ranges[ANGER].hi()),
//				sheila::percent_diff(temp_emotions[ANGER],temp_emotions[SURPRISE],(*it).d(1),temp_ranges[ANGER].lo(),temp_ranges[ANGER].hi()),
//				sheila::percent_diff(temp_emotions[ANGER],temp_emotions[FEAR],(*it).e(1),temp_ranges[ANGER].lo(),temp_ranges[ANGER].hi()),
//				sheila::percent_diff(temp_emotions[ANGER],temp_emotions[TRUST],(*it).f(1),temp_ranges[ANGER].lo(),temp_ranges[ANGER].hi()),
//				sheila::percent_diff(temp_emotions[ANGER],temp_emotions[JOY],(*it).g(1),temp_ranges[ANGER].lo(),temp_ranges[ANGER].hi()),
//				sheila::percent_diff(temp_emotions[ANGER],temp_emotions[ANTICIPATION],(*it).h(1),temp_ranges[ANGER].lo(),temp_ranges[ANGER].hi())
//			},
//			{
//				(*it).disgust_range.contains(temp_emotions[DISGUST]),
//				sheila::percent_diff(temp_emotions[DISGUST],temp_emotions[ANGER],(*it).a(2),temp_ranges[DISGUST].lo(),temp_ranges[DISGUST].hi()),
//				sheila::percent_diff(temp_emotions[DISGUST],temp_emotions[DISGUST],(*it).b(2),temp_ranges[DISGUST].lo(),temp_ranges[DISGUST].hi()),
//				sheila::percent_diff(temp_emotions[DISGUST],temp_emotions[SADNESS],(*it).c(2),temp_ranges[DISGUST].lo(),temp_ranges[DISGUST].hi()),
//				sheila::percent_diff(temp_emotions[DISGUST],temp_emotions[SURPRISE],(*it).d(2),temp_ranges[DISGUST].lo(),temp_ranges[DISGUST].hi()),
//				sheila::percent_diff(temp_emotions[DISGUST],temp_emotions[FEAR],(*it).e(2),temp_ranges[DISGUST].lo(),temp_ranges[DISGUST].hi()),
//				sheila::percent_diff(temp_emotions[DISGUST],temp_emotions[TRUST],(*it).f(2),temp_ranges[DISGUST].lo(),temp_ranges[DISGUST].hi()),
//				sheila::percent_diff(temp_emotions[DISGUST],temp_emotions[JOY],(*it).g(2),temp_ranges[DISGUST].lo(),temp_ranges[DISGUST].hi()),
//				sheila::percent_diff(temp_emotions[DISGUST],temp_emotions[ANTICIPATION],(*it).h(2),temp_ranges[DISGUST].lo(),temp_ranges[DISGUST].hi())
//			},
//			{
//				(*it).sadness_range.contains(temp_emotions[SADNESS]),
//				sheila::percent_diff(temp_emotions[SADNESS],temp_emotions[ANGER],(*it).a(3),temp_ranges[SADNESS].lo(),temp_ranges[SADNESS].hi()),
//				sheila::percent_diff(temp_emotions[SADNESS],temp_emotions[DISGUST],(*it).b(3),temp_ranges[SADNESS].lo(),temp_ranges[SADNESS].hi()),
//				sheila::percent_diff(temp_emotions[SADNESS],temp_emotions[SADNESS],(*it).c(3),temp_ranges[SADNESS].lo(),temp_ranges[SADNESS].hi()),
//				sheila::percent_diff(temp_emotions[SADNESS],temp_emotions[SURPRISE],(*it).d(3),temp_ranges[SADNESS].lo(),temp_ranges[SADNESS].hi()),
//				sheila::percent_diff(temp_emotions[SADNESS],temp_emotions[FEAR],(*it).e(3),temp_ranges[SADNESS].lo(),temp_ranges[SADNESS].hi()),
//				sheila::percent_diff(temp_emotions[SADNESS],temp_emotions[TRUST],(*it).f(3),temp_ranges[SADNESS].lo(),temp_ranges[SADNESS].hi()),
//				sheila::percent_diff(temp_emotions[SADNESS],temp_emotions[JOY],(*it).g(3),temp_ranges[SADNESS].lo(),temp_ranges[SADNESS].hi()),
//				sheila::percent_diff(temp_emotions[SADNESS],temp_emotions[ANTICIPATION],(*it).h(3),temp_ranges[SADNESS].lo(),temp_ranges[SADNESS].hi())
//			},
//			{
//				(*it).surprise_range.contains(temp_emotions[SURPRISE]),
//				sheila::percent_diff(temp_emotions[SURPRISE],temp_emotions[ANGER],(*it).a(4),temp_ranges[SURPRISE].lo(),temp_ranges[SURPRISE].hi()),
//				sheila::percent_diff(temp_emotions[SURPRISE],temp_emotions[DISGUST],(*it).b(4),temp_ranges[SURPRISE].lo(),temp_ranges[SURPRISE].hi()),
//				sheila::percent_diff(temp_emotions[SURPRISE],temp_emotions[SADNESS],(*it).c(4),temp_ranges[SURPRISE].lo(),temp_ranges[SURPRISE].hi()),
//				sheila::percent_diff(temp_emotions[SURPRISE],temp_emotions[SURPRISE],(*it).d(4),temp_ranges[SURPRISE].lo(),temp_ranges[SURPRISE].hi()),
//				sheila::percent_diff(temp_emotions[SURPRISE],temp_emotions[FEAR],(*it).e(4),temp_ranges[SURPRISE].lo(),temp_ranges[SURPRISE].hi()),
//				sheila::percent_diff(temp_emotions[SURPRISE],temp_emotions[TRUST],(*it).f(4),temp_ranges[SURPRISE].lo(),temp_ranges[SURPRISE].hi()),
//				sheila::percent_diff(temp_emotions[SURPRISE],temp_emotions[JOY],(*it).g(4),temp_ranges[SURPRISE].lo(),temp_ranges[SURPRISE].hi()),
//				sheila::percent_diff(temp_emotions[SURPRISE],temp_emotions[ANTICIPATION],(*it).h(4),temp_ranges[SURPRISE].lo(),temp_ranges[SURPRISE].hi())
//			},
//			{
//				(*it).fear_range.contains(temp_emotions[FEAR]),
//				sheila::percent_diff(temp_emotions[FEAR],temp_emotions[ANGER],(*it).a(5),temp_ranges[FEAR].lo(),temp_ranges[FEAR].hi()),
//				sheila::percent_diff(temp_emotions[FEAR],temp_emotions[DISGUST],(*it).b(5),temp_ranges[FEAR].lo(),temp_ranges[FEAR].hi()),
//				sheila::percent_diff(temp_emotions[FEAR],temp_emotions[SADNESS],(*it).c(5),temp_ranges[FEAR].lo(),temp_ranges[FEAR].hi()),
//				sheila::percent_diff(temp_emotions[FEAR],temp_emotions[SURPRISE],(*it).d(5),temp_ranges[FEAR].lo(),temp_ranges[FEAR].hi()),
//				sheila::percent_diff(temp_emotions[FEAR],temp_emotions[FEAR],(*it).e(5),temp_ranges[FEAR].lo(),temp_ranges[FEAR].hi()),
//				sheila::percent_diff(temp_emotions[FEAR],temp_emotions[TRUST],(*it).f(5),temp_ranges[FEAR].lo(),temp_ranges[FEAR].hi()),
//				sheila::percent_diff(temp_emotions[FEAR],temp_emotions[JOY],(*it).g(5),temp_ranges[FEAR].lo(),temp_ranges[FEAR].hi()),
//				sheila::percent_diff(temp_emotions[FEAR],temp_emotions[ANTICIPATION],(*it).h(5),temp_ranges[FEAR].lo(),temp_ranges[FEAR].hi())
//			},
//			{
//				(*it).trust_range.contains(temp_emotions[TRUST]),
//				sheila::percent_diff(temp_emotions[TRUST],temp_emotions[ANGER],(*it).a(6),temp_ranges[TRUST].lo(),temp_ranges[TRUST].hi()),
//				sheila::percent_diff(temp_emotions[TRUST],temp_emotions[DISGUST],(*it).b(6),temp_ranges[TRUST].lo(),temp_ranges[TRUST].hi()),
//				sheila::percent_diff(temp_emotions[TRUST],temp_emotions[SADNESS],(*it).c(6),temp_ranges[TRUST].lo(),temp_ranges[TRUST].hi()),
//				sheila::percent_diff(temp_emotions[TRUST],temp_emotions[SURPRISE],(*it).d(6),temp_ranges[TRUST].lo(),temp_ranges[TRUST].hi()),
//				sheila::percent_diff(temp_emotions[TRUST],temp_emotions[FEAR],(*it).e(6),temp_ranges[TRUST].lo(),temp_ranges[TRUST].hi()),
//				sheila::percent_diff(temp_emotions[TRUST],temp_emotions[TRUST],(*it).f(6),temp_ranges[TRUST].lo(),temp_ranges[TRUST].hi()),
//				sheila::percent_diff(temp_emotions[TRUST],temp_emotions[JOY],(*it).g(6),temp_ranges[TRUST].lo(),temp_ranges[TRUST].hi()),
//				sheila::percent_diff(temp_emotions[TRUST],temp_emotions[ANTICIPATION],(*it).h(6),temp_ranges[TRUST].lo(),temp_ranges[TRUST].hi())
//			},
//			{
//				(*it).joy_range.contains(temp_emotions[JOY]),
//				sheila::percent_diff(temp_emotions[JOY],temp_emotions[ANGER],(*it).a(7),temp_ranges[JOY].lo(),temp_ranges[JOY].hi()),
//				sheila::percent_diff(temp_emotions[JOY],temp_emotions[DISGUST],(*it).b(7),temp_ranges[JOY].lo(),temp_ranges[JOY].hi()),
//				sheila::percent_diff(temp_emotions[JOY],temp_emotions[SADNESS],(*it).c(7),temp_ranges[JOY].lo(),temp_ranges[JOY].hi()),
//				sheila::percent_diff(temp_emotions[JOY],temp_emotions[SURPRISE],(*it).d(7),temp_ranges[JOY].lo(),temp_ranges[JOY].hi()),
//				sheila::percent_diff(temp_emotions[JOY],temp_emotions[FEAR],(*it).e(7),temp_ranges[JOY].lo(),temp_ranges[JOY].hi()),
//				sheila::percent_diff(temp_emotions[JOY],temp_emotions[TRUST],(*it).f(7),temp_ranges[JOY].lo(),temp_ranges[JOY].hi()),
//				sheila::percent_diff(temp_emotions[JOY],temp_emotions[JOY],(*it).g(7),temp_ranges[JOY].lo(),temp_ranges[JOY].hi()),
//				sheila::percent_diff(temp_emotions[JOY],temp_emotions[ANTICIPATION],(*it).h(7),temp_ranges[JOY].lo(),temp_ranges[JOY].hi())
//			},
//			{
//				(*it).anticipation_range.contains(temp_emotions[ANTICIPATION]),
//				sheila::percent_diff(temp_emotions[ANTICIPATION],temp_emotions[ANGER],(*it).a(8),temp_ranges[ANTICIPATION].lo(),temp_ranges[ANTICIPATION].hi()),
//				sheila::percent_diff(temp_emotions[ANTICIPATION],temp_emotions[DISGUST],(*it).b(8),temp_ranges[ANTICIPATION].lo(),temp_ranges[ANTICIPATION].hi()),
//				sheila::percent_diff(temp_emotions[ANTICIPATION],temp_emotions[SADNESS],(*it).c(8),temp_ranges[ANTICIPATION].lo(),temp_ranges[ANTICIPATION].hi()),
//				sheila::percent_diff(temp_emotions[ANTICIPATION],temp_emotions[SURPRISE],(*it).d(8),temp_ranges[ANTICIPATION].lo(),temp_ranges[ANTICIPATION].hi()),
//				sheila::percent_diff(temp_emotions[ANTICIPATION],temp_emotions[FEAR],(*it).e(8),temp_ranges[ANTICIPATION].lo(),temp_ranges[ANTICIPATION].hi()),
//				sheila::percent_diff(temp_emotions[ANTICIPATION],temp_emotions[TRUST],(*it).f(8),temp_ranges[ANTICIPATION].lo(),temp_ranges[ANTICIPATION].hi()),
//				sheila::percent_diff(temp_emotions[ANTICIPATION],temp_emotions[JOY],(*it).g(8),temp_ranges[ANTICIPATION].lo(),temp_ranges[ANTICIPATION].hi()),
//				sheila::percent_diff(temp_emotions[ANTICIPATION],temp_emotions[ANTICIPATION],(*it).h(8),temp_ranges[ANTICIPATION].lo(),temp_ranges[ANTICIPATION].hi())
//			}
//
//		};

		for (char i = 0; i <= 7;i++){

			for (char n = 0; n <= 8;n++){
//				std::cout << em(i) << em(n-1) << ':' << test[i][n] << std::endl;

			}
		}

		if (!(*it).ang_range.contains(temp_emotions[ANGER])) {
			match = false;
		} else if (!(*it).dis_range.contains(temp_emotions[DISGUST])) {
			match = false;
		} else if (!(*it).sad_range.contains(temp_emotions[SADNESS])) {
			match = false;
		} else if (!(*it).sur_range.contains(temp_emotions[SURPRISE])) {
			match = false;
		} else if (!(*it).fea_range.contains(temp_emotions[FEAR])) {
			match = false;
		} else if (!(*it).tru_range.contains(temp_emotions[TRUST])) {
			match = false;
		} else if (!(*it).joy_range.contains(temp_emotions[JOY])) {
			match = false;
		} else if (!(*it).ant_range.contains(temp_emotions[ANTICIPATION])) {
			match = false;
		} else {
			match = true;
			allfeelings.push_back(*it);
		}

	}

	std::cout << "All Feelings: " << temp_feelings.size() << std::endl
			<< "Matches: " << allfeelings.size() << std::endl;

	return allfeelings.at(0).getName();
}

Mood::~Mood() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */
