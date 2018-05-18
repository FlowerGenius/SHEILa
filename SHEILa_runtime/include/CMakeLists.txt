#=SHEILa=======================================================================#
#  Name        : SHEILa_runtime/src/CMakeLists.txt                             #
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>                   #
#  Version     : 0.0.0                                                         #
#  Copyright   :                                                               #
#  Description : CMake configuration file                                      #
#  Module      : SHEILa_runtime                                                #
#  Created     : May  7, 2018                                                  #
#  Modified    :                                                               #
#==============================================================================#
target_sources( ${SHEILa_runtime_NAME} 
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/headers.h"
)

target_include_directories( ${SHEILa_runtime_NAME} PRIVATE "${CMAKE_CURRENT_LIST_DIR}")