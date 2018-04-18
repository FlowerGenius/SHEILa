/*SHEILa========================================================================
 * Name        : CppSource.h
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 17, 2018
 * Modified    :
 *==============================================================================
 */
#ifndef SRC_CPP_CPPSOURCE_CPPSOURCE_H_
#define SRC_CPP_CPPSOURCE_CPPSOURCE_H_

#include "../CppFile/CppFile.h"

namespace sheila {
namespace cpp {

class CppSource : public CppFile {
public:
	CppSource();
	virtual ~CppSource();
private:
	/*
	 * Variable definitions
	 */
	std::vector<CppVariable> 	 contained_variables;

	/*
	 * Object definitions
	 */
	std::vector<CppClassObject>  contained_objects;

};

} /* namespace cpp */
} /* namespace sheila */

#endif /* SRC_CPP_CPPSOURCE_CPPSOURCE_H_ */
