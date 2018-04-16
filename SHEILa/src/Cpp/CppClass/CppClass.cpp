//SHEILa========================================================================
// Name        : CppClass.cpp
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 4, 2018
// Modified    :
//==============================================================================

#include "CppClass.h"

namespace sheila {
namespace cpp {

template<cpp::ClassType _Type>
CppClass<_Type>::CppClass() {
	// TODO Auto-generated constructor stub

}

const std::vector<std::string>& CppClass_base::_getName() const {
	return (*_name);
}

const std::vector<std::string>& CppClass_base::_getDesc() const {
	return (*_desc);

}

bool CppClass_advanced::hasParent(CppClass_advanced e) {
	for (std::vector<CppClass_advanced>::iterator it = _parents->begin();
			it != _parents->end(); ++it) {

		if ((*it)._getName() == e._getName()) {
			return true;
		} else if ((*it).hasParent(e)) {
			return true;
		}
	}

	return false;
}


bool CppClass_advanced::hasChild(CppClass_advanced e) {
	for (std::vector<CppClass_advanced>::iterator it = _children->begin();
			it != _children->end(); ++it) {
		if ((*it)._getName() == e._getName()) {
			return true;
		} else if ((*it).hasChild(e)){
			return true;
		}
	}

	return false;
}

int CppClass_advanced::addParent(CppClass_advanced e, bool _virtual, AccessLevel _access) {
	return 0;
}

int CppClass_advanced::addChild(CppClass_advanced e, bool _virtual, AccessLevel _access) {
	return 0;
}

int CppClass_advanced::editParent(CppClass_advanced e, bool _virtual, AccessLevel _access) {
	return 0;
}

int CppClass_advanced::editChild(CppClass_advanced e, bool _virtual, AccessLevel _access) {
	return 0;
}

int CppClass_advanced::removeParent(CppClass_advanced e) {
	return 0;
}

int CppClass_advanced::removeChild(CppClass_advanced e) {
	return 0;
}

const std::vector<CppClass_advanced>& CppClass_advanced::getParents() const {
	return (*_parents);
}

const std::vector<CppClass_advanced>& CppClass_advanced::getChildren() const {
	return (*_children);
}

///* Member Functions */
//
//bool CppClass::hasMemberFunction(CppMemberFunction f){
//	for (std::vector<CppMemberFunction>::iterator it = _member_functions.begin();
//			it != _member_functions.end(); ++it) {
//
//		if ((*it).getIdentifier() == f.getIdentifier()) {
//			return true;
//		}
//	}
//
//	return false;
//}
//int CppClass::addMemberFunction(CppMemberFunction){
//	return 0;
//}
//int CppClass::editMemberFunction(CppMemberFunction){
//	return 0;
//}
//int CppClass::removeMemberFunction(CppMemberFunction){
//	return 0;
//}
//const std::vector<CppMemberFunction>& CppClass::getMemberFunctions() const {
//	return _member_functions;
//}
//
//
///* Data Members */
//
//bool CppClass::hasDataMember(CppDataMember m) {
//	for (std::vector<CppDataMember>::iterator it = _data_members.begin();
//			it != _data_members.end(); ++it) {
//
//		if ((*it).getIdentifier() == m.getIdentifier()) {
//			return true;
//		}
//	}
//
//	return false;
//}
//int CppClass::addDataMember(CppDataMember) {
//	return 0;
//}
//int CppClass::editDataMember(CppDataMember) {
//	return 0;
//}
//int CppClass::removeDataMember(CppDataMember) {
//	return 0;
//}
//const std::vector<CppDataMember>& CppClass::getDataMembers() const {
//	return _data_members;
//}

template<cpp::ClassType _Type>
CppClass<_Type>::~CppClass() {
	// TODO Auto-generated destructor stub
}

} /* namespace cpp */
} /* namespace sheila */
