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

#include "Feeling.hpp"

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

Feeling::Feeling(std::initializer_list<std::string> info,
				 std::initializer_list<long double> bound_allocator,
				 std::initializer_list<long double> diff_allocator) {


	int i;

	if ( info.size() >= 2 ) {
		i = 0;
		for ( auto&& inf : info ) {
			if (i == 0) {
				this->name = inf;
			} else if (i == 1) {
				this->desc = inf;
			}
		}
	}

	if ( bound_allocator.size() >= 16 ) {
		i = 0;
		for ( auto&& val : bound_allocator ) {
			this->values[i] = val;
			++i;
		}
	}

	if ( diff_allocator.size() >= 56 ) {
		i = 0;
		for ( auto&& diff : diff_allocator ) {
			this->data[i] = diff;
			++i;
		}
	}
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

//	_name.push_back("Feeling");
//	_desc.push_back("A specific range of emotions that can be identified with one word or phrase");

	this->name 	= name;
	this->desc 	= desc;
	this->ang_range 	= Range(ang_low, ang_hi);
	this->dis_range 	= Range(dis_low, dis_hi);
	this->sad_range 	= Range(sad_low, sad_hi);
	this->sur_range 	= Range(sur_low, sur_hi);
	this->fea_range 	= Range(fea_low, fea_hi);
	this->tru_range 	= Range(tru_low, tru_hi);
	this->joy_range 	= Range(joy_low, joy_hi);
	this->ant_range 	= Range(ant_low, ant_hi);

	this->data[0] = min_diff_ang_dis; this->data[1] = max_diff_ang_dis;
	this->data[2] = min_diff_ang_sad; this->data[3] = max_diff_ang_sad;
	this->data[4] = min_diff_ang_sur; this->data[5] = max_diff_ang_sur;
	this->data[6] = min_diff_ang_fea; this->data[7] = max_diff_ang_fea;
	this->data[8] = min_diff_ang_tru; this->data[9] = max_diff_ang_tru;
	this->data[10] = min_diff_ang_joy; this->data[11] = max_diff_ang_joy;
	this->data[12] = min_diff_ang_ant; this->data[13] = max_diff_ang_ant;

	this->data[14] = min_diff_dis_sad; this->data[15] = max_diff_dis_sad;
	this->data[16] = min_diff_dis_sur; this->data[17] = max_diff_dis_sur;
	this->data[18] = min_diff_dis_fea; this->data[19] = max_diff_dis_fea;
	this->data[20] = min_diff_dis_tru; this->data[21] = max_diff_dis_tru;
	this->data[22] = min_diff_dis_joy; this->data[23] = max_diff_dis_joy;
	this->data[24] = min_diff_dis_ant; this->data[25] = max_diff_dis_ant;

	this->data[26] = min_diff_sad_sur; this->data[27] = max_diff_sad_sur;
	this->data[28] = min_diff_sad_fea; this->data[29] = max_diff_sad_fea;
	this->data[30] = min_diff_sad_tru; this->data[31] = max_diff_sad_tru;
	this->data[32] = min_diff_sad_joy; this->data[33] = max_diff_sad_joy;
	this->data[34] = min_diff_sad_ant; this->data[35] = max_diff_sad_ant;

	this->data[36] = min_diff_sur_fea; this->data[37] = max_diff_sur_fea;
	this->data[38] = min_diff_sur_tru; this->data[39] = max_diff_sur_tru;
	this->data[40] = min_diff_sur_joy; this->data[41] = max_diff_sur_joy;
	this->data[42] = min_diff_sur_ant; this->data[43] = max_diff_sur_ant;

	this->data[44] = min_diff_fea_tru; this->data[45] = max_diff_fea_tru;
	this->data[46] = min_diff_fea_joy; this->data[47] = max_diff_fea_joy;
	this->data[48] = min_diff_fea_ant; this->data[49] = max_diff_fea_ant;

	this->data[50] = min_diff_tru_joy; this->data[51] = max_diff_tru_joy;
	this->data[52] = min_diff_tru_ant; this->data[53] = max_diff_tru_ant;

	this->data[54] = min_diff_joy_ant; this->data[55] = max_diff_joy_ant;

}

Feeling::~Feeling() {

}

const std::string& Feeling::getDescription() const {
	return desc;
}

const std::string& Feeling::getName() const {
	return name;
}

std::string Feeling::_E_repr() {
	std::stringstream ss;

	ss << std::fixed << std::setprecision(15);

	ss << name << '\t';							// Name
	ss << desc << '\t';					// Description

	ss << ang_range.lo() << ':' << ang_range.hi() << '\t';	// [Anger] lower bound : upper bound
	ss << dis_range.lo() << ':' << dis_range.hi() << '\t';	// [Disgust] lower bound : upper bound
	ss << sad_range.lo() << ':' << sad_range.hi() << '\t';	// [Sadness] lower bound : upper bound
	ss << sur_range.lo() << ':' << sur_range.hi() << '\t';	// [Surprise] lower bound : upper bound
	ss << fea_range.lo() << ':' << fea_range.hi() << '\t';	// [Fear] lower bound : upper bound
	ss << tru_range.lo() << ':' << tru_range.hi() << '\t';	// [Trust] lower bound : upper bound
	ss << joy_range.lo() << ':' << joy_range.hi() << '\t';	// [Joy] lower bound : upper bound
	ss << ant_range.lo() << ':' << ant_range.hi() << '\t';	// [Anticipation] lower bound : upper bound

	ss << ldtos(data[0],3) << ':' << ldtos(data[1],3) << '\t';	// [Anger] Disgust % Diff
	ss << ldtos(data[2],3) << ':' << ldtos(data[3],3) << '\t';	// [Anger] Sadness % Diff
	ss << ldtos(data[4],3) << ':' << ldtos(data[5],3) << '\t';	// [Anger] Surprise % Diff
	ss << ldtos(data[6],3) << ':' << ldtos(data[7],3) << '\t';	// [Anger] Fear % Diff
	ss << ldtos(data[8],3) << ':' << ldtos(data[9],3) << '\t';	// [Anger] Trust % Diff
	ss << ldtos(data[10],3) << ':' << ldtos(data[11],3) << '\t';	// [Anger] Joy % Diff
	ss << ldtos(data[12],3) << ':' << ldtos(data[13],3) << '\t';	// [Anger] Anticipation % Diff

	ss << ldtos(data[14],3) << ':' << ldtos(data[15],3) << '\t';	// [Disgust] Sadness % Diff
	ss << ldtos(data[16],3) << ':' << ldtos(data[17],3) << '\t';	// [Disgust] Surprise % Diff
	ss << ldtos(data[18],3) << ':' << ldtos(data[19],3) << '\t';	// [Disgust] Fear % Diff
	ss << ldtos(data[20],3) << ':' << ldtos(data[21],3) << '\t';	// [Disgust] Trust % Diff
	ss << ldtos(data[22],3) << ':' << ldtos(data[23],3) << '\t';	// [Disgust] Joy % Diff
	ss << ldtos(data[24],3) << ':' << ldtos(data[25],3) << '\t';	// [Disgust] Anticipation % Diff

	ss << ldtos(data[26],3) << ':' << ldtos(data[27],3) << '\t';	// [Sadness] Surprise % Diff
	ss << ldtos(data[28],3) << ':' << ldtos(data[29],3) << '\t';	// [Sadness] Fear % Diff
	ss << ldtos(data[30],3) << ':' << ldtos(data[31],3) << '\t';	// [Sadness] Trust % Diff
	ss << ldtos(data[32],3) << ':' << ldtos(data[33],3) << '\t';	// [Sadness] Joy % Diff
	ss << ldtos(data[34],3) << ':' << ldtos(data[35],3) << '\t';	// [Sadness] Anticipation % Diff

	ss << ldtos(data[36],3) << ':' << ldtos(data[37],3) << '\t';	// [Surprise] Fear % Diff
	ss << ldtos(data[38],3) << ':' << ldtos(data[39],3) << '\t';	// [Surprise] Trust % Diff
	ss << ldtos(data[40],3) << ':' << ldtos(data[41],3) << '\t';	// [Surprise] Joy % Diff
	ss << ldtos(data[42],3) << ':' << ldtos(data[43],3) << '\t';	// [Surprise] Anticipation % Diff

	ss << ldtos(data[44],3) << ':' << ldtos(data[45],3) << '\t';	// [Fear] Trust % Diff
	ss << ldtos(data[46],3) << ':' << ldtos(data[47],3) << '\t';	// [Fear] Joy % Diff
	ss << ldtos(data[48],3) << ':' << ldtos(data[49],3) << '\t';	// [Fear] Anticipation % Diff

	ss << ldtos(data[50],3) << ':' << ldtos(data[51],3) << '\t';	// [Trust] Joy % Diff
	ss << ldtos(data[52],3) << ':' << ldtos(data[53],3) << '\t';	// [Trust] Anticipation % Diff

	ss << ldtos(data[54],3) << ':' << ldtos(data[55],3) << '\t';	// [Joy] Anticipation % Diff

	ss << '\n';

	return ss.str();
}

void Feeling::_E_eval(std::string data) {

	int n = 0;

	size_t pos2;

	std::string feeling_s = data;
	std::string feeling_s_s;

	std::vector<long double> diffs;


	while ((pos2 = feeling_s.find('\t')) != std::string::npos){
		feeling_s_s = feeling_s.substr(0,pos2);
		size_t pos3;
		switch(n){
		case 0:
			name = feeling_s_s;
			break;
		case 1:
			desc = feeling_s_s;
			break;
		case 2:
			pos3 = feeling_s_s.find(':');
			ang_range = Range(std::stold(feeling_s_s.substr(0,pos3)),std::stold(feeling_s_s.substr(pos3+1)));
			break;
		case 3:
			pos3 = feeling_s_s.find(':');
			dis_range = Range(std::stold(feeling_s_s.substr(0,pos3)),std::stold(feeling_s_s.substr(pos3+1)));
			break;
		case 4:
			pos3 = feeling_s_s.find(':');
			sad_range = Range(std::stold(feeling_s_s.substr(0,pos3)),std::stold(feeling_s_s.substr(pos3+1)));
			break;
		case 5:
			pos3 = feeling_s_s.find(':');
			sur_range = Range(std::stold(feeling_s_s.substr(0,pos3)),std::stold(feeling_s_s.substr(pos3+1)));
			break;
		case 6:
			pos3 = feeling_s_s.find(':');
			fea_range = Range(std::stold(feeling_s_s.substr(0,pos3)),std::stold(feeling_s_s.substr(pos3+1)));
			break;
		case 7:
			pos3 = feeling_s_s.find(':');
			tru_range = Range(std::stold(feeling_s_s.substr(0,pos3)),std::stold(feeling_s_s.substr(pos3+1)));
			break;
		case 8:
			pos3 = feeling_s_s.find(':');
			joy_range = Range(std::stold(feeling_s_s.substr(0,pos3)),std::stold(feeling_s_s.substr(pos3+1)));
			break;
		case 9:
			pos3 = feeling_s_s.find(':');
			ant_range = Range(std::stold(feeling_s_s.substr(0,pos3)),std::stold(feeling_s_s.substr(pos3+1)));
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

//	this->data[0] = diffs[0]; this->data[1] = diffs[1];
//	this->data[2] = diffs[2]; this->data[3] = diffs[3];
//	this->data[4] = diffs[4]; this->data[5] = diffs[5];
//	this->data[6] = diffs[6]; this->data[7] = diffs[7];
//	this->data[8] = diffs[8]; this->data[9] = diffs[9];
//	this->data[10] = diffs[10]; this->data[11] = diffs[11];
//	this->data[12] = diffs[12]; this->data[13] = diffs[13];
//
//	this->data[14] = diffs[14]; this->data[15] = diffs[15];
//	this->data[16] = diffs[16]; this->data[17] = diffs[17];
//	this->data[18] = diffs[18]; this->data[19] = diffs[19];
//	this->data[20] = diffs[20]; this->data[21] = diffs[21];
//	this->data[22] = diffs[22]; this->data[23] = diffs[23];
//	this->data[24] = diffs[24]; this->data[25] = diffs[25];
//
//	this->data[26] = diffs[26]; this->data[27] = diffs[27];
//	this->data[28] = diffs[28]; this->data[29] = diffs[29];
//	this->data[30] = diffs[30]; this->data[31] = diffs[31];
//	this->data[32] = diffs[32]; this->data[33] = diffs[33];
//	this->data[34] = diffs[34]; this->data[35] = diffs[35];
//
//	this->data[36] = diffs[36]; this->data[37] = diffs[37];
//	this->data[38] = diffs[38]; this->data[39] = diffs[39];
//	this->data[40] = diffs[40]; this->data[41] = diffs[41];
//	this->data[42] = diffs[42]; this->data[43] = diffs[43];
//
//	this->data[44] = diffs[44]; this->data[45] = diffs[45];
//	this->data[46] = diffs[46]; this->data[47] = diffs[47];
//	this->data[48] = diffs[48]; this->data[49] = diffs[49];
//
//	this->data[50] = diffs[50]; this->data[51] = diffs[51];
//	this->data[52] = diffs[52]; this->data[53] = diffs[53];
//
//	this->data[54] = diffs[54]; this->data[55] = diffs[55];

	int i = 0;
	for ( auto&& var : diffs) {
		data[i] = var;
		++i;
	}

}

/*
 * Get the minimum and maximum percentage difference from a to b
 *
 * A positive difference means that a > b
 * Negative difference means that b > a
 */
std::pair<long double,long double> Feeling::getDiff(PlutchikEmotion a, PlutchikEmotion b)
{
	try {
		switch(a){
		case PlutchikEmotion::ANGER:
			switch(b){
			case PlutchikEmotion::DISGUST:
				return std::pair<long double,long double>(data[0], data[1]);
			case PlutchikEmotion::SADNESS:
				return std::pair<long double,long double>(data[2], data[3]);
			case PlutchikEmotion::SURPRISE:
				return std::pair<long double,long double>(data[4], data[5]);
			case PlutchikEmotion::FEAR:
				return std::pair<long double,long double>(data[6], data[7]);
			case PlutchikEmotion::TRUST:
				return std::pair<long double,long double>(data[8], data[9]);
			case PlutchikEmotion::JOY:
				return std::pair<long double,long double>(data[10], data[11]);
			case PlutchikEmotion::ANTICIPATION:
				return std::pair<long double,long double>(data[12], data[13]);
			default:
				throw exception::EmotionSelfDiffException(b);
			}
			break;
		case PlutchikEmotion::DISGUST:
			switch(b){
			case PlutchikEmotion::ANGER:
				return std::pair<long double,long double>(-data[1], -data[0]);
			case PlutchikEmotion::SADNESS:
				return std::pair<long double,long double>(data[14], data[15]);
			case PlutchikEmotion::SURPRISE:
				return std::pair<long double,long double>(data[16], data[17]);
			case PlutchikEmotion::FEAR:
				return std::pair<long double,long double>(data[18], data[19]);
			case PlutchikEmotion::TRUST:
				return std::pair<long double,long double>(data[20], data[21]);
			case PlutchikEmotion::JOY:
				return std::pair<long double,long double>(data[22], data[23]);
			case PlutchikEmotion::ANTICIPATION:
				return std::pair<long double,long double>(data[24], data[25]);
			default:
				throw exception::EmotionSelfDiffException(b);
			}
			break;
		case PlutchikEmotion::SADNESS:
			switch(b){
			case PlutchikEmotion::ANGER:
				return std::pair<long double,long double>(-data[3], -data[2]);
			case PlutchikEmotion::DISGUST:
				return std::pair<long double,long double>(-data[15], -data[14]);
			case PlutchikEmotion::SURPRISE:
				return std::pair<long double,long double>(data[26], data[27]);
			case PlutchikEmotion::FEAR:
				return std::pair<long double,long double>(data[28], data[29]);
			case PlutchikEmotion::TRUST:
				return std::pair<long double,long double>(data[30], data[31]);
			case PlutchikEmotion::JOY:
				return std::pair<long double,long double>(data[32], data[33]);
			case PlutchikEmotion::ANTICIPATION:
				return std::pair<long double,long double>(data[34], data[35]);
			default:
				throw exception::EmotionSelfDiffException(b);
			}
			break;
		case PlutchikEmotion::SURPRISE:
			switch(b){
			case PlutchikEmotion::ANGER:
				return std::pair<long double,long double>(-data[5], -data[4]);
			case PlutchikEmotion::DISGUST:
				return std::pair<long double,long double>(-data[17], -data[16]);
			case PlutchikEmotion::SADNESS:
				return std::pair<long double,long double>(-data[27], -data[26]);
			case PlutchikEmotion::FEAR:
				return std::pair<long double,long double>(data[36], data[37]);
			case PlutchikEmotion::TRUST:
				return std::pair<long double,long double>(data[38], data[39]);
			case PlutchikEmotion::JOY:
				return std::pair<long double,long double>(data[40], data[41]);
			case PlutchikEmotion::ANTICIPATION:
				return std::pair<long double,long double>(data[42], data[43]);
			default:
				throw exception::EmotionSelfDiffException(b);
			}
			break;
		case PlutchikEmotion::FEAR:
			switch(b){
			case PlutchikEmotion::ANGER:
				return std::pair<long double,long double>(-data[7], -data[6]);
			case PlutchikEmotion::DISGUST:
				return std::pair<long double,long double>(-data[19], -data[18]);
			case PlutchikEmotion::SADNESS:
				return std::pair<long double,long double>(-data[29], -data[28]);
			case PlutchikEmotion::SURPRISE:
				return std::pair<long double,long double>(-data[37], -data[36]);
			case PlutchikEmotion::TRUST:
				return std::pair<long double,long double>(data[44], data[45]);
			case PlutchikEmotion::JOY:
				return std::pair<long double,long double>(data[46], data[47]);
			case PlutchikEmotion::ANTICIPATION:
				return std::pair<long double,long double>(data[48], data[49]);
			default:
				throw exception::EmotionSelfDiffException(b);
			}
			break;
		case PlutchikEmotion::TRUST:
			switch(b){
			case PlutchikEmotion::ANGER:
				return std::pair<long double,long double>(-data[9], -data[8]);
			case PlutchikEmotion::DISGUST:
				return std::pair<long double,long double>(-data[21], -data[20]);
			case PlutchikEmotion::SADNESS:
				return std::pair<long double,long double>(-data[31], -data[30]);
			case PlutchikEmotion::SURPRISE:
				return std::pair<long double,long double>(-data[39], -data[38]);
			case PlutchikEmotion::FEAR:
				return std::pair<long double,long double>(-data[45], -data[44]);
			case PlutchikEmotion::JOY:
				return std::pair<long double,long double>(data[50], data[51]);
			case PlutchikEmotion::ANTICIPATION:
				return std::pair<long double,long double>(data[52], data[53]);
			default:
				throw exception::EmotionSelfDiffException(b);
			}
			break;
		case PlutchikEmotion::JOY:
			switch(b){
			case PlutchikEmotion::ANGER:
				return std::pair<long double,long double>(-data[11], -data[10]);
			case PlutchikEmotion::DISGUST:
				return std::pair<long double,long double>(-data[23], -data[22]);
			case PlutchikEmotion::SADNESS:
				return std::pair<long double,long double>(-data[33], -data[32]);
			case PlutchikEmotion::SURPRISE:
				return std::pair<long double,long double>(-data[41], -data[40]);
			case PlutchikEmotion::FEAR:
				return std::pair<long double,long double>(-data[47], -data[46]);
			case PlutchikEmotion::TRUST:
				return std::pair<long double,long double>(-data[51], -data[50]);
			case PlutchikEmotion::ANTICIPATION:
				return std::pair<long double,long double>(data[54], data[55]);
			default:
				throw exception::EmotionSelfDiffException(b);
			}
			break;
		case PlutchikEmotion::ANTICIPATION:
			switch(b){
			case PlutchikEmotion::ANGER:
				return std::pair<long double,long double>(-data[13], -data[12]);
			case PlutchikEmotion::DISGUST:
				return std::pair<long double,long double>(-data[25], -data[24]);
			case PlutchikEmotion::SADNESS:
				return std::pair<long double,long double>(-data[35], -data[34]);
			case PlutchikEmotion::SURPRISE:
				return std::pair<long double,long double>(-data[43], -data[42]);
			case PlutchikEmotion::FEAR:
				return std::pair<long double,long double>(-data[49], -data[48]);
			case PlutchikEmotion::TRUST:
				return std::pair<long double,long double>(-data[53], -data[52]);
			case PlutchikEmotion::JOY:
				return std::pair<long double,long double>(-data[55], -data[54]);
			default:
				throw exception::EmotionSelfDiffException(b);
			}
			break;
		}
	}
	catch( const exception::EmotionSelfDiffException &e ) {
		return std::pair<long double,long double>(0.0,0.0);
	}
	return std::pair<long double,long double>(0.0,0.0);
}

} /* namespace sheila */
