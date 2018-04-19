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

#include "../CppPPDirective/CppPPDirective.h"
#include "../CppNameSpace/CppNameSpace.h"


namespace sheila {
namespace cpp {

/** @brief	An abstract model of a C++ File (ie. [source|header])
 *	@author	FlowerGenius
 *
 *	This class represents a file in the C++ build structure model. A CppFile
 *	can be either a header or a source file. All attributes that are shared
 *	by both headers and source files is kept here.
 */
class CppFile {
public:

	/** @brief Creates an object that represents a C++ file.
	 *	@author FlowerGenius
	 *
	 *	This constructor is meant only for initializing members required by
	 *	derived classes and should never be called excepting that the object
	 *	created then be cast to a derived type.
	 *
	 */
	CppFile();

	/** @brief Destructor for CppFile,
	 *  @author FlowerGenius
	 *
	 */
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
	std::vector< CppPPDirective<CppPPDirectiveType::DEFINE> >  pp_defines;

	/*
	 * A list of all undef directives in this file.
	 */
	std::vector<CppPPDirective<CppPPDirectiveType::UNDEF> >   pp_undefines;

	/*
	 * A list of all ifdef directives in this file.
	 */
	std::vector<CppPPDirective<CppPPDirectiveType::IFDEF> >   pp_ifdefines;

	/*
	 * A list of all ifndef directives in this file.
	 */
	std::vector<CppPPDirective<CppPPDirectiveType::IFNDEF> >  pp_ifnotdefines;

	/*
	 * A list of all else directives in this file.
	 */
	std::vector<CppPPDirective<CppPPDirectiveType::ELSE> >    pp_elses;

	/*
	 * A list of all endif directives in this file.
	 */
	std::vector<CppPPDirective<CppPPDirectiveType::ENDIF> >   pp_endifs;

	/*
	 * A list of all elif directives in this file.
	 */
	std::vector<CppPPDirective<CppPPDirectiveType::ELIF> >    pp_elifs;

	/*
	 * A list of all include directives in this file.
	 */
	std::vector<CppPPDirective<CppPPDirectiveType::INCLUDE> > pp_includes;

	/*
	 * A list of all error directives in this file.
	 */
	std::vector<CppPPDirective<CppPPDirectiveType::ERROR> >   pp_errors;

	/*
	 * A list of all line directives in this file.
	 */
	std::vector<CppPPDirective<CppPPDirectiveType::LINE> >    pp_lines;

	/*
	 * A list of all pragma directives in this file.
	 */
	std::vector<CppPPDirective<CppPPDirectiveType::PRAGMA> >  pp_pragmas;

};

} /* namespace cpp */
} /* namespace sheila */

#endif /* SRC_CPP_CPPFILE_CPPFILE_H_ */
