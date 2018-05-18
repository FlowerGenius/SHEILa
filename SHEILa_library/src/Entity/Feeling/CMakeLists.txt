#=SHEILa=======================================================================#
#  Name        : Entity/Feeling
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The Feeling Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling Feeling")

add_library( Feeling OBJECT "" )

target_compile_features( Feeling PUBLIC cxx_std_14)

target_sources( Feeling
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/Feeling.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/Feeling.hpp"
)

add_dependencies( Feeling CppLanguage )

add_dependencies( ${SHEILa_library_NAME} Feeling )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:Feeling> )

target_include_directories( Feeling PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( Feeling PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( Feeling PRIVATE "${CppLanguage_BINARY_DIR}")


