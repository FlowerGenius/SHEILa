/*SHEILa========================================================================
 * Name        : Number.h
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 21, 2018
 * Modified    :
 *==============================================================================
 */
#ifndef SRC_ENTITY_NUMBER_NUMBER_HPP_
#define SRC_ENTITY_NUMBER_NUMBER_HPP_

#include "../Entity.hpp"

namespace sheila {

class Number : public Entity<Number>{
public:
	Number();
	virtual ~Number();
};

} /* namespace sheila */

#endif /* SRC_ENTITY_NUMBER_NUMBER_HPP_ */
