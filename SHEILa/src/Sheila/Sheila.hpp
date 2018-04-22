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
#ifndef SRC_SHEILA_SHEILA_HPP_
#define SRC_SHEILA_SHEILA_HPP_

#include <string>
#include <vector>

namespace sheila {

/** @brief A class representing SHEILa.
 *  @author FlowerGenius
 *
 */
class Sheila {
public:

	Sheila();
	virtual ~Sheila();

private:
	static std::string library_source_file_location;
	static std::string runtime_source_file_location;
	static std::string daemon_source_file_location;

	std::vector<std::string> my_name;

//	std::vector<CppArtifact<Cpp::ArtifactType::EXECUTABLE> > executables;
//	std::vector<CppArtifact<Cpp::ArtifactType::SHARED_LIBRARY> > shared_libs;
//	std::vector<CppArtifact<Cpp::ArtifactType::STATIC_LIBRARY> > static_libs;
//

};

} /* namespace sheila */

#endif /* SRC_SHEILA_SHEILA_HPP_ */
