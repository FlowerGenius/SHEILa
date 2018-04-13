//SHEILa======================================================================
// Name        : IPv4.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 31, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_IPV4_IPV4_H_
#define ENTITY_IPV4_IPV4_H_

#include "../IPAddress/IPAddress.h"

namespace sheila {

/* Internet Protocol address using a 32-bit address */
class IPv4 : public IPAddress {
public:
	IPv4();
	IPv4(uint32_t address);
	IPv4(std::string address);
	IPv4(const char* address);
	IPv4(uint8_t a,uint8_t b,uint8_t c,uint8_t d);


	virtual ~IPv4();

	uint32_t getAddress();

	std::string toString();

protected:

	uint8_t a;
	uint8_t b;
	uint8_t c;
	uint8_t d;

private:

	static std::time_t							_time_created_;
	static std::time_t							_time_accessed_;
	static std::time_t							_time_modified_;
	static std::vector<long double>				_emotion_values_;
	static std::vector<std::string> 			_name_;
	static std::vector<std::string> 			_desc_;
	static std::vector<std::string>				_cv_filters_;
	static std::vector<Entity> 					_parents_;
	static std::vector<Entity> 					_children_;
	static std::vector<cpp::CppMemberFunction> 	_member_functions_;
	static std::vector<cpp::CppDataMember> 		_data_members_;


};

} /* namespace sheila */

#endif /* ENTITY_IPV4_IPV4_H_ */
