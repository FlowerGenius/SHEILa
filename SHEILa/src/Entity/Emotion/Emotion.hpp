//SHEILa======================================================================
// Name        : Emotion.hpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 19, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_EMOTION_EMOTION_HPP_
#define ENTITY_EMOTION_EMOTION_HPP_

#include <stdint.h>
#include <string>
#include <vector>
#include "../Entity.hpp"

namespace sheila {

/** @brief Enumeration of the types of PlutchikEmotion.
 *  @author FlowerGenius
 */
enum class PlutchikEmotion {
	ANGER,       //!< ANGER
	DISGUST,     //!< DISGUST
	SADNESS,     //!< SADNESS
	SURPRISE,    //!< SURPRISE
	FEAR,        //!< FEAR
	TRUST,       //!< TRUST
	JOY,         //!< JOY
	ANTICIPATION //!< ANTICIPATION
};

/** @brief The base for all specializations of the @c Emotion class;
 *  @author FlowerGenius
 */
struct Emotion_base : public Entity<Emotion_base> {
public:

	/** @brief Get the name of a PlutchikEmotion.
	 *  @author FlowerGenius
	 *  @param e The PlutchikEmotion to get the name of.
	 *  @return C++ string containing the name of the PlutchikEmotion.
	 */
	static std::string getPlutchikEmotionName(PlutchikEmotion e){
		switch(e) {
		case PlutchikEmotion::ANGER:
			return "ANGER";
		case PlutchikEmotion::DISGUST:
			return "DISGUST";
		case PlutchikEmotion::SADNESS:
			return "SADNESS";
		case PlutchikEmotion::SURPRISE:
			return "SURPRISE";
		case PlutchikEmotion::FEAR:
			return "FEAR";
		case PlutchikEmotion::TRUST:
			return "TRUST";
		case PlutchikEmotion::JOY:
			return "JOY";
		case PlutchikEmotion::ANTICIPATION:
			return "ANTICIPATION";
		default:
			return "Invalid";
		}
	}

	/** @brief Create a new instance of Emotion_base
	 *
	 */
	Emotion_base() { this->strength = 0.0; }

	/** @brief Destroy this instance of Emotion_base
	 *
	 */
	virtual ~Emotion_base() {
		;
	}

	/** @brief Set the strength of this instance (as a percentage)
	 *  @author FlowerGenius
	 *  @param strength long double representing the strength to be set.
	 *
	 */
	void setStrength(long double strength);

	/** @brief Get the strength of this instance (as a percentage)
	 *  @author FlowerGenius
	 *  @return The percentage strength of this instance.
	 */
	long double getStrength(void);


private:

	/** The percentage strength value of this instance of this emotion. */
	long double strength;

};

/** @brief An emotion as understood by SHEILa.
 *  @author FlowerGenius
 *  @tparam _Te Which Plutchik emotion this class represents.
 *
 *  SHEILa understands her emotions through the Plutchik model of emotionality,
 *  meaning that there are 8 core emotions through which all other emotions
 *  can be described. It is from this assumption that the emotional subsystem
 *  of SHEILa is built.
 *
 */
template<PlutchikEmotion _Te>
class Emotion :  public Emotion_base {
public:

	/** @brief Get the global strength of _Te.
	 *  @author FlowerGenius
	 * 	@return long double representing the percentage value strength of _Te.
	 */
	static long double getGlobalValue(){ return global_value.getStrength(); }


	/** @brief Creates a new instance of Emotion _Te
	 *  @author FlowerGenius
	 *
	 *  An instance of an emotion represents a Plutchik emotion as a percentage
	 *  value, with 100% being the most intense possible feeling of the
	 *  emotion, and with 0% being not feeling the emotion at all.
	 *
	 */
	Emotion() {
		this->setStrength(0.0);
	}

	/** @brief Creates a new instance of Emotion _Te with intensity @a strength
	 *  @author FlowerGenius
	 *  @param strength The intensity to initialize this object with.
	 *
	 *  An instance of an emotion represents a Plutchik emotion as a percentage
	 *  value, with 100% being the most intense possible feeling of the
	 *  emotion, and with 0% being not feeling the emotion at all.
	 *
	 */
	Emotion(long double strength) {
		this->setStrength(strength);
	}

	/** @brief Destroys this instance of Emotion _Te.
	 *  @author FlowerGenius
	 *
	 */
	virtual ~Emotion() {
		;
	}


private:

	/** @brief SHEILa Global @c Emotion for @c Emotion<@a _Te >
	 *  @author FlowerGenius
	 */
	static Emotion<_Te> global_value;


};

} /* namespace sheila */

#endif /* ENTITY_EMOTION_EMOTION_HPP_ */
