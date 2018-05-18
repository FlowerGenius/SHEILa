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

MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()



SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_LIST_DIR})

FOREACH(subdir ${SUBDIRS})
	set( EOBJ_NAME "${subdir}" )
	set( EOBJ_PATH "Entity/${subdir}" )
	set( EOBJ_AUTHOR_NAME  "FlowerGenius")
	set( EOBJ_AUTHOR_EMAIL "justanortherngirl58@gmail.com")
	
	configure_file ( 
  		"${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt.in"
  		"${CMAKE_CURRENT_LIST_DIR}/${subdir}/CMakeLists.txt"
		@ONLY
	)
	
	include( "${CMAKE_CURRENT_LIST_DIR}/${subdir}/CMakeLists.txt" )
	
	
ENDFOREACH()

add_library( Entity OBJECT "" )

target_include_directories( Entity PUBLIC "/home/erin/Documents/SHEILa")
target_include_directories( Entity PRIVATE "${SHEILa_library_SOURCE_DIR}/include" )
target_include_directories(Entity PUBLIC "${CppLanguage_BINARY_DIR}")
target_include_directories(Entity PUBLIC "${CppLanguage_SOURCE_DIR}")

target_compile_features( Entity PUBLIC cxx_std_14)

target_sources( Entity
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/Entity.cpp"
		"${SHEILa_library_SOURCE_DIR}/include/Entity/Entity.hpp"
)

add_dependencies( Entity CppLanguage )
add_dependencies( ${SHEILa_library_NAME} Entity )

