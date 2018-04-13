//SHEILa======================================================================
// Name        : IPv6.h
// Author      : erin
// Version     : 
// Copyright   : 
// Description : 
// Module	   : SHEILa
// Created     : Mar 31, 2018
// Modified    :
//============================================================================

#ifndef ENTITY_IPV6_IPV6_H_
#define ENTITY_IPV6_IPV6_H_

#include "../IPAddress/IPAddress.h"

namespace sheila {

/* Internet Protocol address using a 128-bit address */
class IPv6 :  public IPAddress {
public:
	IPv6();
	virtual ~IPv6();



	std::string toString();
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

#endif /* ENTITY_IPV6_IPV6_H_ */
