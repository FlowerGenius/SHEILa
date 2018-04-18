/*SHEILa========================================================================
 * Name        : CppPPDirective.h
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 17, 2018
 * Modified    :
 *==============================================================================
 */
#ifndef SRC_CPP_CPPPPDIRECTIVE_CPPPPDIRECTIVE_H_
#define SRC_CPP_CPPPPDIRECTIVE_CPPPPDIRECTIVE_H_

#include "../Cpp.h"

namespace sheila {
namespace cpp {

enum class CppPPDirectiveType : std::string {
	DEFINE  = "#define",
	UNDEF   = "#undef",
	IFDEF   = "#ifdef",
	IFNDEF  = "#ifndef",
	ELSE    = "#else",
	ENDIF   = "#endif",
	IF      = "#if",
	ELIF    = "#elif",
	INCLUDE = "#include",
	ERROR   = "#error",
	LINE    = "#line",
	PRAGMA  = "#pragma"
};



struct CppPPDirective_base : public CppFeature {

	CppPPDirective_base() {
		before = nullptr;
	}


	virtual ~CppPPDirective_base() {
		;
	}

	/* The feature that comes before the directive
	 *
	 */
	CppFeature* before;


};

template<CppPPDirectiveType _Td>
class CppPPDirective : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:

};

template<>
class CppPPDirective<CppPPDirectiveType::DEFINE> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:

};

template<>
class CppPPDirective<CppPPDirectiveType::UNDEF> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:

};

template<>
class CppPPDirective<CppPPDirectiveType::IFDEF> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:

};

template<>
class CppPPDirective<CppPPDirectiveType::IFNDEF> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:

};

template<>
class CppPPDirective<CppPPDirectiveType::ELSE> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:

};

template<>
class CppPPDirective<CppPPDirectiveType::IF> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:

};

template<>
class CppPPDirective<CppPPDirectiveType::ELIF> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:

};

template<>
class CppPPDirective<CppPPDirectiveType::INCLUDE> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:

};

template<>
class CppPPDirective<CppPPDirectiveType::ERROR> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:

};

template<>
class CppPPDirective<CppPPDirectiveType::LINE> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:

};

template<>
class CppPPDirective<CppPPDirectiveType::PRAGMA> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:

};

} /* namespace cpp */
} /* namespace sheila */

#endif /* SRC_CPP_CPPPPDIRECTIVE_CPPPPDIRECTIVE_H_ */
