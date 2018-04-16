/*SHEILa========================================================================
 * Name        : CppGlobalComponent.h
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 14, 2018
 * Modified    :
 *==============================================================================
 */
#ifndef CPP_CPPGLOBALCOMPONENT_CPPGLOBALCOMPONENT_H_
#define CPP_CPPGLOBALCOMPONENT_CPPGLOBALCOMPONENT_H_

namespace sheila {
namespace cpp {

typedef enum global_components {
	INCLUDE_DIRECTIVE,
	DEFINE_DIRECTIVE
};

class CppGlobalComponent {
public:
	CppGlobalComponent();
	virtual ~CppGlobalComponent();
protected:

};

} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPPGLOBALCOMPONENT_CPPGLOBALCOMPONENT_H_ */
