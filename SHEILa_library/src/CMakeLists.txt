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
target_sources( ${SHEILa_library_NAME}
	PRIVATE 
		"${CMAKE_CURRENT_LIST_DIR}/main.cpp"		
		"${CMAKE_CURRENT_LIST_DIR}/dllmain.cpp"
)

include("${CMAKE_CURRENT_LIST_DIR}/Entity/CMakeLists.txt")
