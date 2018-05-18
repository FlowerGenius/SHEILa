#=SHEILa=======================================================================#
#  Name        : Entity/Language
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The Language Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling Language")

add_library( Language OBJECT "" )

target_compile_features( Language PUBLIC cxx_std_14)

target_sources( Language
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/Language.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/Language.hpp"
)

add_dependencies( Language CppLanguage )

add_dependencies( ${SHEILa_library_NAME} Language )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:Language> )

target_include_directories( Language PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( Language PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( Language PRIVATE "${CppLanguage_BINARY_DIR}")


