#=SHEILa=======================================================================#
#  Name        : SHEILa_daemon/src/CMakeLists.txt                              #
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>                   #
#  Version     : 0.0.0                                                         #
#  Copyright   :                                                               #
#  Description : CMake configuration file                                      #
#  Module      : SHEILa_daemon                                                 #
#  Created     : May  7, 2018                                                  #
#  Modified    :                                                               #
#==============================================================================#
target_sources( sheila_srv
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/SHEILa_daemon.cpp"
		"${CMAKE_CURRENT_LIST_DIR}/SHEILa_daemon.hpp"
)

target_include_directories( sheila_srv PRIVATE "${CMAKE_CURRENT_LIST_DIR}" )
