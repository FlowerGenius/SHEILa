//SHEILa========================================================================
// Name        : Entity.hpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Mar 29, 2018
// Modified    :
//==============================================================================

#ifndef ENTITY_ENTITY_HPP_
#define ENTITY_ENTITY_HPP_

#include <string>
#include <vector>
#include <typeinfo>
#include <ctime>

#include "../symbols.inc"
#include "../Cpp/language.inc"
#include "../ProgrammingLanguage/C/language.inc"

namespace sheila {

/** @brief Template class for an @c Entity in the SHEILa structure model.
 *  @author FlowerGenius
 *  @tparam _Tp The class that this @c Entity will represent.
 *
 *  An @c Entity is a special data type, it represents the pair of files
 *  required to build the class of the same name and it's variants.
 */
template<class _Tp>
class Entity : private cpp::CppObject<_Tp> {
public:

	/** @brief Creates an @c Entity for modifying the class of type @a _Tp.
	 *  @author FlowerGenius
	 *
	 */
	Entity() { instance_id = 0; }

	/** @brief Destroys an @c Entity object.
	 *  @author FlowerGenius
	 */
	virtual ~Entity() {}


protected:

	/** @brief ID that is a unique unsigned integer within this object's type
	 */
	uintmax_t                instance_id;

	/** @brief List of all known aliases for the specific entity that this
	 *  instance describes.
	 */
	std::vector<std::string> instance_name;

	/** @brief List of all known descriptions for the specific entity that
	 *  this instance describes.
	 */
	std::vector<std::string> instance_desc;

	/** @brief List of paths to all known pictures of or containing the
	 *  specific entity that this instance describes.
	 */
	std::vector<std::string> instance_picture_paths;

	/** @brief List of paths to all known videos of or containing the specific
	 * entity that this instance describes.
	 */
	std::vector<std::string> instance_video_paths;

	/** @brief List of paths to all known audio files associated with the
	 *  specific entity that this instance describes.
	 */
	std::vector<std::string> instance_sound_paths;

	/** @brief List of paths to all known document files associated with the
	 *  specific entity that this instance describes.
	 */
	std::vector<std::string> instance_document_paths;

	/** @brief List of paths to all known programs associated with the specific
	 * entity that this instance describes.
	 */
	std::vector<std::string> instance_program_paths;

	/** @brief The emotional baggage that the (entity that this specific
	 * instance describes) carries.
	 */
	std::vector<long double> instance_emotion_values;

	/** @brief List of paths to all known schemas for identifying the entity
	 *  that this specific instance describes.
	 */
	std::vector<std::string> instance_cv_filters;

	/** @brief  Function returning a C++ string representing this instance.
	 *  @author FlowerGenius
	 *  @return A strictly formatted C++ string.
	 *
	 *  Returns a C++ string that can be parsed by @c _E_eval() to re-create
	 *  an exact copy of this specific instance.
	 *
	 */
	virtual std::string _E_repr() {}

	/** @brief Function that re-creates an instance of @Entity<_Tp> from a
	 *  C++ string.
	 *  @author FlowerGenius
	 *  @param repr A C++ string that represents an instance of @c Entity<_Tp>
	 */
	virtual void _E_eval(std::string repr) {}

#if (BUILD_FOR_SHEILA_DAEMON == 1)
	static std::time_t								this_object_accessed;
	static std::vector<long double>					this_object_emotion_values;
	static std::vector<std::string>					this_object_cv_filters;
	static std::vector<cpp::CppClass_advanced> 		this_object_parents;
	static std::vector<cpp::CppClass_advanced> 		this_object_children;
	static std::vector<_Tp > 						this_object_entities;
#endif

};

} /* namespace sheila */

#endif /* ENTITY_ENTITY_HPP_ */
