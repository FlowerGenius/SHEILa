#=SHEILa=======================================================================#
#  Name        : Entity/SHEILaCoreServer
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The SHEILaCoreServer Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling SHEILaCoreServer")

add_library( SHEILaCoreServer OBJECT "" )

target_compile_features( SHEILaCoreServer PUBLIC cxx_std_14)

target_sources( SHEILaCoreServer
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/SHEILaCoreServer.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/SHEILaCoreServer.hpp"
)

add_dependencies( SHEILaCoreServer CppLanguage )

add_dependencies( ${SHEILa_library_NAME} SHEILaCoreServer )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:SHEILaCoreServer> )

target_include_directories( SHEILaCoreServer PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( SHEILaCoreServer PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( SHEILaCoreServer PRIVATE "${CppLanguage_BINARY_DIR}")


