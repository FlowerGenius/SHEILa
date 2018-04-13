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

#ifndef ENTITY_FEELING_FEELING_H_
#define ENTITY_FEELING_FEELING_H_

#include "../Range/Range.h"
#include "../Entity.h"

#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>

namespace sheila {

class Feeling : public Entity {
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

	static std::time_t							_time_created_;
	static std::time_t							_time_accessed_;
	static std::time_t							_time_modified_;
	static std::vector<long double>				_emotion_values_;
	static std::vector<std::string> 			_name_;
	static std::vector<std::string> 			_desc_;
	static std::vector<std::string>				_cv_filters_;
	static std::vector<Entity> 					_parents_;
	static std::vector<Entity> 					_children_;
	static std::vector<cpp::CppMemberFunction> 	_member_functions_;
	static std::vector<cpp::CppDataMember> 		_data_members_;

};

} /* namespace sheila */

#endif /* ENTITY_FEELING_FEELING_H_ */
