cmake_minimum_required (VERSION 3.5)
project(CppLanguage VERSION 1.0.1 LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 11)
add_library(CppLanguage SHARED 
	src/CppLanguage.cpp
)

target_include_directories(CppLanguage PRIVATE include)
target_include_directories(CppLanguage PRIVATE src)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(CppLanguage PROPERTIES VERSION ${PROJECT_VERSION})
