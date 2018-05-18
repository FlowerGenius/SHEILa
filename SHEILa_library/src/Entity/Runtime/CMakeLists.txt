#=SHEILa=======================================================================#
#  Name        : Entity/Runtime
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The Runtime Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling Runtime")

add_library( Runtime OBJECT "" )

target_compile_features( Runtime PUBLIC cxx_std_14)

target_sources( Runtime
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/Runtime.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/Runtime.hpp"
)

add_dependencies( Runtime CppLanguage )

add_dependencies( ${SHEILa_library_NAME} Runtime )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:Runtime> )

target_include_directories( Runtime PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( Runtime PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( Runtime PRIVATE "${CppLanguage_BINARY_DIR}")


