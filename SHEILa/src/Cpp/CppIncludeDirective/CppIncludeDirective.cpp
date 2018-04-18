/*SHEILa========================================================================
 * Name        : CppIncludeDirective.cpp
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 16, 2018
 * Modified    :
 *==============================================================================
 */
#include "CppIncludeDirective.h"

namespace sheila {
namespace cpp {

CppIncludeDirective::CppIncludeDirective(){
	file = nullptr;
	standard = false;
	active = false;
	name = "undefined";
}

CppIncludeDirective::CppIncludeDirective(std::string path_arg) {
	standard = false;

	file = &CppHeaderFile(path_arg);

	if (!file->validate()) {
		active = false;
	} else {
		active = true;
	}

}

CppIncludeDirective::CppIncludeDirective(std::string path_arg,
		bool active_arg) {
	standard = false;

	file = &CppHeaderFile(path_arg);

	if (!file->validate()) {
		active = false;
	} else {
		active = active_arg;
	}

}

CppIncludeDirective::CppIncludeDirective(CppStandardHeaderFile name) {
	standard = true;

	file = &CppHeaderFile(name);

	if (!file->validate()) {
		active = false;
	} else {
		active = true;
	}
}

CppIncludeDirective::~CppIncludeDirective() {
	// TODO Auto-generated destructor stub
}

} /* namespace cpp */
} /* namespace sheila */
