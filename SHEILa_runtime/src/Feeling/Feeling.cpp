//SHEILa======================================================================
// Name        : Feeling.cpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 20, 2018
// Modified    :
//============================================================================

#include "Feeling.h"

namespace sheila {

/*
 *
 */
std::string ldtos(long double d, int coeff_digits){
	std::stringstream ss;

	if (d >= 0.0){
		ss << '+';
		ss << std::fixed << std::setprecision(std::numeric_limits<long double>::digits10 - coeff_digits) << d;
	} else {
		ss << std::fixed << std::setprecision(std::numeric_limits<long double>::digits10 - coeff_digits) << d;
	}

	return ss.str();

}

std::vector<Feeling> Feeling::feelings;

Feeling::Feeling() {

}

Feeling::Feeling(std::string name, std::string desc,
		long double ang_low, long double ang_hi,
		long double dis_low, long double dis_hi,
		long double sad_low, long double sad_hi,
		long double sur_low, long double sur_hi,
		long double fea_low, long double fea_hi,
		long double tru_low, long double tru_hi,
		long double joy_low, long double joy_hi,
		long double ant_low, long double ant_hi,
	    long double min_diff_ang_dis, long double max_diff_ang_dis,
		long double min_diff_ang_sad, long double max_diff_ang_sad,
		long double min_diff_ang_sur, long double max_diff_ang_sur,
		long double min_diff_ang_fea, long double max_diff_ang_fea,
		long double min_diff_ang_tru, long double max_diff_ang_tru,
		long double min_diff_ang_joy, long double max_diff_ang_joy,
		long double min_diff_ang_ant, long double max_diff_ang_ant,
		long double min_diff_dis_sad, long double max_diff_dis_sad,
		long double min_diff_dis_sur, long double max_diff_dis_sur,
		long double min_diff_dis_fea, long double max_diff_dis_fea,
		long double min_diff_dis_tru, long double max_diff_dis_tru,
		long double min_diff_dis_joy, long double max_diff_dis_joy,
		long double min_diff_dis_ant, long double max_diff_dis_ant,
		long double min_diff_sad_sur, long double max_diff_sad_sur,
		long double min_diff_sad_fea, long double max_diff_sad_fea,
		long double min_diff_sad_tru, long double max_diff_sad_tru,
		long double min_diff_sad_joy, long double max_diff_sad_joy,
		long double min_diff_sad_ant, long double max_diff_sad_ant,
		long double min_diff_sur_fea, long double max_diff_sur_fea,
		long double min_diff_sur_tru, long double max_diff_sur_tru,
		long double min_diff_sur_joy, long double max_diff_sur_joy,
		long double min_diff_sur_ant, long double max_diff_sur_ant,
		long double min_diff_fea_tru, long double max_diff_fea_tru,
		long double min_diff_fea_joy, long double max_diff_fea_joy,
		long double min_diff_fea_ant, long double max_diff_fea_ant,
		long double min_diff_tru_joy, long double max_diff_tru_joy,
		long double min_diff_tru_ant, long double max_diff_tru_ant,
		long double min_diff_joy_ant, long double max_diff_joy_ant) {

	this->name 			= name;
	this->description 	= desc;
	this->ang_range 	= Range(ang_low, ang_hi);
	this->dis_range 	= Range(dis_low, dis_hi);
	this->sad_range 	= Range(sad_low, sad_hi);
	this->sur_range 	= Range(sur_low, sur_hi);
	this->fea_range 	= Range(fea_low, fea_hi);
	this->tru_range 	= Range(tru_low, tru_hi);
	this->joy_range 	= Range(joy_low, joy_hi);
	this->ant_range 	= Range(ant_low, ant_hi);

	this->min_diff_ang_dis = min_diff_ang_dis; this->max_diff_ang_dis = max_diff_ang_dis;
	this->min_diff_ang_sad = min_diff_ang_sad; this->max_diff_ang_sad = max_diff_ang_sad;
	this->min_diff_ang_sur = min_diff_ang_sur; this->max_diff_ang_sur = max_diff_ang_sur;
	this->min_diff_ang_fea = min_diff_ang_fea; this->max_diff_ang_fea = max_diff_ang_fea;
	this->min_diff_ang_tru = min_diff_ang_tru; this->max_diff_ang_tru = max_diff_ang_tru;
	this->min_diff_ang_joy = min_diff_ang_joy; this->max_diff_ang_joy = max_diff_ang_joy;
	this->min_diff_ang_ant = min_diff_ang_ant; this->max_diff_ang_ant = max_diff_ang_ant;

	this->min_diff_dis_sad = min_diff_dis_sad; this->max_diff_dis_sad = max_diff_dis_sad;
	this->min_diff_dis_sur = min_diff_dis_sur; this->max_diff_dis_sur = max_diff_dis_sur;
	this->min_diff_dis_fea = min_diff_dis_fea; this->max_diff_dis_fea = max_diff_dis_fea;
	this->min_diff_dis_tru = min_diff_dis_tru; this->max_diff_dis_tru = max_diff_dis_tru;
	this->min_diff_dis_joy = min_diff_dis_joy; this->max_diff_dis_joy = max_diff_dis_joy;
	this->min_diff_dis_ant = min_diff_dis_ant; this->max_diff_dis_ant = max_diff_dis_ant;

	this->min_diff_sad_sur = min_diff_sad_sur; this->max_diff_sad_sur = max_diff_sad_sur;
	this->min_diff_sad_fea = min_diff_sad_fea; this->max_diff_sad_fea = max_diff_sad_fea;
	this->min_diff_sad_tru = min_diff_sad_tru; this->max_diff_sad_tru = max_diff_sad_tru;
	this->min_diff_sad_joy = min_diff_sad_joy; this->max_diff_sad_joy = max_diff_sad_joy;
	this->min_diff_sad_ant = min_diff_sad_ant; this->max_diff_sad_ant = max_diff_sad_ant;

	this->min_diff_sur_fea = min_diff_sur_fea; this->max_diff_sur_fea = max_diff_sur_fea;
	this->min_diff_sur_tru = min_diff_sur_tru; this->max_diff_sur_tru = max_diff_sur_tru;
	this->min_diff_sur_joy = min_diff_sur_joy; this->max_diff_sur_joy = max_diff_sur_joy;
	this->min_diff_sur_ant = min_diff_sur_ant; this->max_diff_sur_ant = max_diff_sur_ant;

	this->min_diff_fea_tru = min_diff_fea_tru; this->max_diff_fea_tru = max_diff_fea_tru;
	this->min_diff_fea_joy = min_diff_fea_joy; this->max_diff_fea_joy = max_diff_fea_joy;
	this->min_diff_fea_ant = min_diff_fea_ant; this->max_diff_fea_ant = max_diff_fea_ant;

	this->min_diff_tru_joy = min_diff_tru_joy; this->max_diff_tru_joy = max_diff_tru_joy;
	this->min_diff_tru_ant = min_diff_tru_ant; this->max_diff_tru_ant = max_diff_tru_ant;

	this->min_diff_joy_ant = min_diff_joy_ant; this->max_diff_joy_ant = max_diff_joy_ant;


}

Feeling::~Feeling() {
	// TODO Auto-generated destructor stub
}

const std::string& Feeling::getDescription() const {
	return description;
}

const std::string& Feeling::getName() const {
	return name;
}

std::string Feeling::toString() {
	std::stringstream ss;

	ss << std::fixed << std::setprecision(15);

	ss << name << '\t';							// Name
	ss << description << '\t';					// Description

	ss << ang_range.lo() << ':' << ang_range.hi() << '\t';	// [Anger] lower bound : upper bound
	ss << dis_range.lo() << ':' << dis_range.hi() << '\t';	// [Disgust] lower bound : upper bound
	ss << sad_range.lo() << ':' << sad_range.hi() << '\t';	// [Sadness] lower bound : upper bound
	ss << sur_range.lo() << ':' << sur_range.hi() << '\t';	// [Surprise] lower bound : upper bound
	ss << fea_range.lo() << ':' << fea_range.hi() << '\t';	// [Fear] lower bound : upper bound
	ss << tru_range.lo() << ':' << tru_range.hi() << '\t';	// [Trust] lower bound : upper bound
	ss << joy_range.lo() << ':' << joy_range.hi() << '\t';	// [Joy] lower bound : upper bound
	ss << ant_range.lo() << ':' << ant_range.hi() << '\t';	// [Anticipation] lower bound : upper bound

	ss << ldtos(min_diff_ang_dis,3) << ':' << ldtos(max_diff_ang_dis,3) << '\t';	// [Anger] Disgust % Diff
	ss << ldtos(min_diff_ang_sad,3) << ':' << ldtos(max_diff_ang_sad,3) << '\t';	// [Anger] Sadness % Diff
	ss << ldtos(min_diff_ang_sur,3) << ':' << ldtos(max_diff_ang_sur,3) << '\t';	// [Anger] Surprise % Diff
	ss << ldtos(min_diff_ang_fea,3) << ':' << ldtos(max_diff_ang_fea,3) << '\t';	// [Anger] Fear % Diff
	ss << ldtos(min_diff_ang_tru,3) << ':' << ldtos(max_diff_ang_tru,3) << '\t';	// [Anger] Trust % Diff
	ss << ldtos(min_diff_ang_joy,3) << ':' << ldtos(max_diff_ang_joy,3) << '\t';	// [Anger] Joy % Diff
	ss << ldtos(min_diff_ang_ant,3) << ':' << ldtos(max_diff_ang_ant,3) << '\t';	// [Anger] Anticipation % Diff

	ss << ldtos(min_diff_dis_sad,3) << ':' << ldtos(max_diff_dis_sad,3) << '\t';	// [Disgust] Sadness % Diff
	ss << ldtos(min_diff_dis_sur,3) << ':' << ldtos(max_diff_dis_sur,3) << '\t';	// [Disgust] Surprise % Diff
	ss << ldtos(min_diff_dis_fea,3) << ':' << ldtos(max_diff_dis_fea,3) << '\t';	// [Disgust] Fear % Diff
	ss << ldtos(min_diff_dis_tru,3) << ':' << ldtos(max_diff_dis_tru,3) << '\t';	// [Disgust] Trust % Diff
	ss << ldtos(min_diff_dis_joy,3) << ':' << ldtos(max_diff_dis_joy,3) << '\t';	// [Disgust] Joy % Diff
	ss << ldtos(min_diff_dis_ant,3) << ':' << ldtos(max_diff_dis_ant,3) << '\t';	// [Disgust] Anticipation % Diff

	ss << ldtos(min_diff_sad_sur,3) << ':' << ldtos(max_diff_sad_sur,3) << '\t';	// [Sadness] Surprise % Diff
	ss << ldtos(min_diff_sad_fea,3) << ':' << ldtos(max_diff_sad_fea,3) << '\t';	// [Sadness] Fear % Diff
	ss << ldtos(min_diff_sad_tru,3) << ':' << ldtos(max_diff_sad_tru,3) << '\t';	// [Sadness] Trust % Diff
	ss << ldtos(min_diff_sad_joy,3) << ':' << ldtos(max_diff_sad_joy,3) << '\t';	// [Sadness] Joy % Diff
	ss << ldtos(min_diff_sad_ant,3) << ':' << ldtos(max_diff_sad_ant,3) << '\t';	// [Sadness] Anticipation % Diff

	ss << ldtos(min_diff_sur_fea,3) << ':' << ldtos(max_diff_sur_fea,3) << '\t';	// [Surprise] Fear % Diff
	ss << ldtos(min_diff_sur_tru,3) << ':' << ldtos(max_diff_sur_tru,3) << '\t';	// [Surprise] Trust % Diff
	ss << ldtos(min_diff_sur_joy,3) << ':' << ldtos(max_diff_sur_joy,3) << '\t';	// [Surprise] Joy % Diff
	ss << ldtos(min_diff_sur_ant,3) << ':' << ldtos(max_diff_sur_ant,3) << '\t';	// [Surprise] Anticipation % Diff

	ss << ldtos(min_diff_fea_tru,3) << ':' << ldtos(max_diff_fea_tru,3) << '\t';	// [Fear] Trust % Diff
	ss << ldtos(min_diff_fea_joy,3) << ':' << ldtos(max_diff_fea_joy,3) << '\t';	// [Fear] Joy % Diff
	ss << ldtos(min_diff_fea_ant,3) << ':' << ldtos(max_diff_fea_ant,3) << '\t';	// [Fear] Anticipation % Diff

	ss << ldtos(min_diff_tru_joy,3) << ':' << ldtos(max_diff_tru_joy,3) << '\t';	// [Trust] Joy % Diff
	ss << ldtos(min_diff_tru_ant,3) << ':' << ldtos(max_diff_tru_ant,3) << '\t';	// [Trust] Anticipation % Diff

	ss << ldtos(min_diff_joy_ant,3) << ':' << ldtos(max_diff_joy_ant,3) << '\t';	// [Joy] Anticipation % Diff

	ss << '\n';

	return ss.str();
}

/*
 * Get the minimum and maximum percentage difference from a to b
 *
 * A positive difference means that a > b
 * Negative difference means that b > a
 */
std::pair<long double,long double> Feeling::getDiff(char a, char b)
{
	switch(a){
	case ANGER:
		switch(b){
		case DISGUST:
			return std::pair<long double,long double>(min_diff_ang_dis, max_diff_ang_dis);
		case SADNESS:
			return std::pair<long double,long double>(min_diff_ang_sad, max_diff_ang_sad);
		case SURPRISE:
			return std::pair<long double,long double>(min_diff_ang_sur, max_diff_ang_sur);
		case FEAR:
			return std::pair<long double,long double>(min_diff_ang_fea, max_diff_ang_fea);
		case TRUST:
			return std::pair<long double,long double>(min_diff_ang_tru, max_diff_ang_tru);
		case JOY:
			return std::pair<long double,long double>(min_diff_ang_joy, max_diff_ang_joy);
		case ANTICIPATION:
			return std::pair<long double,long double>(min_diff_ang_ant, max_diff_ang_ant);
		}
		break;
	case DISGUST:
		switch(b){
		case ANGER:
			return std::pair<long double,long double>(-max_diff_ang_dis, -min_diff_ang_dis);
		case SADNESS:
			return std::pair<long double,long double>(min_diff_dis_sad, max_diff_dis_sad);
		case SURPRISE:
			return std::pair<long double,long double>(min_diff_dis_sur, max_diff_dis_sur);
		case FEAR:
			return std::pair<long double,long double>(min_diff_dis_fea, max_diff_dis_fea);
		case TRUST:
			return std::pair<long double,long double>(min_diff_dis_tru, max_diff_dis_tru);
		case JOY:
			return std::pair<long double,long double>(min_diff_dis_joy, max_diff_dis_joy);
		case ANTICIPATION:
			return std::pair<long double,long double>(min_diff_dis_ant, max_diff_dis_ant);
		}
		break;
	case SADNESS:
		switch(b){
		case ANGER:
			return std::pair<long double,long double>(-max_diff_ang_sad, -min_diff_ang_sad);
		case DISGUST:
			return std::pair<long double,long double>(-max_diff_dis_sad, -min_diff_dis_sad);
		case SURPRISE:
			return std::pair<long double,long double>(min_diff_sad_sur, max_diff_sad_sur);
		case FEAR:
			return std::pair<long double,long double>(min_diff_sad_fea, max_diff_sad_fea);
		case TRUST:
			return std::pair<long double,long double>(min_diff_sad_tru, max_diff_sad_tru);
		case JOY:
			return std::pair<long double,long double>(min_diff_sad_joy, max_diff_sad_joy);
		case ANTICIPATION:
			return std::pair<long double,long double>(min_diff_sad_ant, max_diff_sad_ant);
		}
		break;
	case SURPRISE:
		switch(b){
		case ANGER:
			return std::pair<long double,long double>(-max_diff_ang_sur, -min_diff_ang_sur);
		case DISGUST:
			return std::pair<long double,long double>(-max_diff_dis_sur, -min_diff_dis_sur);
		case SADNESS:
			return std::pair<long double,long double>(-max_diff_sad_sur, -min_diff_sad_sur);
		case FEAR:
			return std::pair<long double,long double>(min_diff_sur_fea, max_diff_sur_fea);
		case TRUST:
			return std::pair<long double,long double>(min_diff_sur_tru, max_diff_sur_tru);
		case JOY:
			return std::pair<long double,long double>(min_diff_sur_joy, max_diff_sur_joy);
		case ANTICIPATION:
			return std::pair<long double,long double>(min_diff_sur_ant, max_diff_sur_ant);
		}
		break;
	case FEAR:
		switch(b){
		case ANGER:
			return std::pair<long double,long double>(-max_diff_ang_fea, -min_diff_ang_fea);
		case DISGUST:
			return std::pair<long double,long double>(-max_diff_dis_fea, -min_diff_dis_fea);
		case SADNESS:
			return std::pair<long double,long double>(-max_diff_sad_fea, -min_diff_sad_fea);
		case SURPRISE:
			return std::pair<long double,long double>(-max_diff_sur_fea, -min_diff_sur_fea);
		case TRUST:
			return std::pair<long double,long double>(min_diff_fea_tru, max_diff_fea_tru);
		case JOY:
			return std::pair<long double,long double>(min_diff_fea_joy, max_diff_fea_joy);
		case ANTICIPATION:
			return std::pair<long double,long double>(min_diff_fea_ant, max_diff_fea_ant);
		}
		break;
	case TRUST:
		switch(b){
		case ANGER:
			return std::pair<long double,long double>(-max_diff_ang_tru, -min_diff_ang_tru);
		case DISGUST:
			return std::pair<long double,long double>(-max_diff_dis_tru, -min_diff_dis_tru);
		case SADNESS:
			return std::pair<long double,long double>(-max_diff_sad_tru, -min_diff_sad_tru);
		case SURPRISE:
			return std::pair<long double,long double>(-max_diff_sur_tru, -min_diff_sur_tru);
		case FEAR:
			return std::pair<long double,long double>(-max_diff_fea_tru, -min_diff_fea_tru);
		case JOY:
			return std::pair<long double,long double>(min_diff_tru_joy, max_diff_tru_joy);
		case ANTICIPATION:
			return std::pair<long double,long double>(min_diff_tru_ant, max_diff_tru_ant);
		}
		break;
	case JOY:
		switch(b){
		case ANGER:
			return std::pair<long double,long double>(-max_diff_ang_joy, -min_diff_ang_joy);
		case DISGUST:
			return std::pair<long double,long double>(-max_diff_dis_joy, -min_diff_dis_joy);
		case SADNESS:
			return std::pair<long double,long double>(-max_diff_sad_joy, -min_diff_sad_joy);
		case SURPRISE:
			return std::pair<long double,long double>(-max_diff_sur_joy, -min_diff_sur_joy);
		case FEAR:
			return std::pair<long double,long double>(-max_diff_fea_joy, -min_diff_fea_joy);
		case TRUST:
			return std::pair<long double,long double>(-max_diff_tru_joy, -min_diff_tru_joy);
		case ANTICIPATION:
			return std::pair<long double,long double>(min_diff_joy_ant, max_diff_joy_ant);
		}
		break;
	case ANTICIPATION:
		switch(b){
		case ANGER:
			return std::pair<long double,long double>(-max_diff_ang_ant, -min_diff_ang_ant);
		case DISGUST:
			return std::pair<long double,long double>(-max_diff_dis_ant, -min_diff_dis_ant);
		case SADNESS:
			return std::pair<long double,long double>(-max_diff_sad_ant, -min_diff_sad_ant);
		case SURPRISE:
			return std::pair<long double,long double>(-max_diff_sur_ant, -min_diff_sur_ant);
		case FEAR:
			return std::pair<long double,long double>(-max_diff_fea_ant, -min_diff_fea_ant);
		case TRUST:
			return std::pair<long double,long double>(-max_diff_tru_ant, -min_diff_tru_ant);
		case JOY:
			return std::pair<long double,long double>(-max_diff_joy_ant, -min_diff_joy_ant);
		}
		break;
	default:
		break;
	}
	return std::pair<long double,long double>(0.0,0.0);
}

} /* namespace sheila */
