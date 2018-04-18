/*SHEILa========================================================================
 * Name        : CppDeclaration.h
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 17, 2018
 * Modified    :
 *==============================================================================
 */
#ifndef SRC_CPP_CPPDECLARATION_CPPDECLARATION_H_
#define SRC_CPP_CPPDECLARATION_CPPDECLARATION_H_

#include <string>
#include <vector>

#include "../Cpp.h"
#include "../CppVariable/CppVariable.h"
#include "../CppFunction/CppFunction.h"
#include "../CppClass/CppClass.h"

namespace sheila {
namespace cpp {


//typedef enum cpp_declaration_types {
//		FUNCTION,
//		VARIABLE,
//		POINTER,
//		CLASS,
//		OBJECT
//} CppDeclarationType;

template<class _Td>
class CppDeclaration {
public:
	CppDeclaration();
	virtual ~CppDeclaration();
};

/*
 * A declaration of a variable
 */
template<>
class CppDeclaration<CppVariable> {
	CppDeclaration();
	virtual ~CppDeclaration();
};

/*
 * A declaration of a function, aka prototype
 */
template<>
class CppDeclaration<CppFunction> {
	CppDeclaration();
	virtual ~CppDeclaration();
};

/*
 * A declaration of a class, aka forward declaration
 */
template<>
class CppDeclaration<CppVariable> {
	CppDeclaration();
	virtual ~CppDeclaration();
};



} /* namespace cpp */
} /* namespace sheila */

#endif /* SRC_CPP_CPPDECLARATION_CPPDECLARATION_H_ */
