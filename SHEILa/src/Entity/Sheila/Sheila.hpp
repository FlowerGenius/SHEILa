/*SHEILa========================================================================
 * Name        : Sheila.hpp
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 16, 2018
 * Modified    :
 *==============================================================================
 */
#ifndef SRC_ENTITY_SHEILA_SHEILA_HPP_
#define SRC_ENTITY_SHEILA_SHEILA_HPP_

#include <string>
#include "../UnknownEntity/UnknownEntity.hpp"

namespace sheila {

class Sheila {
public:

	Sheila();
	virtual ~Sheila();

private:
	static std::string library_source_file_location;
	static std::string runtime_source_file_location;
	static std::string daemon_source_file_location;

	static int buildEntity(UnknownEntity e) {
		return 0;
	}

};

} /* namespace sheila */

#endif /* SRC_ENTITY_SHEILA_SHEILA_HPP_ */
