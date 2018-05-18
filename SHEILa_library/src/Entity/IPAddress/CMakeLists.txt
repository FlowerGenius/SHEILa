#=SHEILa=======================================================================#
#  Name        : Entity/IPAddress
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The IPAddress Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling IPAddress")

add_library( IPAddress OBJECT "" )

target_compile_features( IPAddress PUBLIC cxx_std_14)

target_sources( IPAddress
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/IPAddress.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/IPAddress.hpp"
)

add_dependencies( IPAddress CppLanguage )

add_dependencies( ${SHEILa_library_NAME} IPAddress )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:IPAddress> )

target_include_directories( IPAddress PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( IPAddress PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( IPAddress PRIVATE "${CppLanguage_BINARY_DIR}")


