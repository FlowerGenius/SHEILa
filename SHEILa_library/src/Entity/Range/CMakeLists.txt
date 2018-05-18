#=SHEILa=======================================================================#
#  Name        : Entity/Range
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The Range Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling Range")

add_library( Range OBJECT "" )

target_compile_features( Range PUBLIC cxx_std_14)

target_sources( Range
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/Range.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/Range.hpp"
)

add_dependencies( Range CppLanguage )

add_dependencies( ${SHEILa_library_NAME} Range )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:Range> )

target_include_directories( Range PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( Range PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( Range PRIVATE "${CppLanguage_BINARY_DIR}")


