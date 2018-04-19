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

	const static std::string T(ArtifactType t) {
		switch(t){
		case ArtifactType::EXECUTABLE:
			return "executable";
		case ArtifactType::STATIC_LIBRARY:
			return "static library";
		case ArtifactType::SHARED_LIBRARY:
			return "shared library";
		default:
			return T(ArtifactType::EXECUTABLE);
		}
	}

	CppArtifact() {
		this->name = T(_Ta);
	}
	virtual ~CppArtifact() {
		;
	}

	const std::string& getName() const {
		return this->name;
	}
private:

	std::string name;

	std::vector<CppObject<void>* > 		           cpp_objects;
	std::vector<CppArtifact<ArtifactType::STATIC_LIBRARY>* > static_libs;
	std::vector<CppArtifact<ArtifactType::SHARED_LIBRARY>* > shared_libs;
};

typedef CppArtifact<ArtifactType::EXECUTABLE> CppExecutable;
typedef CppArtifact<ArtifactType::STATIC_LIBRARY> CppStaticLib;
typedef CppArtifact<ArtifactType::SHARED_LIBRARY> CppSharedLib;


} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPPARTIFACT_CPPARTIFACT_H_ */
