#=SHEILa=======================================================================#
#  Name        : SHEILa_runtime/CMakeLists.txt                                 #
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>                   #
#  Version     : 0.0.0                                                         #
#  Copyright   :                                                               #
#  Description : CMake configuration file                                      #
#  Module      : SHEILa_runtime                                                #
#  Created     : May  7, 2018                                                  #
#  Modified    :                                                               #
#==============================================================================#
cmake_minimum_required(VERSION 3.11)

set( SHEILa_runtime_NAME "SHEILa_runtime" )

set( SHEILa_runtime_AUTHOR_NAME "FlowerGenius" )

set( SHEILa_runtime_AUTHOR_MAIL "justanortherngirl58@gmail.com" )

set( SHEILa_runtime_VERSION 1.0.0 )

set( SHEILa_runtime_COPYRIGHT "This software is not protected" )

set( SHEILa_runtime_LANGUAGES CXX )

set( SHEILa_runtime_DESCRIPTION "The workspace project for the AI SHEILa" )

set( SHEILa_runtime_DATE_CREATED "Apr 14, 2018" )

string( TIMESTAMP SHEILa_runtime_DATE_MODIFIED  "%m %d, %y" )

# Initialize the project with some setup information.
project( ${SHEILa_runtime_NAME} 
	VERSION     ${SHEILa_runtime_VERSION} 
	LANGUAGES   ${SHEILa_runtime_LANGUAGES}
	DESCRIPTION ${SHEILa_runtime_DESCRIPTION}
)

set( SHEILa_runtime_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}" )

set( SHEILa_runtime_BINARY_DIR "${CMAKE_CURRENT_LIST_DIR}/bin/${CMAKE_HOST_SYSTEM_PROCESSOR}" )

add_executable(${SHEILa_runtime_NAME} "")

target_compile_features( ${SHEILa_runtime_NAME} PUBLIC cxx_std_14)

target_include_directories(${SHEILa_runtime_NAME} PUBLIC "/home/erin/Documents/SHEILa")

set( CppLanguage_NAME "CppLanguage" )
set( CppLanguage_SOURCE_DIR "/home/erin/Documents/SHEILa/CppLanguage" )
set( CppLanguage_BINARY_DIR "${CppLanguage_SOURCE_DIR}/bin/x86_64" )

target_include_directories(${SHEILa_runtime_NAME} PRIVATE "${CppLanguage_BINARY_DIR}")

add_library( ${CppLanguage_NAME} SHARED IMPORTED )

set_target_properties( ${CppLanguage_NAME}
	PROPERTIES 
		IMPORTED_LOCATION "${CppLanguage_BINARY_DIR}/lib${CppLanguage_NAME}.so"
		INTERFACE_INCLUDE_DIRECTORIES  "${CppLanguage_BINARY_DIR};${CppLanguage_SOURCE_DIR}/include"
)

add_dependencies( ${SHEILa_runtime_NAME} ${CppLanguage_NAME} )

set( SHEILa_library_NAME "SHEILa_library" )
set( SHEILa_library_SOURCE_DIR "/home/erin/Documents/SHEILa/SHEILa_library" )
set( SHEILa_library_BINARY_DIR "${SHEILa_library_SOURCE_DIR}/bin/x86_64" )

add_library( ${SHEILa_library_NAME} SHARED IMPORTED )

set_target_properties( ${SHEILa_library_NAME}
	PROPERTIES 
		IMPORTED_LOCATION "${SHEILa_library_BINARY_DIR}/lib${SHEILa_library_NAME}.so"
		INTERFACE_INCLUDE_DIRECTORIES "${SHEILa_library_BINARY_DIR};${SHEILa_library_SOURCE_DIR}/include"
)

#add_dependencies( ${SHEILa_library_NAME} ${CppLanguage_NAME} )
add_dependencies( ${SHEILa_runtime_NAME} ${SHEILa_library_NAME} )

include("${CMAKE_CURRENT_LIST_DIR}/include/CMakeLists.txt")
include("${CMAKE_CURRENT_LIST_DIR}/src/CMakeLists.txt")

target_link_libraries( ${SHEILa_runtime_NAME} ${CppLanguage_NAME} )
target_link_libraries( ${SHEILa_runtime_NAME} ${SHEILa_library_NAME} )


