#=SHEILa=======================================================================#
#  Name        : CMakeLists.txt                                                #
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>                   #
#  Version     : 0.0.0                                                         #
#  Copyright   :                                                               #
#  Description : CMake configuration file                                      #
#  Module      : CppLanguage                                                   #
#  Created     : May  7, 2018                                                  #
#  Modified    :                                                               #
#==============================================================================#
cmake_minimum_required (VERSION 3.5)

project(CppLanguage VERSION 1.0.1 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 14)

add_library(CppLanguage SHARED "")

configure_file (
  "${PROJECT_SOURCE_DIR}/CppLanguageConfig.h.in"
  "${PROJECT_BINARY_DIR}/CppLanguageConfig.h"
)

include(${CMAKE_CURRENT_LIST_DIR}/src/CMakeLists.txt)

set_target_properties(CppLanguage PROPERTIES VERSION ${PROJECT_VERSION})
