#=SHEILa=======================================================================#
#  Name        : Entity/Network
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The Network Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling Network")

add_library( Network OBJECT "" )

target_compile_features( Network PUBLIC cxx_std_14)

target_sources( Network
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/Network.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/Network.hpp"
)

add_dependencies( Network CppLanguage )

add_dependencies( ${SHEILa_library_NAME} Network )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:Network> )

target_include_directories( Network PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( Network PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( Network PRIVATE "${CppLanguage_BINARY_DIR}")


