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

	static std::time_t mktime(std::string);

	template <class _T>
	static std::string repr(_T e) {
		return e._E_repr();
	}



	static int createNewEntity(
			std::vector<std::string> names,
			std::vector<std::string> descs,
			std::vector<std::string> cvinf,
 	);

	Entity();
	virtual ~Entity();;

	int commitClassToDisk();
	int loadClassFromDisk();


	/* Inheritance */

	virtual bool hasParent(Entity);
	virtual bool hasChild(Entity);
	virtual int addParent(Entity, bool _virtual, cpp::AccessLevel _level);
	virtual int addChild(Entity, bool _virtual, cpp::AccessLevel _level);
	virtual int editParent(Entity, bool _virtual, cpp::AccessLevel _level);
	virtual int editChild(Entity, bool _virtual, cpp::AccessLevel _level);
	virtual int removeParent(Entity);
	virtual int removeChild(Entity);
	virtual const std::vector<Entity>& _getParents() const;
	virtual const std::vector<Entity>& _getChildren() const;

	/* Constructors */


	/* Destructors */


	/* Member Functions */

	virtual bool hasMemberFunction(cpp::CppMemberFunction);
	virtual int addMemberFunction(cpp::CppMemberFunction);
	virtual int editMemberFunction(cpp::CppMemberFunction);
	virtual int removeMemberFunction(cpp::CppMemberFunction);
	virtual const std::vector<cpp::CppMemberFunction>& _getMemberFunctions() const;


	/* Data Members */

	virtual bool hasDataMember(cpp::CppDataMember);
	virtual int addDataMember(cpp::CppDataMember);
	virtual int editDataMember(cpp::CppDataMember);
	virtual int removeDataMember(cpp::CppDataMember);
	virtual const std::vector<cpp::CppDataMember>& _getDataMembers() const;

	/* Entity metadata */

	virtual const std::vector<std::string>& _getName() const;
	virtual const std::vector<std::string>& _getDesc() const;


	/* The id on the server of an instance of this class
	 *
	 */
	virtual uintmax_t _getInstanceID();

	/* The location on the server database of where this class and it's
	 * header file are located.
	 */
	virtual std::string _getClassPath();

	/* The location on the server database of where substantive instances
	 * of this class will be stored.
	 */
	virtual std::string _getInstancePath();

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

	std::time_t							_time_created;
	std::time_t							_time_accessed;
	std::time_t							_time_modified;
	std::vector<long double>			_emotion_values;
	std::vector<std::string> 			_name;
	std::vector<std::string> 			_desc;
	std::vector<std::string>			_cv_filters;
	std::vector<Entity> 				_parents;
	std::vector<Entity> 				_children;
	std::vector<cpp::CppMemberFunction> _member_functions;
	std::vector<cpp::CppDataMember> 	_data_members;

	/* Member Functions that modify the class they are accessed from.
	 *
	 * IMPORTANT! THESE FUNCTIONS MUST NEVER BE OVERRIDDEN IN ANY SUBCLASS
	 * OF ENTITY
	 */

};

} /* namespace sheila */

#endif /* ENTITY_ENTITY_H_ */
