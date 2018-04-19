/*SHEILa========================================================================
 * Name        : CppObject.h
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description :
 * Module      : SHEILa
 * Created     : Apr 16, 2018
 * Modified    :
 *==============================================================================
 */
#ifndef SRC_CPP_CPPOBJECT_CPPOBJECT_H_
#define SRC_CPP_CPPOBJECT_CPPOBJECT_H_

#include <string>
#include <vector>

#include "../../ProgrammingLanguage/XML/XmlFile/XmlFile.h"
#include "../Cpp.h"
#include "../CppSource/CppSource.h"
#include "../CppHeader/CppHeader.h"


namespace sheila {
namespace cpp {

/** @brief The base for all of the specializations of @c CppClass.
 *  @author FlowerGenius
 *
 *  This struct provides a base object for all of the specializations of
 *  @c CppClass. This struct is not meant to ever be used in it's own right,
 *  rather it exists as a wrapper allowing any @c CppObject types to be
 *  accessed, stored, and used iteratively by upcasting to this base.
 *
 */
struct CppObject_base {

	/** @brief Default constructor for all specializations of @c CppObject.
	 *  @author FlowerGenius
	 *
	 *  This constructor should never be called excepting that it is called
	 *  by a derived class as part of the derivation chain.
	 *
	 */
	CppObject_base() {}

	/** @brief Default destructor for all specializations of @c CppObject.
	 *  @author FlowerGenius
	 *
	 *  This denstructor should never be called excepting that it is called
	 *  by a derived class as part of the derivation chain.
	 *
	 */
	virtual ~CppObject_base(){}

};

/** @brief An abstract model of a compilation object in C++.
 *  @author FlowerGenius
 *  @tparam _N 1. @c void for typical usage; 2. @c class that this
 *             specialization will model.
 *
 *  This template class is very strange and possibly not clearly intuitive,
 *  thus this description may be too long to read, skip down to the end for a
 *  concise summary - FlowerGenius
 *
 *  Important Note: The strange nature of the class is a result of it's
 *  intended usage, as this library is not meant for the understanding of
 *  a human developer, rather it is meant for the understanding of the
 *  Software Human Emulated Intelligence (on) Linux [a] a.k.a. @c SHEILa.
 *
 *	Introduction: For the purposes of this model, a C++ compilation object
 *	shall be defined as the combination of a single C++ source file and a
 *	definition of the user defined Header Files included from that source.
 *
 *	All header files included from those main header files shall not be
 *	@e defined by the object, rather they shall be referenced by the object.
 *	That is to say that when a @c CppObject is represented in XML, the XML file
 *	contains only references to non-primary header files. Where the properties
 *	of them can be accessed through their pointer to their respective
 *	@c CppHeader models such that modifications to those models modify them
 *	globally, rather than modifying a local copy of them.
 *
 *  An XML representation of a @c CppObject or one of it's children must be
 *  a model of an entire valid XML file.
 *
 *  Typical Usage (modeling a C++ compilation object) : @c CppObject<@a void >
 *
 *	Adv. Usage (child models a C++ compilation object) : @c CppObject<@a _N >
 *	where @a _N is the class that the @c CppObject is going to model.
 *
 *  TL;DR This class can be used as a typical class where the object that it
 *  represents is indicated by each unique instance of the class; OR it can
 *  be used as a template class where each unique specialization represents
 *  a compilation object.
 *
 */
template<class _N>
class CppObject : private CppObject_base {
public:

	/** @brief Creates a new abstract model of a C++ object
	 *
	 */
	CppObject() {
		;
	}

	/** @brief Builds a new abstract model of a C++ object from an XML file
	 *
	 */
	CppObject(xml::XmlFile*);

	virtual ~CppObject() {
		;
	}

protected:

#if (BUILD_FOR_SHEILA_DAEMON == 1)
	static std::vector<std::string> this_object_names;
	static std::vector<std::string> this_object_authors;
	static std::vector<std::string> this_object_versions;
	static std::vector<std::string> this_object_copyrights;
	static std::vector<std::string> this_object_descriptions;
	static std::vector<std::string> this_object_modules;
	static std::string              this_object_created;
	static std::vector<std::string> this_object_modified;


	static std::vector<cpp::CppHeader*> this_object_headers;
	static cpp::CppSource*              this_object_source;
#endif

private:

	std::vector<std::string> object_names;
	std::vector<std::string> object_authors;
	std::vector<std::string> object_versions;
	std::vector<std::string> object_copyrights;
	std::vector<std::string> object_descriptions;
	std::vector<std::string> object_modules;
	std::string              object_created;
	std::vector<std::string> object_modified;


	std::vector<cpp::CppHeader*> object_headers;
	cpp::CppSource*              object_source;


};

} /* namespace cpp */
} /* namespace sheila */

#endif /* SRC_CPP_CPPOBJECT_CPPOBJECT_H_ */
