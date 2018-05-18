#=SHEILa=======================================================================#
#  Name        : Entity/ProgrammingLanguage
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The ProgrammingLanguage Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling ProgrammingLanguage")

add_library( ProgrammingLanguage OBJECT "" )

target_compile_features( ProgrammingLanguage PUBLIC cxx_std_14)

target_sources( ProgrammingLanguage
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/ProgrammingLanguage.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/ProgrammingLanguage.hpp"
)

add_dependencies( ProgrammingLanguage CppLanguage )

add_dependencies( ${SHEILa_library_NAME} ProgrammingLanguage )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:ProgrammingLanguage> )

target_include_directories( ProgrammingLanguage PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( ProgrammingLanguage PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( ProgrammingLanguage PRIVATE "${CppLanguage_BINARY_DIR}")


