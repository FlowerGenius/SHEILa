//SHEILa======================================================================
// Name        : Feeling.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 20, 2018
// Modified    :
//============================================================================

#ifndef FEELING_FEELING_H_
#define FEELING_FEELING_H_

#include <string>
#include <vector>
#include <utility>
#include "../Range/Range.h"

namespace sheila {

class Feeling {
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
			double min_diff_joy_ant, double max_diff_joy_ant);
	virtual ~Feeling();
	const std::string& getDescription() const;
	const std::string& getName() const;

	std::pair<double,double> getDiff(char a, char b);

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
	std::string description;

	double min_diff_ang_dis; double max_diff_ang_dis;
	double min_diff_ang_sad; double max_diff_ang_sad;
	double min_diff_ang_sur; double max_diff_ang_sur;
	double min_diff_ang_fea; double max_diff_ang_fea;
	double min_diff_ang_tru; double max_diff_ang_tru;
	double min_diff_ang_joy; double max_diff_ang_joy;
	double min_diff_ang_ant; double max_diff_ang_ant;
	double min_diff_dis_sad; double max_diff_dis_sad;
	double min_diff_dis_sur; double max_diff_dis_sur;
	double min_diff_dis_fea; double max_diff_dis_fea;
	double min_diff_dis_tru; double max_diff_dis_tru;
	double min_diff_dis_joy; double max_diff_dis_joy;
	double min_diff_dis_ant; double max_diff_dis_ant;
	double min_diff_sad_sur; double max_diff_sad_sur;
	double min_diff_sad_fea; double max_diff_sad_fea;
	double min_diff_sad_tru; double max_diff_sad_tru;
	double min_diff_sad_joy; double max_diff_sad_joy;
	double min_diff_sad_ant; double max_diff_sad_ant;
	double min_diff_sur_fea; double max_diff_sur_fea;
	double min_diff_sur_tru; double max_diff_sur_tru;
	double min_diff_sur_joy; double max_diff_sur_joy;
	double min_diff_sur_ant; double max_diff_sur_ant;
	double min_diff_fea_tru; double max_diff_fea_tru;
	double min_diff_fea_joy; double max_diff_fea_joy;
	double min_diff_fea_ant; double max_diff_fea_ant;
	double min_diff_tru_joy; double max_diff_tru_joy;
	double min_diff_tru_ant; double max_diff_tru_ant;
	double min_diff_joy_ant; double max_diff_joy_ant;

};

} /* namespace sheila */

#endif /* FEELING_FEELING_H_ */
