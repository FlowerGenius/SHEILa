#=SHEILa=======================================================================#
#  Name        : Entity/Processor
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The Processor Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling Processor")

add_library( Processor OBJECT "" )

target_compile_features( Processor PUBLIC cxx_std_14)

target_sources( Processor
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/Processor.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/Processor.hpp"
)

add_dependencies( Processor CppLanguage )

add_dependencies( ${SHEILa_library_NAME} Processor )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:Processor> )

target_include_directories( Processor PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( Processor PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( Processor PRIVATE "${CppLanguage_BINARY_DIR}")


