#=SHEILa=======================================================================#
#  Name        : Entity/UnknownEntity
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The UnknownEntity Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling UnknownEntity")

add_library( UnknownEntity OBJECT "" )

target_compile_features( UnknownEntity PUBLIC cxx_std_14)

target_sources( UnknownEntity
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/UnknownEntity.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/UnknownEntity.hpp"
)

add_dependencies( UnknownEntity CppLanguage )

add_dependencies( ${SHEILa_library_NAME} UnknownEntity )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:UnknownEntity> )

target_include_directories( UnknownEntity PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( UnknownEntity PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( UnknownEntity PRIVATE "${CppLanguage_BINARY_DIR}")


