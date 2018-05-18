#=SHEILa=======================================================================#
#  Name        : Entity/Number
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The Number Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling Number")

add_library( Number OBJECT "" )

target_compile_features( Number PUBLIC cxx_std_14)

target_sources( Number
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/Number.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/Number.hpp"
)

add_dependencies( Number CppLanguage )

add_dependencies( ${SHEILa_library_NAME} Number )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:Number> )

target_include_directories( Number PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( Number PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( Number PRIVATE "${CppLanguage_BINARY_DIR}")


