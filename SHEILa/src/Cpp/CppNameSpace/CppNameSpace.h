/*SHEILa========================================================================
 * Name        : CppNameSpace.h
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 17, 2018
 * Modified    :
 *==============================================================================
 */
#ifndef SRC_CPP_CPPNAMESPACE_CPPNAMESPACE_H_
#define SRC_CPP_CPPNAMESPACE_CPPNAMESPACE_H_

#include <string>
#include <vector>

#include "../Cpp.h"
#include "../CppClass/CppClass.h"
#include "../CppVariable/CppVariable.h"
#include "../CppFunction/CppFunction.h"
#include "../CppClassObject/CppClassObject.h"
#include "../CppEnumeration/CppEnumeration.h"
#include "../CppTypeDefinition/CppTypeDefinition.h"
#include "../CppDeclaration/CppDeclaration.h"

namespace sheila {
namespace cpp {

/*
 * An abstract model of a C++ namespace feature
 */
class CppNameSpace : public CppFeature {
public:

	static std::vector<CppNameSpace> namespaces;

	CppNameSpace();
	virtual ~CppNameSpace();

private:

	/*
	 * Variable definitions
	 */
	std::vector<CppVariable> 	 contained_variables;

	/*
	 * Object definitions
	 */
	std::vector<CppClassObject>  contained_objects;

	/*
	 * Function definitions
	 */
	std::vector<CppFunction> 	 contained_functions;

	/*
	 * Class definitions
	 */
	std::vector<CppClass<ClassType::CLASS> >	contained_classes;

	/*
	 * Struct definitions
	 */
	std::vector<CppStruct>		 contained_structs;

	/*
	 * Union definitions
	 */
	std::vector<CppUnion>		 contained_unions;

	/*
	 * Enum definitions
	 */
	std::vector<CppEnumeration>  contained_enums;

	/*
	 * Type definitions
	 */
	std::vector<CppTypeDefinition> contained_typedefs;

	/*
	 * Namespace definitions
	 */
	std::vector<CppNameSpace>    contained_namespaces;



	/*
	 * Declarations of variables that are not also definitions
	 */
	std::vector<CppDeclaration<CppVariable> > contained_declared_variables;

	/*
	 * Declarations of prototype functions
	 */
	std::vector<CppDeclaration<CppFunction> > contained_prototypes;

	/*
	 * Forward declarations of classes, unions, and structs
	 */
	std::vector<CppDeclaration<CppClass_base> > contained_forward_declarations;


	// TODO implement understanding of the "using" keyword

};

} /* namespace cpp */
} /* namespace sheila */

#endif /* SRC_CPP_CPPNAMESPACE_CPPNAMESPACE_H_ */
