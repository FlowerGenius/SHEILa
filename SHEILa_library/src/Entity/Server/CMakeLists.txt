#=SHEILa=======================================================================#
#  Name        : Entity/Server
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The Server Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling Server")

add_library( Server OBJECT "" )

target_compile_features( Server PUBLIC cxx_std_14)

target_sources( Server
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/Server.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/Server.hpp"
)

add_dependencies( Server CppLanguage )

add_dependencies( ${SHEILa_library_NAME} Server )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:Server> )

target_include_directories( Server PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( Server PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( Server PRIVATE "${CppLanguage_BINARY_DIR}")


