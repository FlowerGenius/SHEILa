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

std::vector<Feeling> Feeling::feelings;

Feeling::Feeling() {

}

Feeling::Feeling(std::string name, std::string desc,
		uintmax_t ang_low, uintmax_t ang_hi,
		uintmax_t dis_low, uintmax_t dis_hi,
		uintmax_t sad_low, uintmax_t sad_hi,
		uintmax_t sur_low, uintmax_t sur_hi,
		uintmax_t fea_low, uintmax_t fea_hi,
		uintmax_t tru_low, uintmax_t tru_hi,
		uintmax_t joy_low, uintmax_t joy_hi,
		uintmax_t ant_low, uintmax_t ant_hi,
		double min_diff_ang_dis, double max_diff_ang_dis,
		double min_diff_ang_sad, double max_diff_ang_sad,
		double min_diff_ang_sur, double max_diff_ang_sur,
		double min_diff_ang_fea, double max_diff_ang_fea,
		double min_diff_ang_tru, double max_diff_ang_tru,
		double min_diff_ang_joy, double max_diff_ang_joy,
		double min_diff_ang_ant, double max_diff_ang_ant,
		double min_diff_dis_sad, double max_diff_dis_sad,
		double min_diff_dis_sur, double max_diff_dis_sur,
		double min_diff_dis_fea, double max_diff_dis_fea,
		double min_diff_dis_tru, double max_diff_dis_tru,
		double min_diff_dis_joy, double max_diff_dis_joy,
		double min_diff_dis_ant, double max_diff_dis_ant,
		double min_diff_sad_sur, double max_diff_sad_sur,
		double min_diff_sad_fea, double max_diff_sad_fea,
		double min_diff_sad_tru, double max_diff_sad_tru,
		double min_diff_sad_joy, double max_diff_sad_joy,
		double min_diff_sad_ant, double max_diff_sad_ant,
		double min_diff_sur_fea, double max_diff_sur_fea,
		double min_diff_sur_tru, double max_diff_sur_tru,
		double min_diff_sur_joy, double max_diff_sur_joy,
		double min_diff_sur_ant, double max_diff_sur_ant,
		double min_diff_fea_tru, double max_diff_fea_tru,
		double min_diff_fea_joy, double max_diff_fea_joy,
		double min_diff_fea_ant, double max_diff_fea_ant,
		double min_diff_tru_joy, double max_diff_tru_joy,
		double min_diff_tru_ant, double max_diff_tru_ant,
		double min_diff_joy_ant, double max_diff_joy_ant) {

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

/*
 * Get the minimum and maximum percentage difference from a to b
 *
 * A positive difference means that a > b
 * Negative difference means that b > a
 */
std::pair<double,double> Feeling::getDiff(char a, char b)
{
	switch(a){
	case ANGER:
		switch(b){
		case DISGUST:
			return std::pair<double,double>(min_diff_ang_dis, max_diff_ang_dis);
		case SADNESS:
			return std::pair<double,double>(min_diff_ang_sad, max_diff_ang_sad);
		case SURPRISE:
			return std::pair<double,double>(min_diff_ang_sur, max_diff_ang_sur);
		case FEAR:
			return std::pair<double,double>(min_diff_ang_fea, max_diff_ang_fea);
		case TRUST:
			return std::pair<double,double>(min_diff_ang_tru, max_diff_ang_tru);
		case JOY:
			return std::pair<double,double>(min_diff_ang_joy, max_diff_ang_joy);
		case ANTICIPATION:
			return std::pair<double,double>(min_diff_ang_ant, max_diff_ang_ant);
		}
		break;
	case DISGUST:
		switch(b){
		case ANGER:
			return std::pair<double,double>(-max_diff_ang_dis, -min_diff_ang_dis);
		case SADNESS:
			return std::pair<double,double>(min_diff_dis_sad, max_diff_dis_sad);
		case SURPRISE:
			return std::pair<double,double>(min_diff_dis_sur, max_diff_dis_sur);
		case FEAR:
			return std::pair<double,double>(min_diff_dis_fea, max_diff_dis_fea);
		case TRUST:
			return std::pair<double,double>(min_diff_dis_tru, max_diff_dis_tru);
		case JOY:
			return std::pair<double,double>(min_diff_dis_joy, max_diff_dis_joy);
		case ANTICIPATION:
			return std::pair<double,double>(min_diff_dis_ant, max_diff_dis_ant);
		}
		break;
	case SADNESS:
		switch(b){
		case ANGER:
			return std::pair<double,double>(-max_diff_ang_sad, -min_diff_ang_sad);
		case DISGUST:
			return std::pair<double,double>(-max_diff_dis_sad, -min_diff_dis_sad);
		case SURPRISE:
			return std::pair<double,double>(min_diff_sad_sur, max_diff_sad_sur);
		case FEAR:
			return std::pair<double,double>(min_diff_sad_fea, max_diff_sad_fea);
		case TRUST:
			return std::pair<double,double>(min_diff_sad_tru, max_diff_sad_tru);
		case JOY:
			return std::pair<double,double>(min_diff_sad_joy, max_diff_sad_joy);
		case ANTICIPATION:
			return std::pair<double,double>(min_diff_sad_ant, max_diff_sad_ant);
		}
		break;
	case SURPRISE:
		switch(b){
		case ANGER:
			return std::pair<double,double>(-max_diff_ang_sur, -min_diff_ang_sur);
		case DISGUST:
			return std::pair<double,double>(-max_diff_dis_sur, -min_diff_dis_sur);
		case SADNESS:
			return std::pair<double,double>(-max_diff_sad_sur, -min_diff_sad_sur);
		case FEAR:
			return std::pair<double,double>(min_diff_sur_fea, max_diff_sur_fea);
		case TRUST:
			return std::pair<double,double>(min_diff_sur_tru, max_diff_sur_tru);
		case JOY:
			return std::pair<double,double>(min_diff_sur_joy, max_diff_sur_joy);
		case ANTICIPATION:
			return std::pair<double,double>(min_diff_sur_ant, max_diff_sur_ant);
		}
		break;
	case FEAR:
		switch(b){
		case ANGER:
			return std::pair<double,double>(-max_diff_ang_fea, -min_diff_ang_fea);
		case DISGUST:
			return std::pair<double,double>(-max_diff_dis_fea, -min_diff_dis_fea);
		case SADNESS:
			return std::pair<double,double>(-max_diff_sad_fea, -min_diff_sad_fea);
		case SURPRISE:
			return std::pair<double,double>(-max_diff_sur_fea, -min_diff_sur_fea);
		case TRUST:
			return std::pair<double,double>(min_diff_fea_tru, max_diff_fea_tru);
		case JOY:
			return std::pair<double,double>(min_diff_fea_joy, max_diff_fea_joy);
		case ANTICIPATION:
			return std::pair<double,double>(min_diff_fea_ant, max_diff_fea_ant);
		}
		break;
	case TRUST:
		switch(b){
		case ANGER:
			return std::pair<double,double>(-max_diff_ang_tru, -min_diff_ang_tru);
		case DISGUST:
			return std::pair<double,double>(-max_diff_dis_tru, -min_diff_dis_tru);
		case SADNESS:
			return std::pair<double,double>(-max_diff_sad_tru, -min_diff_sad_tru);
		case SURPRISE:
			return std::pair<double,double>(-max_diff_sur_tru, -min_diff_sur_tru);
		case FEAR:
			return std::pair<double,double>(-max_diff_fea_tru, -min_diff_fea_tru);
		case JOY:
			return std::pair<double,double>(min_diff_tru_joy, max_diff_tru_joy);
		case ANTICIPATION:
			return std::pair<double,double>(min_diff_tru_ant, max_diff_tru_ant);
		}
		break;
	case JOY:
		switch(b){
		case ANGER:
			return std::pair<double,double>(-max_diff_ang_joy, -min_diff_ang_joy);
		case DISGUST:
			return std::pair<double,double>(-max_diff_dis_joy, -min_diff_dis_joy);
		case SADNESS:
			return std::pair<double,double>(-max_diff_sad_joy, -min_diff_sad_joy);
		case SURPRISE:
			return std::pair<double,double>(-max_diff_sur_joy, -min_diff_sur_joy);
		case FEAR:
			return std::pair<double,double>(-max_diff_fea_joy, -min_diff_fea_joy);
		case TRUST:
			return std::pair<double,double>(-max_diff_tru_joy, -min_diff_tru_joy);
		case ANTICIPATION:
			return std::pair<double,double>(min_diff_joy_ant, max_diff_joy_ant);
		}
		break;
	case ANTICIPATION:
		switch(b){
		case ANGER:
			return std::pair<double,double>(-max_diff_ang_ant, -min_diff_ang_ant);
		case DISGUST:
			return std::pair<double,double>(-max_diff_dis_ant, -min_diff_dis_ant);
		case SADNESS:
			return std::pair<double,double>(-max_diff_sad_ant, -min_diff_sad_ant);
		case SURPRISE:
			return std::pair<double,double>(-max_diff_sur_ant, -min_diff_sur_ant);
		case FEAR:
			return std::pair<double,double>(-max_diff_fea_ant, -min_diff_fea_ant);
		case TRUST:
			return std::pair<double,double>(-max_diff_tru_ant, -min_diff_tru_ant);
		case JOY:
			return std::pair<double,double>(-max_diff_joy_ant, -min_diff_joy_ant);
		}
		break;
	default:
		break;
	}
	return std::pair<double,double>(0.0,0.0);
}

} /* namespace sheila */
