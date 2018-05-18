#=SHEILa=======================================================================#
#  Name        : Entity/Version
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The Version Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling Version")

add_library( Version OBJECT "" )

target_compile_features( Version PUBLIC cxx_std_14)

target_sources( Version
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/Version.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/Version.hpp"
)

add_dependencies( Version CppLanguage )

add_dependencies( ${SHEILa_library_NAME} Version )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:Version> )

target_include_directories( Version PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( Version PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( Version PRIVATE "${CppLanguage_BINARY_DIR}")


