#=SHEILa=======================================================================#
#  Name        : Entity/Vendor
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The Vendor Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling Vendor")

add_library( Vendor OBJECT "" )

target_compile_features( Vendor PUBLIC cxx_std_14)

target_sources( Vendor
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/Vendor.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/Vendor.hpp"
)

add_dependencies( Vendor CppLanguage )

add_dependencies( ${SHEILa_library_NAME} Vendor )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:Vendor> )

target_include_directories( Vendor PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( Vendor PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( Vendor PRIVATE "${CppLanguage_BINARY_DIR}")


