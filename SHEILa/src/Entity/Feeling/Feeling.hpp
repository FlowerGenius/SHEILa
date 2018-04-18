//SHEILa======================================================================
// Name        : Feeling.hpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 20, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_FEELING_FEELING_HPP_
#define ENTITY_FEELING_FEELING_HPP_

#include "../Range/Range.hpp"
#include "../Entity.hpp"

#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>

namespace sheila {

class Feeling : public Entity<FEELING_T> {
public:

	static std::vector<Feeling> feelings;

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


	Feeling();
	Feeling(std::string name, std::string desc,
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
			long double min_diff_joy_ant, long double max_diff_joy_ant);
	virtual ~Feeling();
	const std::string& getDescription() const;
	const std::string& getName() const;
	std::string _E_repr();
	void		_E_eval(std::string);

	std::pair<long double,long double> getDiff(char a, char b);

	Range ang_range;
	Range dis_range;
	Range sad_range;
	Range sur_range;
	Range fea_range;
	Range tru_range;
	Range joy_range;
	Range ant_range;


protected:
	std::string name;
	std::string desc;

	long double min_diff_ang_dis; long double max_diff_ang_dis;
	long double min_diff_ang_sad; long double max_diff_ang_sad;
	long double min_diff_ang_sur; long double max_diff_ang_sur;
	long double min_diff_ang_fea; long double max_diff_ang_fea;
	long double min_diff_ang_tru; long double max_diff_ang_tru;
	long double min_diff_ang_joy; long double max_diff_ang_joy;
	long double min_diff_ang_ant; long double max_diff_ang_ant;
	long double min_diff_dis_sad; long double max_diff_dis_sad;
	long double min_diff_dis_sur; long double max_diff_dis_sur;
	long double min_diff_dis_fea; long double max_diff_dis_fea;
	long double min_diff_dis_tru; long double max_diff_dis_tru;
	long double min_diff_dis_joy; long double max_diff_dis_joy;
	long double min_diff_dis_ant; long double max_diff_dis_ant;
	long double min_diff_sad_sur; long double max_diff_sad_sur;
	long double min_diff_sad_fea; long double max_diff_sad_fea;
	long double min_diff_sad_tru; long double max_diff_sad_tru;
	long double min_diff_sad_joy; long double max_diff_sad_joy;
	long double min_diff_sad_ant; long double max_diff_sad_ant;
	long double min_diff_sur_fea; long double max_diff_sur_fea;
	long double min_diff_sur_tru; long double max_diff_sur_tru;
	long double min_diff_sur_joy; long double max_diff_sur_joy;
	long double min_diff_sur_ant; long double max_diff_sur_ant;
	long double min_diff_fea_tru; long double max_diff_fea_tru;
	long double min_diff_fea_joy; long double max_diff_fea_joy;
	long double min_diff_fea_ant; long double max_diff_fea_ant;
	long double min_diff_tru_joy; long double max_diff_tru_joy;
	long double min_diff_tru_ant; long double max_diff_tru_ant;
	long double min_diff_joy_ant; long double max_diff_joy_ant;

private:


};

} /* namespace sheila */

#endif /* ENTITY_FEELING_FEELING_HPP_ */
