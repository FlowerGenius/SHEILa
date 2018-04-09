# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here
#
cmake_minimum_required(VERSION 3.5)

add_subdirectory("src")

add_library(SHEILa SHARED ${PROJECT_SOURCE_DIR}/src/main.cpp )
