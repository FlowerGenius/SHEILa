#=SHEILa=======================================================================#
#  Name        : CMakeLists.txt                                                #
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>                   #
#  Version     : 0.0.0                                                         #
#  Copyright   :                                                               #
#  Description : cmake configuration file                                      #
#  Module      : SHEILa                                                        #
#  Created     : Apr 14, 2018                                                  #
#  Modified    :                                                               #
#==============================================================================#
cmake_minimum_required(VERSION 3.5)

#project(SHEILalib VERSION 0.0.0 LANGUAGES CXX)

add_subdirectory(
	"Entity" 
)

add_library(SHEILalib SHARED
	main.cpp
)