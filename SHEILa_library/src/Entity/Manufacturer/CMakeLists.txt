#=SHEILa=======================================================================#
#  Name        : Entity/Manufacturer
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The Manufacturer Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling Manufacturer")

add_library( Manufacturer OBJECT "" )

target_compile_features( Manufacturer PUBLIC cxx_std_14)

target_sources( Manufacturer
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/Manufacturer.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/Manufacturer.hpp"
)

add_dependencies( Manufacturer CppLanguage )

add_dependencies( ${SHEILa_library_NAME} Manufacturer )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:Manufacturer> )

target_include_directories( Manufacturer PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( Manufacturer PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( Manufacturer PRIVATE "${CppLanguage_BINARY_DIR}")


