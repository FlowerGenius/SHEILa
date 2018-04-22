/*SHEILa========================================================================
 * Name        : CppCompoundType.h
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 17, 2018
 * Modified    :
 *==============================================================================
 */
#ifndef SRC_PROGRAMMINGLANGUAGE_CPP_CPPCOMPOUNDTYPE_CPPCOMPOUNDTYPE_H_
#define SRC_PROGRAMMINGLANGUAGE_CPP_CPPCOMPOUNDTYPE_CPPCOMPOUNDTYPE_H_

namespace sheila {
namespace cpp {

typedef enum cpp_compound_type_types {
	ENUMERATION,
	ARRAY,
	STRING,
	POINTER,
	POINTER_TO_MEMBER,
	REFERENCE,
	CLASS,
	STRUCT,
	UNION,
	FUNCTION
} CppCompoundTypeType;

struct CppCompoundType_base /*: public CppType */ {
	CppCompoundType_base(){
		;
	}

	virtual ~CppCompoundType_base(){
		;
	}
};

template<CppCompoundTypeType _Tt>
class CppCompoundType : public CppCompoundType_base {
public:
	CppCompoundType();
	virtual ~CppCompoundType();
};

template<>
class CppCompoundType<ENUMERATION> : public CppCompoundType_base {
	CppCompoundType();
	virtual ~CppCompoundType();
};

template<>
class CppCompoundType<ARRAY> : public CppCompoundType_base {
	CppCompoundType();
	virtual ~CppCompoundType();
};

template<>
class CppCompoundType<STRING> : public CppCompoundType_base {
	CppCompoundType();
	virtual ~CppCompoundType();
};

template<>
class CppCompoundType<POINTER> : public CppCompoundType_base {
	CppCompoundType();
	virtual ~CppCompoundType();
};

template<>
class CppCompoundType<POINTER_TO_MEMBER> : public CppCompoundType_base {
	CppCompoundType();
	virtual ~CppCompoundType();
};

template<>
class CppCompoundType<REFERENCE> : public CppCompoundType_base {
	CppCompoundType();
	virtual ~CppCompoundType();
};

template<>
class CppCompoundType<CLASS> : public CppCompoundType_base {
	CppCompoundType();
	virtual ~CppCompoundType();
};

template<>
class CppCompoundType<STRUCT> : public CppCompoundType_base {
	CppCompoundType();
	virtual ~CppCompoundType();
};

template<>
class CppCompoundType<UNION> : public CppCompoundType_base {
	CppCompoundType();
	virtual ~CppCompoundType();
};

template<>
class CppCompoundType<FUNCTION> : public CppCompoundType_base {
	CppCompoundType();
	virtual ~CppCompoundType();
};

} /* namespace cpp */
} /* namespace sheila */

#endif /* SRC_PROGRAMMINGLANGUAGE_CPP_CPPCOMPOUNDTYPE_CPPCOMPOUNDTYPE_H_ */
