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

/** @brief Abstract model of a C++ compilation artifact.
 *  @author FlowerGenius
 *  @tparam _Ta The type of artifact to specialize as.
 *
 *  This class represents a C++ artifact. An artifact can be a:
 *
 *  @arg @a EXECUTABLE A binary that is meant to be run on it's target platform.
 *  @arg @a STATIC_LIBRARY An archive that that defines features to be included
 *                         in some other program or library.
 *  @arg @a SHARED_LIBRARY A binary that contains features to be referenced in
 *                         some other program or library.
 *
 *  No other types of artifacts are supported by the C++ language. For detailed
 *  descriptions of each type of artifact, see the definition for the
 *  respective specializations.
 *
 *  All types of artifact are comprised of linked @c CppObject elements and
 *  other @c CppArtifact elements given that they are library types. This is
 *  modeled by having each artifact instance contain a vector of pointers to
 *  the objects and libraries to be linked.
 *
 */
template<Cpp::ArtifactType _Ta>
class CppArtifact {
public:

	/** @brief Translation function for getting the name of an artifact.
	 *  @author FlowerGenius
	 *  @param t The type of artifact to get the name of.
	 *  @return C++ string containing the name of artifact @a t.
	 *
	 *  This function returns the name of the type of artifact @a t.
	 *
	 */
	const static std::string T(Cpp::ArtifactType t) {
		switch(t){
		case Cpp::ArtifactType::EXECUTABLE:
			return "executable";
		case Cpp::ArtifactType::STATIC_LIBRARY:
			return "static library";
		case Cpp::ArtifactType::SHARED_LIBRARY:
			return "shared library";
		default:
			return T(Cpp::ArtifactType::EXECUTABLE);
		}
	}

	/** @brief Template constructor for a C++ artifact.
	 *  @author FlowerGenius
	 *
	 *  This constructor creates an instance of @c CppArtifact< @a _Ta > where
	 *  @a _Ta is the type of artifact being generated. It also sets @a name to
	 *  the name returned by the @a T function.
	 *
	 */
	CppArtifact() { this->artifact_type_name = T(_Ta); }

	/** @brief Template destructor for a C++ artifact.
	 *  @author FlowerGenius
	 *
	 *  This destructor destroys the instance of @c CppArtifact that this
	 *  object represents.
	 *
	 */
	virtual ~CppArtifact() {}

	/** @brief Get the type name of this artifact.
	 *  @author FlowerGenius
	 *  @return A C++ string containing the name of the @c ArtifactType
	 */
	const std::string& getName() const { return this->artifact_type_name; }

private:

	/** @brief The name of the type of artifact that this instance represents */
	std::string artifact_type_name;

	/** @brief The vector of pointers to linked C++ objects */
	std::vector<CppObject<void>* > 		           cpp_objects;

	/** @brief The vector of pointers to linked C++ static libraries */
	std::vector<CppArtifact<Cpp::ArtifactType::STATIC_LIBRARY>* > static_libs;

	/** @brief The vector of pointers to linked C++ shared libraries */
	std::vector<CppArtifact<Cpp::ArtifactType::SHARED_LIBRARY>* > shared_libs;
};

/** @brief A type definition of @c CppExecutable for sanity and convenience.
 *  @author FlowerGenius
 *
 *  An executable artifact in C++ is a binary that is meant to be run on the
 *  target(s) it is compiled for.
 *
 *  Sometimes referred to as a @e runtime or a @e program. These artifacts
 *  generally carry a @e .exe file extension in the case of DOS/Windows systems
 *  and either @e .o , @e .bin , or no extension in Unix systems.
 *
 */
typedef CppArtifact<Cpp::ArtifactType::EXECUTABLE> CppExecutable;

/** @brief A type definition of @c CppStaticLib for sanity and convenience.
 *  @author FlowerGenius
 *
 *  A static library artifact in C++ is an archive that is meant to be linked
 *  into other programs or libraries.
 *
 *  A library that is linked into a program statically has all of it's contents
 *  copied into the resulting artifact binary or archive, thus static libraries
 *  are not recommended for large libraries; however having static linkage
 *  means that the library does not have to be shipped with the binary or
 *  archive it is linked from.
 *
 *  A static library typically carries a @e .lib file extension in the case
 *  of DOS/Windows systems and a @e .a extension in Unix systems.
 *
 */
typedef CppArtifact<Cpp::ArtifactType::STATIC_LIBRARY> CppStaticLib;

/** @brief A type definition of @c CppSharedLib for sanity and convenience.
 *  @author FlowerGenius
 *
 *  A shared library artifact in C++ is a binary that is meant to be linked
 *  into other programs or libraries. Similarly to the static library.
 *
 *  A library that is linked into a program with shared linkage has none
 *  of it's contents drawn into the resulting binary or archive; rather, the
 *  archive or library provides references to the features included in the
 *  shared library.
 *
 *  A shared library typically carries a @e .dll extension in the case of
 *  DOS/Windows systems and a @e .so extension in Unix systems.
 *
 */
typedef CppArtifact<Cpp::ArtifactType::SHARED_LIBRARY> CppSharedLib;


} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPPARTIFACT_CPPARTIFACT_H_ */
