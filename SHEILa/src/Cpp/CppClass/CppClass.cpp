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

#include <Cpp/CppClass/CppClass.h>

namespace sheila {
namespace cpp {

CppClass::CppClass() {
	// TODO Auto-generated constructor stub

}


const std::vector<std::string>& CppClass::_getName() const {
	return _name;
}

const std::vector<std::string>& CppClass::_getDesc() const {
	return _desc;
}


bool CppClass::hasParent(CppClass e) {
	for (std::vector<CppClass>::iterator it = _parents.begin();
			it != _parents.end(); ++it) {

		if ((*it)._getName() == e._getName()) {
			return true;
		} else if ((*it).hasParent(e)) {
			return true;
		}
	}

	return false;
}

bool CppClass::hasChild(CppClass e) {
	for (std::vector<CppClass>::iterator it = _children.begin();
			it != _children.end(); ++it) {
		if ((*it)._getName() == e._getName()) {
			return true;
		} else if ((*it).hasChild(e)){
			return true;
		}
	}

	return false;
}

int CppClass::addParent(CppClass e, bool _virtual, AccessLevel _access) {

}

int CppClass::addChild(CppClass e, bool _virtual, AccessLevel _access) {

}

int CppClass::editParent(CppClass e, bool _virtual, AccessLevel _access) {

}

int CppClass::editChild(CppClass e, bool _virtual, AccessLevel _access) {

}

int CppClass::removeParent(CppClass e) {

}

int CppClass::removeChild(CppClass e) {

}

const std::vector<CppClass>& CppClass::getParents() const {
	return _parents;
}

const std::vector<CppClass>& CppClass::getChildren() const {
	return _children;
}

CppClass::~CppClass() {
	// TODO Auto-generated destructor stub
}

} /* namespace cpp */
} /* namespace sheila */
