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


namespace sheila {
namespace cpp {

class CppClass {
public:
	CppClass();
	virtual ~CppClass();

	virtual const std::vector<std::string>& _getName() const;
	virtual const std::vector<std::string>& _getDesc() const;


	/* Inheritance */

	virtual bool hasParent(CppClass);
	virtual bool hasChild(CppClass);
	virtual int addParent(CppClass, bool _virtual, AccessLevel _level);
	virtual int addChild(CppClass, bool _virtual, AccessLevel _level);
	virtual int editParent(CppClass, bool _virtual, AccessLevel _level);
	virtual int editChild(CppClass, bool _virtual, AccessLevel _level);
	virtual int removeParent(CppClass);
	virtual int removeChild(CppClass);
	virtual const std::vector<CppClass>& getParents() const;
	virtual const std::vector<CppClass>& getChildren() const;


	/* Member Functions */

	virtual bool hasMemberFunction(CppMemberFunction);
	virtual int addMemberFunction(CppMemberFunction);
	virtual int editMemberFunction(CppMemberFunction);
	virtual int removeMemberFunction(CppMemberFunction);
	virtual const std::vector<CppMemberFunction>& getMemberFunctions() const;


	/* Data Members */

	virtual bool hasDataMember(CppDataMember);
	virtual int addDataMember(CppDataMember);
	virtual int editDataMember(CppDataMember);
	virtual int removeDataMember(CppDataMember);
	virtual const std::vector<CppDataMember>& getDataMembers() const;

protected:

	std::vector<CppClass> _parents;
	std::vector<CppClass> _children;


	std::vector<std::string> 			_name;
	std::vector<std::string> 			_desc;

	std::time_t							_time_created;
	std::time_t							_time_accessed;
	std::time_t							_time_modified;
	std::vector<CppMemberFunction> 		_member_functions;
	std::vector<CppDataMember> 			_data_members;

};


} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPPCLASS_CPPCLASS_H_ */
