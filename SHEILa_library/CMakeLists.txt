#=SHEILa=======================================================================#
#  Name        : SHEILa_library/CMakeLists.txt                                 #
#  Author      : FlowerGenius<justanortherngirl58@gmail.com>                   #
#  Version     : 0.0.0                                                         #
#  Copyright   :                                                               #
#  Description : cmake configuration file                                      #
#  Module      : SHEILa_library                                                #
#  Created     : Apr 14, 2018                                                  #
#  Modified    :                                                               #
#==============================================================================#
cmake_minimum_required (VERSION 3.11)

set( SHEILa_library_NAME "SHEILa_library" )

set( SHEILa_library_AUTHOR_NAME "FlowerGenius" )

set( SHEILa_library_AUTHOR_MAIL "justanortherngirl58@gmail.com" )

set( SHEILa_library_VERSION 1.0.0 )

set( SHEILa_library_COPYRIGHT "This software is not protected" )

set( SHEILa_library_LANGUAGES CXX )

set( SHEILa_library_DESCRIPTION "A library of the knowledge base of SHEILa" )

set( SHEILa_library_DATE_CREATED "Apr 14, 2018" )

string( TIMESTAMP SHEILa_library_DATE_MODIFIED  "%m %d, %y" )

# Initialize the project with some setup information.
project( ${SHEILa_library_NAME} 
	VERSION     ${SHEILa_library_VERSION} 
	LANGUAGES   ${SHEILa_library_LANGUAGES}
	DESCRIPTION ${SHEILa_library_DESCRIPTION}
)

set( SHEILa_library_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}" )

set( SHEILa_library_BINARY_DIR "${CMAKE_CURRENT_LIST_DIR}/bin/${CMAKE_HOST_SYSTEM_PROCESSOR}" )

message(STATUS "PROJECT_SOURCE_DIR: ${SHEILa_library_DATE_MODIFIED}")

option( REQUIRES_NOARG_CONSTRUCTOR "Set to ON if the library requires that every class have an empty default constructor" ON)

option( CXX_11_EXTENSIONS "Set ON to enable C++11" ON )

option( CXX_14_EXTENSIONS "Set ON to enable C++14 (implies C++11)" ON )

option( CXX_17_EXTENSIONS "Set ON to enable C++17 (implies C++14)" OFF )

option( CXX_20_EXTENSIONS "Set ON to enable C++20 (implies C++17)" OFF )

option( CMAKE_POSITION_INDEPENDENT_CODE "Set ON to activate -fPIC flag" ON )


if(REQUIRES_NOARG_CONSTRUCTOR)
set( REQUIRES_NOARG_CONSTRUCTOR true )
else()
set( REQUIRES_NOARG_CONSTRUCTOR false )
endif()

if(WIN32)

	# Set all of the following options OFF to compile for the version of the 
	# host and/or the latest Microsoft Windows (TM) version.
	
	option( WINDOWS_TARGET_BLUE 
		"Set ON to target Windows 8.1 specifically" OFF )
	
	option( WINDOWS_TARGET_WIN8 
		"Set ON to target Windows 8 specifically" OFF )
	
	option( WINDOWS_TARGET_WIN7 
		"Set ON to target Windows 7 specifically" OFF )
	
	option( WINDOWS_TARGET_WS08 
		"Set ON to target Windows Server 2008 specifically" OFF )
	
	option( WINDOWS_TARGET_VISTASP1 
		"Set ON to target Windows Vista with SP1 specifically" OFF )
	
	option( WINDOWS_TARGET_VISTA 
		"Set ON to target Windows Vista specifically" OFF )
	
	option( WINDOWS_TARGET_WS03SP2 
		"Set ON to target Windows Server 2003 with SP2 specifically" OFF )
	
	option( WINDOWS_TARGET_WS03SP1 
		"Set ON to target Windows Server 2003 with SP1 specifically" OFF )
	
	option( WINDOWS_TARGET_WS03
		"Set ON to target Windows Server 2003 specifically" OFF )
		
	option( WINDOWS_TARGET_WINXPSP3
		"Set ON to target Windows XP with SP3 specifically" OFF )
		
	option( WINDOWS_TARGET_WINXPSP2
		"Set ON to target Windows XP with SP2 specifically" OFF )
		
	option( WINDOWS_TARGET_WINXPSP1
		"Set ON to target Windows XP with SP1 specifically" OFF )
		
	option( WINDOWS_TARGET_WINXP
		"Set ON to target Windows XP specifically" OFF )
	
	if(WINDOWS_TARGET_BLUE)
		set( WINDOWS_WINNT_TARGET_VER WINBLUE )
		set( WINDOWS_NTDDI_TARGET_VER WINBLUE )
	
	elseif(WINDOWS_TARGET_WIN8)
		set( WINDOWS_WINNT_TARGET_VER WIN8 )
		set( WINDOWS_NTDDI_TARGET_VER WIN8 )
	
	elseif(WINDOWS_TARGET_WIN7)
		set( WINDOWS_WINNT_TARGET_VER WIN7 )
		set( WINDOWS_NTDDI_TARGET_VER WIN7 )
	
	elseif(WINDOWS_TARGET_WS08)
		set( WINDOWS_WINNT_TARGET_VER WS08 )
		set( WINDOWS_NTDDI_TARGET_VER WS08 )
	
	elseif(WINDOWS_TARGET_VISTASP1)
		set( WINDOWS_WINNT_TARGET_VER VISTA )
		set( WINDOWS_NTDDI_TARGET_VER VISTASP1 )
	
	elseif(WINDOWS_TARGET_VISTA)
		set( WINDOWS_WINNT_TARGET_VER VISTA )
		set( WINDOWS_NTDDI_TARGET_VER VISTA )
	
	elseif(WINDOWS_TARGET_WS03SP2)
		set( WINDOWS_WINNT_TARGET_VER WS03 )
		set( WINDOWS_NTDDI_TARGET_VER WS03SP2  )
	
	elseif(WINDOWS_TARGET_WS03SP1)
		set( WINDOWS_WINNT_TARGET_VER WS03 )
		set( WINDOWS_NTDDI_TARGET_VER WS03SP1 )
	
	elseif(WINDOWS_TARGET_WS03)
		set( WINDOWS_WINNT_TARGET_VER WS03 )
		set( WINDOWS_NTDDI_TARGET_VER WS03 )
	
	elseif(WINDOWS_TARGET_WINXPSP3)
		set( WINDOWS_WINNT_TARGET_VER WINXP )
		set( WINDOWS_NTDDI_TARGET_VER WINXPSP3 )
	
	elseif(WINDOWS_TARGET_WINXPSP2)
		set( WINDOWS_WINNT_TARGET_VER WINXP )
		set( WINDOWS_NTDDI_TARGET_VER WINXPSP2 )
	
	elseif(WINDOWS_TARGET_WINXPSP1)
		set( WINDOWS_WINNT_TARGET_VER WINXP )
		set( WINDOWS_NTDDI_TARGET_VER WINXPSP1 )
	
	elseif(WINDOWS_TARGET_WINXP)
		set( WINDOWS_WINNT_TARGET_VER WINXP )
		set( WINDOWS_NTDDI_TARGET_VER WINXP )
	
	else()
		set( WINDOWS_WINNT_TARGET_VER WINLATEST )
		set( WINDOWS_NTDDI_TARGET_VER WINLATEST )
	endif()

endif(WIN32)

	set( PROJECT_CXX_STANDARD 97 )

if(CXX_11_EXTENSIONS)
	set( PROJECT_CXX_STANDARD 11 )
endif()

if(CXX_14_EXTENSIONS)
	set( CXX_11_EXTENSIONS ON )
	set( PROJECT_CXX_STANDARD 14 )
endif()

if(CXX_17_EXTENSIONS)
	set( CXX_11_EXTENSIONS ON )
	set( CXX_14_EXTENSIONS ON )
	set( PROJECT_CXX_STANDARD 17 )
endif()

if(CXX_20_EXTENSIONS)
	set( CXX_11_EXTENSIONS ON )
	set( CXX_14_EXTENSIONS ON )
	set( CXX_17_EXTENSIONS ON )
	set( PROJECT_CXX_STANDARD 20 )
endif()

add_library( ${SHEILa_library_NAME} SHARED "${SHEILa_library_SOURCE_DIR}/SHEILa.h" )

target_compile_features( ${SHEILa_library_NAME} PUBLIC cxx_std_${PROJECT_CXX_STANDARD})

set( CppLanguage_NAME "CppLanguage" )
set( CppLanguage_SOURCE_DIR "/home/erin/Documents/SHEILa/CppLanguage" )
set( CppLanguage_BINARY_DIR "${CppLanguage_SOURCE_DIR}/bin/x86_64" )

add_library( ${CppLanguage_NAME} SHARED IMPORTED )

set_target_properties( ${CppLanguage_NAME}
	PROPERTIES 
		IMPORTED_LOCATION "${CppLanguage_BINARY_DIR}/lib${CppLanguage_NAME}.so"
		INTERFACE_INCLUDE_DIRECTORIES  "${CppLanguage_BINARY_DIR};${CppLanguage_SOURCE_DIR}/include"
)

target_include_directories(${SHEILa_library_NAME} PRIVATE "${CppLanguage_BINARY_DIR}")

add_dependencies( ${SHEILa_library_NAME} ${CppLanguage_NAME} )

target_include_directories(${SHEILa_library_NAME} PRIVATE "${SHEILa_library_BINARY_DIR}")

target_include_directories(${SHEILa_library_NAME} PRIVATE "${SHEILa_library_SOURCE_DIR}/../")

target_include_directories(${SHEILa_library_NAME} PRIVATE "${SHEILa_library_SOURCE_DIR}")
target_include_directories(${SHEILa_library_NAME} PUBLIC "${SHEILa_library_BINARY_DIR}")
configure_file( 
	"${CMAKE_CURRENT_LIST_DIR}/config/${SHEILa_library_NAME}Config.h.in"
	"${SHEILa_library_BINARY_DIR}/${SHEILa_library_NAME}Config.h"
)

#if(WIN32)
configure_file(
	"${CMAKE_CURRENT_LIST_DIR}/config/stdafx.h.in"
	"${CMAKE_CURRENT_LIST_DIR}/include/stdafx.h"
)

configure_file(
	"${CMAKE_CURRENT_LIST_DIR}/config/targetver.h.in"
	"${CMAKE_CURRENT_LIST_DIR}/include/targetver.h"
)
#endif(WIN32)

include("${CMAKE_CURRENT_LIST_DIR}/include/CMakeLists.txt")
include("${CMAKE_CURRENT_LIST_DIR}/src/CMakeLists.txt")

target_link_libraries( ${SHEILa_library_NAME} CppLanguage )

