#=SHEILa=======================================================================#
#  Name        : SHEILa_daemon/CMakeLists.txt                                  #
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>                   #
#  Version     : 0.0.0                                                         #
#  Copyright   :                                                               #
#  Description : cmake configuration file                                      #
#  Module      : SHEILa_daemon                                                 #
#  Created     : Apr 14, 2018                                                  #
#  Modified    :                                                               #
#==============================================================================#
cmake_minimum_required (VERSION 3.11)

project( "SHEILa_daemon" VERSION ${SHEILa_VERSION} LANGUAGES CXX )

# Create a timestamp representing the date of compilation
string( TIMESTAMP TS "%m %d, %y" )
set( MODULE_COMPILE_TIME ${TS} )

set( MODULE_NAME "SHEILa_daemon" )

message(STATUS "${MODULE_NAME}: Now Working On ${MODULE_NAME} at ${TS}")

add_executable(sheila_srv "")

target_compile_features( sheila_srv PUBLIC cxx_std_14)

target_include_directories(sheila_srv PUBLIC "${PROJECT_SOURCE_DIR}/SHEILa_library/src")

target_include_directories(sheila_srv PUBLIC "${PROJECT_SOURCE_DIR}/CppLanguage/include")

add_dependencies( sheila_srv ${SHEILa_library_NAME} )

target_link_libraries( sheila_srv ${SHEILa_library_NAME} )

include("${CMAKE_CURRENT_LIST_DIR}/src/CMakeLists.txt")
