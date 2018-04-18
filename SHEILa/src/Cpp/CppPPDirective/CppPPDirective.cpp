/*SHEILa========================================================================
 * Name        : CppPPDirective.cpp
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 17, 2018
 * Modified    :
 *==============================================================================
 */
#include "CppPPDirective.h"

namespace sheila {
namespace cpp {

template<CppPPDirectiveType _Td>
CppPPDirective<_Td>::CppPPDirective(std::vector<std::string> allocator = {}) {
	this->parameters(allocator);
}

template<CppPPDirectiveType _Td>
std::string CppPPDirective<_Td>::cpp_str() {
	std::string tmp = " ";
	for (auto const& value: this->parameters) {
		tmp.append(value + " ");
	}
	return "#" + _Td + tmp;
}

template<CppPPDirectiveType _Td>
std::string CppPPDirective<_Td>::xml_str() {
	std::string tmp = "[";
	for (auto const& value: this->parameters) {
		tmp.append(value + ",");
	}
	if (this->parameters.size() > 0) {
		tmp.replace(tmp.rfind(','),1,1,']');
	} else {
		tmp.append("]");
	}
	return "<directive type='" + _Td + "' parameters='" + tmp + "' />";
}


template<CppPPDirectiveType _Td>
CppPPDirective<_Td>::~CppPPDirective() {
	// TODO Auto-generated destructor stub
}

} /* namespace cpp */
} /* namespace sheila */
