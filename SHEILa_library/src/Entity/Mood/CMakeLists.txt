#=SHEILa=======================================================================#
#  Name        : Entity/Mood
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The Mood Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling Mood")

add_library( Mood OBJECT "" )

target_compile_features( Mood PUBLIC cxx_std_14)

target_sources( Mood
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/Mood.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/Mood.hpp"
)

add_dependencies( Mood CppLanguage )

add_dependencies( ${SHEILa_library_NAME} Mood )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:Mood> )

target_include_directories( Mood PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( Mood PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( Mood PRIVATE "${CppLanguage_BINARY_DIR}")


