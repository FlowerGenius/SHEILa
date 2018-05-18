#=SHEILa=======================================================================#
#  Name        : Entity/InstructionSetArchitecture
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>
#  Version     : 1.0.0                                             
#  Copyright   : 
#  Description : CMake Configuration File For The InstructionSetArchitecture Object
#  Module      : 
#  Created     : Apr 14, 2018
#  Modified    : 
#==============================================================================#

message(STATUS "${PROJECT_NAME}: Now Assembling InstructionSetArchitecture")

add_library( InstructionSetArchitecture OBJECT "" )

target_compile_features( InstructionSetArchitecture PUBLIC cxx_std_14)

target_sources( InstructionSetArchitecture
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/InstructionSetArchitecture.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/InstructionSetArchitecture.hpp"
)

add_dependencies( InstructionSetArchitecture CppLanguage )

add_dependencies( ${SHEILa_library_NAME} InstructionSetArchitecture )

target_link_libraries( ${SHEILa_library_NAME} $<TARGET_OBJECTS:InstructionSetArchitecture> )

target_include_directories( InstructionSetArchitecture PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( InstructionSetArchitecture PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories( InstructionSetArchitecture PRIVATE "${CppLanguage_BINARY_DIR}")


