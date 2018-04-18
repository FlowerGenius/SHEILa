/*SHEILa========================================================================
 * Name        : CppIncludeDirective.h
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 16, 2018
 * Modified    :
 *==============================================================================
 */
#ifndef SRC_CPP_CPPINCLUDEDIRECTIVE_CPPINCLUDEDIRECTIVE_H_
#define SRC_CPP_CPPINCLUDEDIRECTIVE_CPPINCLUDEDIRECTIVE_H_

#include <string>

#include "../Cpp.h"
#include "../CppHeaderFile/CppHeaderFile.h"

namespace sheila {
namespace cpp {

class CppIncludeDirective {
public:

	/* Parses an include directive and returns an object of it */
	static CppIncludeDirective parse(std::string);

	CppIncludeDirective();
	CppIncludeDirective(std::string path_arg);
	CppIncludeDirective(std::string path_arg, bool active_arg);
	CppIncludeDirective(CppStandardHeaderFile name);

	std::string cpp_print();

	virtual ~CppIncludeDirective();
protected:
	bool active; /* True if the directive is not commented out */
	bool standard;
	std::string name;
	CppHeaderFile*	file;
};

} /* namespace cpp */
} /* namespace sheila */

#endif /* SRC_CPP_CPPINCLUDEDIRECTIVE_CPPINCLUDEDIRECTIVE_H_ */
