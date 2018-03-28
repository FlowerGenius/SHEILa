//SHEILa======================================================================
// Name        : Processor.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 28, 2018
// Modified    :
//============================================================================

#ifndef PROCESSOR_PROCESSOR_H_
#define PROCESSOR_PROCESSOR_H_

#include <string>

namespace sheila {
namespace processor {

class Processor {
public:
	Processor();
	virtual ~Processor();
private:

	std::string architecture;
	std::string byte_order;


};


} /* namespace processor */
} /* namespace sheila */

#endif /* PROCESSOR_PROCESSOR_H_ */
