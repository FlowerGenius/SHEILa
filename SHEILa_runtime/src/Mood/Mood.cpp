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

namespace server {
extern std::vector<Feeling> feelings;
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

	uintmax_t temp_anger = getAngerStrength();
	uintmax_t temp_disgust = getDisgustStrength();
	uintmax_t temp_sadness = getSadnessStrength();
	uintmax_t temp_surprise = getSurpriseStrength();
	uintmax_t temp_fear = getFearStrength();
	uintmax_t temp_trust = getTrustStrength();
	uintmax_t temp_joy = getJoyStrength();
	uintmax_t temp_anticipation = getAnticipationStrength();

	std::vector<Feeling> allfeelings;
	for (std::vector<Feeling>::iterator it = server::feelings.begin();
			it != server::feelings.end(); ++it) {
		bool match = true;

		if (!(*it).anger_range.contains(getAngerStrength())) {
			match = false;
		} else if (!(*it).disgust_range.contains(getDisgustStrength())) {
			match = false;
		} else if (!(*it).sadness_range.contains(getSadnessStrength())) {
			match = false;
		} else if (!(*it).surprise_range.contains(getSurpriseStrength())) {
			match = false;
		} else if (!(*it).fear_range.contains(getFearStrength())) {
			match = false;
		} else if (!(*it).trust_range.contains(getTrustStrength())) {
			match = false;
		} else if (!(*it).joy_range.contains(getJoyStrength())) {
			match = false;
		} else if (!(*it).anticipation_range.contains(
				getAnticipationStrength())) {
			match = false;
		} else {
			match = true;
			allfeelings.push_back(*it);
		}

	}

	std::cout << "All Feelings: " << server::feelings.size() << std::endl
			<< "Matches: " << allfeelings.size() << std::endl;

	return allfeelings.at(0).getName();
}

Mood::~Mood() {
	// TODO Auto-generated destructor stub
}

} /* namespace sheila */
