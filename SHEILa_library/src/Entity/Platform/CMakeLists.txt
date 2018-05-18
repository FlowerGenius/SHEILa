#=SHEILa=======================================================================#
#  Name        : Entity/Platform
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The Platform Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling Platform")

add_library( Platform OBJECT "" )

target_compile_features( Platform PUBLIC cxx_std_14)

target_sources( Platform
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/Platform.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/Platform.hpp"
)

add_dependencies( Platform CppLanguage )

add_dependencies( ${SHEILa_library_NAME} Platform )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:Platform> )

target_include_directories( Platform PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( Platform PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( Platform PRIVATE "${CppLanguage_BINARY_DIR}")


