/*SHEILa========================================================================
 * Name        : CppFile.h
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 17, 2018
 * Modified    :
 *==============================================================================
 */
#ifndef SRC_CPP_CPPFILE_CPPFILE_H_
#define SRC_CPP_CPPFILE_CPPFILE_H_

#include <string>
#include <vector>

#include "../CppClass/CppClass.h"
#include "../CppPPDirective/CppPPDirective.h"
#include "../CppVariable/CppVariable.h"
#include "../CppFunction/CppFunction.h"
#include "../CppClassObject/CppClassObject.h"
#include "../CppEnumeration/CppEnumeration.h"
#include "../CppTypeDefinition/CppTypeDefinition.h"
#include "../CppDeclaration/CppDeclaration.h"
#include "../CppNameSpace/CppNameSpace.h"


namespace sheila {
namespace cpp {

class CppFile {
public:
	CppFile();
	virtual ~CppFile();

protected:

	/*
	 * Function definitions
	 */
	std::vector<CppFunction> 	 contained_functions;

	/*
	 * Class definitions
	 */
	std::vector<CppClass<ClassType::CLASS> >		 contained_classes;

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



	/*
	 * A list of all define directives in this file.
	 */
	std::vector<CppPPDirective<PP_DEFINE> >  pp_defines;

	/*
	 * A list of all undef directives in this file.
	 */
	std::vector<CppPPDirective<PP_UNDEF> >   pp_undefines;

	/*
	 * A list of all ifdef directives in this file.
	 */
	std::vector<CppPPDirective<PP_IFDEF> >   pp_ifdefines;

	/*
	 * A list of all ifndef directives in this file.
	 */
	std::vector<CppPPDirective<PP_IFNDEF> >  pp_ifnotdefines;

	/*
	 * A list of all else directives in this file.
	 */
	std::vector<CppPPDirective<PP_ELSE> >    pp_elses;

	/*
	 * A list of all endif directives in this file.
	 */
	std::vector<CppPPDirective<PP_ENDIF> >   pp_endifs;

	/*
	 * A list of all elif directives in this file.
	 */
	std::vector<CppPPDirective<PP_ELIF> >    pp_elifs;

	/*
	 * A list of all include directives in this file.
	 */
	std::vector<CppPPDirective<PP_INCLUDE> > pp_includes;

	/*
	 * A list of all error directives in this file.
	 */
	std::vector<CppPPDirective<PP_ERROR> >   pp_errors;

	/*
	 * A list of all line directives in this file.
	 */
	std::vector<CppPPDirective<PP_LINE> >    pp_lines;

	/*
	 * A list of all pragma directives in this file.
	 */
	std::vector<CppPPDirective<PP_PRAGMA> >  pp_pragmas;

};

} /* namespace cpp */
} /* namespace sheila */

#endif /* SRC_CPP_CPPFILE_CPPFILE_H_ */
