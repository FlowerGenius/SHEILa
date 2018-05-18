#=SHEILa=======================================================================#
#  Name        : Entity/OperatingSystem
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The OperatingSystem Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling OperatingSystem")

add_library( OperatingSystem OBJECT "" )

target_compile_features( OperatingSystem PUBLIC cxx_std_14)

target_sources( OperatingSystem
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/OperatingSystem.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/OperatingSystem.hpp"
)

add_dependencies( OperatingSystem CppLanguage )

add_dependencies( ${SHEILa_library_NAME} OperatingSystem )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:OperatingSystem> )

target_include_directories( OperatingSystem PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( OperatingSystem PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( OperatingSystem PRIVATE "${CppLanguage_BINARY_DIR}")


