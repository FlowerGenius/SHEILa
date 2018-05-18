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

#include "stdafx.h"
#include <string>
#include <vector>
#include <typeinfo>
#include <ctime>

#define ENTITY_TEMPLATE

namespace sheila {

struct Entity_base {

	Entity_base() {

	}

	virtual ~Entity_base() {

	}

};

/** @brief Template class for an @c Entity in the SHEILa structure model.
 *  @author FlowerGenius
 *  @tparam _Tp The class that this @c Entity will represent.
 *
 *  An @c Entity is a special data type, it represents the pair of files
 *  required to build the class of the same name and it's variants.
 */
#ifdef ENTITY_TEMPLATE
	template<class _Tp>
#endif
class Entity
#ifdef ENTITY_TEMPLATE
		: public Cpp::Structure::Files::OutFiles::Object<_Tp>
#endif
	{
public:

	/** @brief Creates an @c Entity for modifying the class of type @a _Tp.
	 *  @author FlowerGenius
	 *
	 */
	Entity() {
		instance_id = 0;
	}

	/** @brief Destroys an @c Entity object.
	 *  @author FlowerGenius
	 */
	virtual ~Entity() {}

#ifdef ENTITY_TEMPLATE
	static const std::vector<_Tp>& getConcreteObjects() {
		//return this_object_entities;;
	}
#endif

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

private:

	/** @brief  Function returning a C++ string representing this instance.
	 *  @author FlowerGenius
	 *  @return A strictly formatted C++ string.
	 *
	 *  Returns a C++ string that can be parsed by @c _E_eval() to re-create
	 *  an exact copy of this specific instance.
	 *
	 */
	virtual std::string _E_repr() {}

	/** @brief Function that re-creates an instance of @Entity< _Tp > from a
	 *  C++ string.
	 *  @author FlowerGenius
	 *  @param repr A C++ string that represents an instance of @c Entity<_Tp>
	 */
	virtual void _E_eval(std::string repr) {}

#if (BUILD_FOR_SHEILA_DAEMON == 1)

	/** @brief The POSIX time that this object was last accessed */
	static std::time_t								this_object_accessed;

	/** @brief The emotional baggage that this object carries.
	 *  @author FlowerGenius
	 *
	 *  This field differs from the @a instance_emotion_values in that this
	 *  represents how SHEILa feels about this class of thing, rather than
	 *  a thing itself. As an example, this is how she feels about Cars, rather
	 *  than a specific car she has seen.
	 */
	static std::vector<long double>					this_object_emotion_values;

	/** @brief List of paths to all known schemas for identifying entities as
	 *  being of this ( _Tp ) type.
	 */
	static std::vector<std::string>					this_object_cv_filters;

	/** @brief List of pointers to all of the entities that this entity is
	 *  derived from.
	 *  @author FlowerGenius
	 *
	 *  As an entity can actually contain more that one class, parent in
	 *  this context means something different from the default C++ context.
	 *  A parent of an entity means that the CV schema of the parent must
	 *  match all of it's children, but the children have more specific
	 *  CV schema adding specificity on top of the schema of the parent.
	 *
	 */
	static std::vector<Cpp::Structure::Files::OutFiles::Object_base> 		this_object_parents;

	/** @brief List of pointers to all of the entities that are derived from
	 *  this entity.
	 *  @author FlowerGenius
	 *
	 *  As an entity can actually contain more that one class, child in
	 *  this context means something different from the default C++ context.
	 *  A parent of an entity means that the CV schema of the parent must
	 *  match all of it's children, but the children have more specific
	 *  CV schema adding specificity on top of the schema of the parent.
	 *
	 */
	static std::vector<Cpp::Structure::Files::OutFiles::Object_base> 		this_object_children;

	/** Actual location in storage for all entities of type _Tp */
//	static std::vector<_Tp > 						this_object_entities;
#endif

};

} /* namespace sheila */

#endif /* ENTITY_ENTITY_HPP_ */
