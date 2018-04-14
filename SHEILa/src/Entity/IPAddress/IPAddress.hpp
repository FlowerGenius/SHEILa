//SHEILa======================================================================
// Name        : IPAddress.hpp
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa_runtime
// Created     : Mar 27, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_IPADDRESS_IPADDRESS_HPP_
#define ENTITY_IPADDRESS_IPADDRESS_HPP_

#include <stdint.h>
#include <string>
#include <sstream>
#include <bitset>

#include "../Entity.hpp"

namespace sheila {

class IPAddress : public Entity {
public:

	static std::vector<IPAddress> ip_addresses;

	IPAddress();
	virtual ~IPAddress();

	//virtual std::string toString();
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

#endif /* ENTITY_IPADDRESS_IPADDRESS_HPP_ */
