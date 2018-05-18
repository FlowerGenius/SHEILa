#=SHEILa=======================================================================#
#  Name        : Entity/Schema
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The Schema Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling Schema")

add_library( Schema OBJECT "" )

target_compile_features( Schema PUBLIC cxx_std_14)

target_sources( Schema
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/Schema.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/Schema.hpp"
)

add_dependencies( Schema CppLanguage )

add_dependencies( ${SHEILa_library_NAME} Schema )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:Schema> )

target_include_directories( Schema PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( Schema PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( Schema PRIVATE "${CppLanguage_BINARY_DIR}")


