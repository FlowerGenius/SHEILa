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
target_sources( CppLanguage
	PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/CppLanguage.h"
)

target_include_directories(CppLanguage PUBLIC "${CMAKE_CURRENT_LIST_DIR}")