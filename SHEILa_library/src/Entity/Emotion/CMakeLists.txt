#=SHEILa=======================================================================#
#  Name        : Entity/Emotion
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The Emotion Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling Emotion")

add_library( Emotion OBJECT "" )

target_compile_features( Emotion PUBLIC cxx_std_14)

target_sources( Emotion
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/Emotion.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/Emotion.hpp"
)

add_dependencies( Emotion CppLanguage )

add_dependencies( ${SHEILa_library_NAME} Emotion )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:Emotion> )

target_include_directories( Emotion PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( Emotion PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( Emotion PRIVATE "${CppLanguage_BINARY_DIR}")


