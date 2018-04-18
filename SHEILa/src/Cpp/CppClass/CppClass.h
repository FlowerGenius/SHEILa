//SHEILa========================================================================
// Name        : CppClass.h
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 4, 2018
// Modified    :
//==============================================================================

#ifndef CPP_CPPCLASS_CPPCLASS_H_
#define CPP_CPPCLASS_CPPCLASS_H_

#include <string>
#include <vector>
#include <ctime>

#include "../Cpp.h"
#include "../CppDataMember/CppDataMember.h"
#include "../CppMemberFunction/CppMemberFunction.h"
#include "../CppHeader/CppHeader.h"
#include "../CppMacro/CppMacro.h"
#include "../CppConstructor/CppConstructor.h"
#include "../CppDestructor/CppDestructor.h"


namespace sheila {
namespace cpp {

enum class ClassType : std::string {
	CLASS = "class",
	STRUCT = "struct",
	UNION = "union"
};

/* functions and members shared by every type of class */
struct CppClass_base {
public:
//	CppClass_base();
	virtual ~CppClass_base() {
		;
	}

	virtual const std::vector<std::string>& _getName() const;
	virtual const std::vector<std::string>& _getDesc() const;

	/* Constructors */

	bool hasConstructor(cpp::CppConstructor);
	int addConstructor(cpp::CppConstructor);
	int editConstructor(cpp::CppConstructor);
	int removeConstructor(cpp::CppConstructor);
	const std::vector<cpp::CppConstructor>& getConstructors() const;


	/* Destructors */


	bool hasDestructor(cpp::CppDestructor);
	int addDestructor(cpp::CppDestructor);
	int editDestructor(cpp::CppDestructor);
	int removeDestructor(cpp::CppDestructor);
	const std::vector<cpp::CppDestructor>& getDestructors() const;

	/* Member Functions */

	bool hasMemberFunction(cpp::CppMemberFunction);
	int addMemberFunction(cpp::CppMemberFunction);
	int editMemberFunction(cpp::CppMemberFunction);
	int removeMemberFunction(cpp::CppMemberFunction);
	const std::vector<cpp::CppMemberFunction>& getMemberFunctions() const;


	/* Data Members */

	bool hasDataMember(cpp::CppDataMember);
	int addDataMember(cpp::CppDataMember);
	int editDataMember(cpp::CppDataMember);
	int removeDataMember(cpp::CppDataMember);
	const std::vector<cpp::CppDataMember>& getDataMembers() const;

protected:
	std::time_t*							_time_created;
	std::time_t*							_time_accessed;
	std::time_t*							_time_modified;
	std::vector<std::string>* 			_name;
	std::vector<std::string>* 			_desc;
	std::vector<cpp::CppConstructor>*	_constructors;
	std::vector<cpp::CppDestructor>*		_destructors;
	std::vector<cpp::CppMemberFunction>* _member_functions;
	std::vector<cpp::CppDataMember>* 	_data_members;

};

/* functions and members shared by the advanced class types */
struct CppClass_advanced : public CppClass_base {
public:

//	CppClass_advanced();
	virtual ~CppClass_advanced() {
		;
	}

	/* Inheritance */

	virtual bool hasParent(CppClass_advanced);
	virtual bool hasChild(CppClass_advanced);
	virtual int addParent(CppClass_advanced, bool _virtual, AccessLevel _level);
	virtual int addChild(CppClass_advanced, bool _virtual, AccessLevel _level);
	virtual int editParent(CppClass_advanced, bool _virtual, AccessLevel _level);
	virtual int editChild(CppClass_advanced, bool _virtual, AccessLevel _level);
	virtual int removeParent(CppClass_advanced);
	virtual int removeChild(CppClass_advanced);
	virtual const std::vector<CppClass_advanced>& getParents() const;
	virtual const std::vector<CppClass_advanced>& getChildren() const;




protected:

	std::vector<CppClass_advanced>* 			_parents;
	std::vector<CppClass_advanced>* 			_children;


};


template<cpp::ClassType _Type = ClassType::CLASS>
class CppClass : public CppClass_advanced {
public:
	CppClass();
	virtual ~CppClass();
};

template<>
class CppClass<ClassType::STRUCT> : public CppClass_advanced {
public:
	CppClass();
	virtual ~CppClass();
};

typedef CppClass<ClassType::STRUCT> CppStruct;

template<>
class CppClass<ClassType::UNION> : public CppClass_base {
public:
	CppClass();
	virtual ~CppClass();
};

typedef CppClass<ClassType::UNION> CppUnion;



} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPPCLASS_CPPCLASS_H_ */
