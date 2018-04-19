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


struct CppObject_base {
	CppObject_base(){
		;
	}
	virtual ~CppObject_base(){
		;
	}
};

/*
 * A compilation object in C++, it points to one source file and a series of
 * header files. This model also contains specific metadata for a strictly
 * formatted file header.
 *
 */
template<class _N>
class CppObject : private CppObject_base {


public:

	/* Creates a new abstract model of a C++ object
	 *
	 */
	CppObject() {
		;
	}

	/* Builds a new abstract model of a C++ object from an XML file
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
