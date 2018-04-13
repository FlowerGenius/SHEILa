//SHEILa========================================================================
// Name        : Entity.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Mar 29, 2018
// Modified    :
//==============================================================================

#ifndef ENTITY_ENTITY_H_
#define ENTITY_ENTITY_H_

#include "../symbols.inc"

#include "../Cpp/Cpp.h"
#include "../Cpp/CppClass/CppClass.h"
#include "../Cpp/CppMemberFunction/CppMemberFunction.h"
#include "../Cpp/CppDataMember/CppDataMember.h"


#include <string>
#include <vector>
#include <typeinfo>
#include <stdint.h>
#include <ctime>


namespace sheila {

/* An Entity is, put simply, a C++ class as perceived by SHEILa. */
class Entity {

/*
 * Any instance of an entity or of its children has a file on the disk.
 */

public:

	static std::vector<Entity> entities;

	/* Helper functions */

	static int createNewEntity(
			std::vector<std::string> names,
			std::vector<std::string> descs,
			std::vector<std::string> cvinf
 	);

	Entity();
	virtual ~Entity();;

	int commitClassToDisk();
	int loadClassFromDisk();


	/* Inheritance */

	bool hasParent(Entity);
	bool hasChild(Entity);
	int addParent(Entity, bool _virtual, cpp::AccessLevel _level);
	int addChild(Entity, bool _virtual, cpp::AccessLevel _level);
	int editParent(Entity, bool _virtual, cpp::AccessLevel _level);
	int editChild(Entity, bool _virtual, cpp::AccessLevel _level);
	int removeParent(Entity);
	int removeChild(Entity);
	const std::vector<Entity>& _getParents() const;
	const std::vector<Entity>& _getChildren() const;

	/* Constructors */


	/* Destructors */


	/* Member Functions */

	bool hasMemberFunction(cpp::CppMemberFunction);
	int addMemberFunction(cpp::CppMemberFunction);
	int editMemberFunction(cpp::CppMemberFunction);
	int removeMemberFunction(cpp::CppMemberFunction);
	const std::vector<cpp::CppMemberFunction>& _getMemberFunctions() const;


	/* Data Members */

	bool hasDataMember(cpp::CppDataMember);
	int addDataMember(cpp::CppDataMember);
	int editDataMember(cpp::CppDataMember);
	int removeDataMember(cpp::CppDataMember);
	const std::vector<cpp::CppDataMember>& _getDataMembers() const;

	/* Entity metadata */

	const std::vector<std::string>& _getName() const;
	const std::vector<std::string>& _getDesc() const;


	/* The id on the server of an instance of this class
	 *
	 */
	uintmax_t _getInstanceID();

	/* The location on the server database of where this class and it's
	 * header file are located.
	 */
	std::string _getClassPath();

	/* The location on the server database of where substantive instances
	 * of this class will be stored.
	 */
	std::string _getInstancePath();

protected:


	/* Data Members describing the instance they are accessed from.
	 *
	 * IMPORTANT! NONE OF THESE MEMBERS MAY BE INITIALIZED IN A
	 * DEFAULT CONSTRUCTOR
	 */

	uintmax_t 							instance_id;
	std::vector<std::string> 			name; //line 1 of instance file
	std::vector<std::string>			desc; //line 2 of instance file
	std::vector<std::string>			picture_paths;
	std::vector<std::string>			video_paths;
	std::vector<std::string>			sound_paths;
	std::vector<std::string>			document_paths;
	std::vector<std::string>			program_paths;
	std::vector<long double>			emotion_values;
	std::vector<std::string>			cv_filters;


	/* Member Functions that modify the instance they are accessed from.
	 *
	 * IMPORTANT! ALL OF THESE FUNCTIONS MUST BE OVERRIDDEN IN EVERY
	 * SUBCLASS OF ENTITY
	 */


	virtual std::string 				_E_repr();
	virtual void 						_E_eval(std::string);

	/* Data Members describing the class they are accessed from.
	 *
	 * IMPORTANT! ALL OF THESE MEMBERS MUST BE INITIALIZED IN EVERY
	 * CONSTRUCTOR OF EVERY SUBCLASS OF ENTITY
	 *
	 * TL;DR The following members represent some feature of the code itself
	 * for the class from which it is called.
	 */

	std::time_t*						_time_created;
	std::time_t*						_time_accessed;
	std::time_t*						_time_modified;
	std::vector<long double>*			_emotion_values;
	std::vector<std::string>* 			_name;
	std::vector<std::string>* 			_desc;
	std::vector<std::string>*			_cv_filters;
	std::vector<Entity>* 				_parents;
	std::vector<Entity>* 				_children;
	std::vector<cpp::CppMemberFunction>* _member_functions;
	std::vector<cpp::CppDataMember>* 	_data_members;

	/* Member Functions that modify the class they are accessed from.
	 *
	 * IMPORTANT! THESE FUNCTIONS MUST NEVER BE OVERRIDDEN IN ANY SUBCLASS
	 * OF ENTITY
	 */

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

#endif /* ENTITY_ENTITY_H_ */
