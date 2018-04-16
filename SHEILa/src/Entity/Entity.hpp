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
#include "../C/language.inc"

namespace sheila {

typedef enum sheila_entity_types {
	ENTITY_T = -1,
	EMOTION_T,
	FEELING_T,
	INSTRUCTION_SET_ARCHITECTURE_T,
	IPADDRESS_T,
	IPv4_T,
	IPv6_T,
	LANGUAGE_T,
	MANUFACTURER_T,
	MOOD_T,
	NATURAL_LANGUAGE_T,
	NETWORK_T,
	OPERATING_SYSTEM_T,
	PLATFORM_T,
	PROCESSOR_T,
	PROGRAMMING_LANGUAGE_T,
	RANGE_T,
	RUNTIME_T,
	SCHEMA_T,
	SERVER_T,
	SHEILA_CORE_SERVER_t,
	UNKOWN_ENTITY_T,
	VENDOR_T,
	VERSION_T
} SheilaEntityType;






///* An Entity is, put simply, a C++ class as perceived by SHEILa. */
//class Entity {
//
///*
// * Any instance of an entity or of its children has a file on the disk.
// */
//
//public:
//
//	static std::vector<Entity> entities;
//
//	/* Helper functions */
//
//	static int createNewEntity(
//			std::vector<std::string> names,
//			std::vector<std::string> descs,
//			std::vector<std::string> cvinf
// 	);
//
//	Entity();
//	virtual ~Entity();;
//
//	int commitClassToDisk();
//	int loadClassFromDisk();
//
//
//	/* Inheritance */
//
//	bool hasParent(Entity);
//	bool hasChild(Entity);
//	int addParent(Entity, bool _virtual, cpp::AccessLevel _level);
//	int addChild(Entity, bool _virtual, cpp::AccessLevel _level);
//	int editParent(Entity, bool _virtual, cpp::AccessLevel _level);
//	int editChild(Entity, bool _virtual, cpp::AccessLevel _level);
//	int removeParent(cpp::CppClass_advanced);
//	int removeChild(cpp::CppClass_advanced);
//	const std::vector<cpp::CppClass_advanced>& _getParents() const;
//	const std::vector<cpp::CppClass_advanced>& _getChildren() const;
//
//	/* Preprocessor Cpp Standard Library Includes */
//
//	bool hasInclude(cpp::CppStandardHeaderFile);
//	int addInclude(cpp::CppStandardHeaderFile);
//	int editInclude(cpp::CppStandardHeaderFile, cpp::CppStandardHeaderFile);
//	int removeInclude(cpp::CppStandardHeaderFile);
//	const std::vector<cpp::CppStandardHeaderFile>& _getCppIncludes() const;
//
//	/* Preprocessor C Standard Library Includes */
//
//	bool hasInclude(c::CStandardHeaderFile);
//	int addInclude(c::CStandardHeaderFile);
//	int editInclude(c::CStandardHeaderFile, c::CStandardHeaderFile);
//	int removeInclude(c::CStandardHeaderFile);
//	const std::vector<c::CStandardHeaderFile>& _getCIncludes() const;
//
//	/* Preprocessor Included files */
//
//	bool hasInclude(cpp::CppHeaderFile);
//	int addInclude(cpp::CppHeaderFile);
//	int editInclude(cpp::CppHeaderFile, cpp::CppHeaderFile);
//	int removeInclude(cpp::CppHeaderFile);
//	const std::vector<cpp::CppHeaderFile>& _getIncludes() const;
//
//	/* Preprocessor Macros */
//
//	bool hasMacro(cpp::CppMacro);
//	int addMacro(cpp::CppMacro);
//	int editMacro(cpp::CppMacro, cpp::CppMacro);
//	int removeMacro(cpp::CppMacro);
//	const std::vector<cpp::CppMacro>& _getMacros() const;
//
//	/* Preprocessor Symbols */
//
//	bool hasSymbol(cpp::CppSymbol);
//	int addSymbol(cpp::CppSymbol);
//	int editSymbol(cpp::CppSymbol, cpp::CppSymbol);
//	int removeSymbol(cpp::CppSymbol);
//	const std::vector<cpp::CppSymbol>& _getSymbols() const;
//
//
//	/* Constructors */
//
//	bool hasConstructor(cpp::CppConstructor);
//	int addConstructor(cpp::CppConstructor);
//	int editConstructor(cpp::CppConstructor, cpp::CppConstructor);
//	int removeConstructor(cpp::CppConstructor);
//	const std::vector<cpp::CppConstructor>& _getConstructors() const;
//
//
//	/* Destructors */
//
//
//	bool hasDestructor(cpp::CppDestructor);
//	int addDestructor(cpp::CppDestructor);
//	int editDestructor(cpp::CppDestructor, cpp::CppDestructor);
//	int removeDestructor(cpp::CppDestructor);
//	const std::vector<cpp::CppDestructor>& _getDestructors() const;
//
//	/* Member Functions */
//
//	bool hasMemberFunction(cpp::CppMemberFunction);
//	int addMemberFunction(cpp::CppMemberFunction);
//	int editMemberFunction(cpp::CppMemberFunction, cpp::CppMemberFunction);
//	int removeMemberFunction(cpp::CppMemberFunction);
//	const std::vector<cpp::CppMemberFunction>& _getMemberFunctions() const;
//
//
//	/* Data Members */
//
//	bool hasDataMember(cpp::CppDataMember);
//	int addDataMember(cpp::CppDataMember);
//	int editDataMember(cpp::CppDataMember, cpp::CppDataMember);
//	int removeDataMember(cpp::CppDataMember);
//	const std::vector<cpp::CppDataMember>& _getDataMembers() const;
//
//	/* Entity metadata */
//
//	const std::vector<std::string>& _getName() const;
//	const std::vector<std::string>& _getDesc() const;
//
//
//	/* The id on the server of an instance of this class
//	 *
//	 */
//	uintmax_t _getInstanceID();
//
//	/* The location on the server database of where this class and it's
//	 * header file are located.
//	 */
//	std::string _getClassPath();
//
//	/* The location on the server database of where substantive instances
//	 * of this class will be stored.
//	 */
//	std::string _getInstancePath();
//
//protected:
//
//
//	/* Data Members describing the instance they are accessed from.
//	 *
//	 * IMPORTANT! NONE OF THESE MEMBERS MAY BE INITIALIZED IN A
//	 * DEFAULT CONSTRUCTOR
//	 */
//
//	uintmax_t 							instance_id;
//	std::vector<std::string> 			name; //line 1 of instance file
//	std::vector<std::string>			desc; //line 2 of instance file
//	std::vector<std::string>			picture_paths;
//	std::vector<std::string>			video_paths;
//	std::vector<std::string>			sound_paths;
//	std::vector<std::string>			document_paths;
//	std::vector<std::string>			program_paths;
//	std::vector<long double>			emotion_values;
//	std::vector<std::string>			cv_filters;
//
//
//	/* Member Functions that modify the instance they are accessed from.
//	 *
//	 * IMPORTANT! ALL OF THESE FUNCTIONS MUST BE OVERRIDDEN IN EVERY
//	 * SUBCLASS OF ENTITY
//	 */
//
//
//	virtual std::string 				_E_repr();
//	virtual void 						_E_eval(std::string);
//
//	/* Data Members describing the class they are accessed from.
//	 *
//	 * IMPORTANT! ALL OF THESE MEMBERS MUST BE INITIALIZED IN EVERY
//	 * CONSTRUCTOR OF EVERY SUBCLASS OF ENTITY
//	 *
//	 * TL;DR The following members represent some feature of the code itself
//	 * for the class from which it is called.
//	 */
//
//
//	SheilaEntityType*							_Type;
//	std::time_t*								_time_created;
//	std::time_t*								_time_accessed;
//	std::time_t*								_time_modified;
//	std::vector<long double>*					_emotion_values;
//	std::vector<std::string>* 					_name;
//	std::vector<std::string>* 					_desc;
//	std::vector<std::string>*					_cv_filters;
//	std::vector<cpp::CppClass_advanced>* 		_parents;
//	std::vector<cpp::CppClass_advanced>* 		_children;
//	std::vector<cpp::CppStandardHeaderFile>*	_cpp_include_files;
//	std::vector<c::CStandardHeaderFile>*		_c_include_files;
//	std::vector<cpp::CppHeaderFile>*			_include_files;
//	std::vector<cpp::CppMacro>*					_macros;
//	std::vector<cpp::CppSymbol>*				_symbols;
//	std::vector<cpp::CppConstructor>*			_constructors;
//	std::vector<cpp::CppDestructor>*			_destructors;
//	std::vector<cpp::CppMemberFunction>* 		_member_functions;
//	std::vector<cpp::CppDataMember>* 			_data_members;
//
//
//private:
//
//	const static SheilaEntityType					_Type_ = ENTITY_T;
//	static std::time_t								_time_created_;
//	static std::time_t								_time_accessed_;
//	static std::time_t								_time_modified_;
//	static std::vector<long double>					_emotion_values_;
//	static std::vector<std::string> 				_name_;
//	static std::vector<std::string> 				_desc_;
//	static std::vector<std::string>					_cv_filters_;
//	static std::vector<cpp::CppClass_advanced> 		_parents_;
//	static std::vector<cpp::CppClass_advanced> 		_children_;
//	static std::vector<cpp::CppStandardHeaderFile>	_cpp_include_files_;
//	static std::vector<c::CStandardHeaderFile>		_c_include_files_;
//	static std::vector<cpp::CppHeaderFile>			_include_files_;
//	static std::vector<cpp::CppMacro>				_macros_;
//	static std::vector<cpp::CppSymbol>				_symbols_;
//	static std::vector<cpp::CppConstructor>			_constructors_;
//	static std::vector<cpp::CppDestructor>			_destructors_;
//	static std::vector<cpp::CppMemberFunction> 		_member_functions_;
//	static std::vector<cpp::CppDataMember> 			_data_members_;
//
//};

template<SheilaEntityType _Tp>
class SheilaClass : public cpp::CppClass<cpp::CLASS> {

public:



	SheilaClass() {

		_Type = &SheilaClass<_Tp>::_Type_;

		_time_accessed  = &SheilaClass<_Tp>::_time_accessed_;
		_time_created   = &SheilaClass<_Tp>::_time_created_;
		_time_modified  = &SheilaClass<_Tp>::_time_modified_;

		_emotion_values = &SheilaClass<_Tp>::_emotion_values_;

		_name = &SheilaClass<_Tp>::_name_;
		_desc = &SheilaClass<_Tp>::_desc_;

		_cv_filters = &SheilaClass<_Tp>::_cv_filters_;

		_parents  = &SheilaClass<_Tp>::_parents_;
		_children = &SheilaClass<_Tp>::_children_;

		_c_include_files    = &SheilaClass<_Tp>::_c_include_files_;
		_cpp_include_files  = &SheilaClass<_Tp>::_cpp_include_files_;
		_include_files      = &SheilaClass<_Tp>::_include_files_;

		_constructors		= &SheilaClass<_Tp>::_constructors_;
		_destructors        = &SheilaClass<_Tp>::_destructors_;
		_member_functions   = &SheilaClass<_Tp>::_member_functions_;
		_data_members       = &SheilaClass<_Tp>::_data_members_;

	};

	virtual ~SheilaClass() {

	};

	static const std::string& getSheilaClassSourcePath() {
		return _source_path_;
	}

	static const SheilaEntityType getSheilaClassType() {
		return _Type_;
	}

	static std::time_t getSheilaClassTimeAccessed() {
		return _time_accessed_;
	}

	static std::time_t getSheilaClassTimeCreated() {
		return _time_created_;
	}

	static std::time_t getSheilaClassTimeModified() {
		return _time_modified_;
	}

	static const std::vector<c::CStandardHeaderFile>& getSheilaClassCIncludeFiles() {
		return _c_include_files_;
	}

	static const std::vector<cpp::CppClass_advanced>& getSheilaClassChildren()  {
		return _children_;
	}

	static const std::vector<cpp::CppConstructor>& getSheilaClassConstructors()  {
		return _constructors_;
	}

	static const std::vector<cpp::CppStandardHeaderFile>& getSheilaClassCppIncludeFiles()  {
		return _cpp_include_files_;
	}

	static const std::vector<std::string>& getSheilaClassCvFilters()  {
		return _cv_filters_;
	}

	static const std::vector<cpp::CppDataMember>& getSheilaClassDataMembers()  {
		return _data_members_;
	}

	static const std::vector<std::string>& getSheilaClassDesc()  {
		return _desc_;
	}

	static const std::vector<cpp::CppDestructor>& getSheilaClassDestructors()  {
		return _destructors_;
	}

	static const std::vector<long double>& getSheilaClassEmotionValues()  {
		return _emotion_values_;
	}

	static const std::vector<cpp::CppHeaderFile>& getSheilaClassIncludeFiles()  {
		return _include_files_;
	}

	static const std::vector<cpp::CppMemberFunction>& getSheilaClassMemberFunctions()  {
		return _member_functions_;
	}

	static const std::vector<std::string>& getSheilaClassName()  {
		return _name_;
	}

	static const std::vector<cpp::CppClass_advanced>& getSheilaClassParents()  {
		return _parents_;
	}


protected:

	const static SheilaEntityType					_Type_ = _Tp;
	static std::string								_source_path_;
	static std::time_t								_time_created_;
	static std::time_t								_time_accessed_;
	static std::time_t								_time_modified_;
	static std::vector<long double>					_emotion_values_;
	static std::vector<std::string> 				_name_;
	static std::vector<std::string> 				_desc_;
	static std::vector<std::string>					_cv_filters_;
	static std::vector<cpp::CppClass_advanced> 		_parents_;
	static std::vector<cpp::CppClass_advanced> 		_children_;
	static std::vector<cpp::CppStandardHeaderFile>	_cpp_include_files_;
	static std::vector<c::CStandardHeaderFile>		_c_include_files_;
	static std::vector<cpp::CppHeaderFile>			_include_files_;
//	static std::vector<cpp::CppMacro>				_macros_;
//	static std::vector<cpp::CppSymbol>				_symbols_;
	static std::vector<cpp::CppConstructor>			_constructors_;
	static std::vector<cpp::CppDestructor>			_destructors_;
	static std::vector<cpp::CppMemberFunction> 		_member_functions_;
	static std::vector<cpp::CppDataMember> 			_data_members_;


	const SheilaEntityType*							_Type;
	std::vector<long double>*					_emotion_values;
	std::vector<std::string>*					_cv_filters;
	std::vector<cpp::CppStandardHeaderFile>*	_cpp_include_files;
	std::vector<c::CStandardHeaderFile>*		_c_include_files;
	std::vector<cpp::CppHeaderFile>*			_include_files;
//	std::vector<cpp::CppMacro>*					_macros;
//	std::vector<cpp::CppSymbol>*				_symbols;



	virtual std::string 				_E_repr();
	virtual void 						_E_eval(std::string);

};



} /* namespace sheila */

#endif /* ENTITY_ENTITY_HPP_ */
