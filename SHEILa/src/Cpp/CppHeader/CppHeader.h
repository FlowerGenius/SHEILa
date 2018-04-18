/*SHEILa========================================================================
 * Name        : CppHeader.h
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 17, 2018
 * Modified    :
 *==============================================================================
 */
#ifndef SRC_CPP_CPPHEADER_CPPHEADER_H_
#define SRC_CPP_CPPHEADER_CPPHEADER_H_

#include "../CppFile/CppFile.h"

namespace sheila {
namespace cpp {

/*
 * An abstract model of a header file in C++
 */
class CppHeader : public CppFile {
public:
	CppHeader();
	virtual ~CppHeader();
private:


};

} /* namespace cpp */
} /* namespace sheila */

#endif /* SRC_CPP_CPPHEADER_CPPHEADER_H_ */
