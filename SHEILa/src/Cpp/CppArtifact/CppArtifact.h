/*SHEILa========================================================================
 * Name        : CppArtifact.h
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 14, 2018
 * Modified    :
 *==============================================================================
 */
#ifndef CPP_CPPARTIFACT_CPPARTIFACT_H_
#define CPP_CPPARTIFACT_CPPARTIFACT_H_

#include <string>
#include <vector>

#include "../CppObject/CppObject.h"


namespace sheila {
namespace cpp {

enum class ArtifactType {
	EXECUTABLE,
	STATIC_LIBRARY,
	SHARED_LIBRARY
};

/*
 * Abstract model of a Cpp Artifact
 */
template<cpp::ArtifactType _Ta>
class CppArtifact {
public:
	CppArtifact();
	virtual ~CppArtifact();
private:
//	std::vector<CObject* > 	c_objects;
	std::vector<CppObject* > 		           cpp_objects;
	std::vector<CppArtifact<ArtifactType::STATIC_LIBRARY>* > static_libs;
	std::vector<CppArtifact<ArtifactType::SHARED_LIBRARY>* > shared_libs;
};


} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPPARTIFACT_CPPARTIFACT_H_ */
