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

#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <exception>
#include <stdexcept>

#include "Entity/Range.hpp"
#include "Entity/Emotion.hpp"
#include "Entity/Entity.hpp"


namespace sheila {

namespace exception {

	/** @brief Exception thrown when an Emotion is compared relative to itself.
	 *  @author FlowerGenius
	 */
	struct EmotionSelfDiffException : public std::runtime_error {

		/** @brief Create an instance of EmotionSelfDiffException.
		 *  @author FlowerGenius
		 *  @param e The PlutchikEmotion that was compared to itself.
		 */
		EmotionSelfDiffException(PlutchikEmotion& e) : runtime_error(
				"Attempted to get the difference between "+
				Emotion_base::getPlutchikEmotionName(e)+" and itself")
				{};

		/** Destroy this instance of EmotionSelfDiffException */
		virtual ~EmotionSelfDiffException() {
			;
		}

	};
}

/** @brief A Feeling as understood by SHEILa.
 *  @author FlowerGenius
 *
 *  To SHEILa, a Feeling is a specific map of Plutchik emotion values and their
 *  relations to one another. Since the number of unique feelings is
 *  not finite, an instance of the Feeling class represents a feeling, rather
 *  than having a class for each.
 *
 */
class Feeling : public Entity<Feeling> {
public:

	/** @brief Creates an instance of Feeling.
	 *  @author FlowerGenius
	 *
	 */
	Feeling(std::initializer_list<std::string> info={},
			std::initializer_list<long double> args1={},
			std::initializer_list<long double> args2={});

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

	/** @brief Destroys this instance of feeling
	 *  @author FlowerGenius
	 */
	virtual ~Feeling();


	const std::string& getDescription() const;
	const std::string& getName() const;

	std::string _E_repr();
	void		_E_eval(std::string);
	std::pair<long double,long double> getDiff(char a, char b);
	std::pair<long double,long double> getDiff(PlutchikEmotion a, PlutchikEmotion b);

	Range ang_range;
	Range dis_range;
	Range sad_range;
	Range sur_range;
	Range fea_range;
	Range tru_range;
	Range joy_range;
	Range ant_range;


private:
	std::string name;
	std::string desc;

	/** @brief C-style array of long double containing the value data.
	 *  @author FlowerGenius
	 *
	 *  Lookup Table:
	 *
	 *  @arg @a 0 Lower bound on @c Anger values matching this feeling.
	 *  @arg @a 1 Higher bound on @c Anger values matching this feeling.
	 *  @arg @a 2 Lower bound on @c Disgust values matching this feeling.
	 *  @arg @a 3 Higher bound on @c Disgust values matching this feeling.
	 *  @arg @a 4 Lower bound on @c Sadness values matching this feeling.
	 *  @arg @a 5 Higher bound on @c Sadness values matching this feeling.
	 *  @arg @a 6 Lower bound on @c Surprise values matching this feeling.
	 *  @arg @a 7 Higher bound on @c Surprise values matching this feeling.
	 *  @arg @a 8 Lower bound on @c Fear values matching this feeling.
	 *  @arg @a 9 Higher bound on @c Fear values matching this feeling.
	 *  @arg @a 10 Lower bound on @c Trust values matching this feeling.
	 *  @arg @a 11 Higher bound on @c Trust values matching this feeling.
	 *  @arg @a 12 Lower bound on @c Joy values matching this feeling.
	 *  @arg @a 13 Higher bound on @c Joy values matching this feeling.
	 *  @arg @a 14 Lower bound on @c Anticipation values matching this feeling.
	 *  @arg @a 15 Higher bound on @c Anticipation values matching this feeling.
	 *
	 */
	long double values[16];

	/** @brief C-style array of long double containing the relational data.
	 *
	 */
	long double data[56];

};

} /* namespace sheila */

#endif /* ENTITY_FEELING_FEELING_HPP_ */
