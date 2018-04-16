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

#include "../CppSourceFile/CppSourceFile.h"
#include "../CppHeaderFile/CppHeaderFile.h"

namespace sheila {
namespace cpp {

typedef enum cpp_artifact_types {
	EXECUTABLE,
	STATIC_LIBRARY,
	SHARED_LIBRARY
} ArtifactType;

struct CppArtifact_base {
public:

	virtual ~CppArtifact_base(){
		;
	}

protected:



};

struct CppArtifact_library : public CppArtifact_base {
public:

	virtual ~CppArtifact_library(){
		;
	}

	virtual bool	isShared();

protected:
	bool	shared;
};

template<cpp::ArtifactType _Type = EXECUTABLE>
class CppArtifact : public CppArtifact_base {
public:
	CppArtifact();
	virtual ~CppArtifact();
};

template<>
class CppArtifact<STATIC_LIBRARY> : public CppArtifact_library {
public:
	CppArtifact() {
		shared = false;
	}

	virtual ~CppArtifact() {
		;
	}

protected:

};

template<>
class CppArtifact<SHARED_LIBRARY> : public CppArtifact_library {
public:
	CppArtifact()  {
		shared = true;
	}
	virtual ~CppArtifact() {
		;
	}

protected:
};

} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPPARTIFACT_CPPARTIFACT_H_ */
