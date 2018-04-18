/*SHEILa========================================================================
 * Name        : CppObjdefFile.h
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 17, 2018
 * Modified    :
 *==============================================================================
 */
#ifndef SRC_CPP_CPPOBJDEFFILE_CPPOBJDEFFILE_H_
#define SRC_CPP_CPPOBJDEFFILE_CPPOBJDEFFILE_H_

#include <string>
#include <vector>

#include "../../ProgrammingLanguage/XML/XmlFile/XmlFile.h"

namespace sheila {
namespace cpp {

class CppObjdefFile : public xml::XmlFile {
public:
	CppObjdefFile();


	virtual ~CppObjdefFile();
};

} /* namespace cpp */
} /* namespace sheila */

#endif /* SRC_CPP_CPPOBJDEFFILE_CPPOBJDEFFILE_H_ */
