# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here
#
cmake_minimum_required(VERSION 3.11)

set( SHEILa_NAME "SHEILa" )

set( SHEILa_AUTHOR_NAME "FlowerGenius" )

set( SHEILa_AUTHOR_MAIL "justanortherngirl58@gmail.com" )

set( SHEILa_VERSION 1.0.0 )

set( SHEILa_COPYRIGHT "This software is not protected" )

set( SHEILa_LANGUAGES CXX )

set( SHEILa_DESCRIPTION "The workspace project for the AI SHEILa" )

set( SHEILa_DATE_CREATED "Apr 14, 2018" )

string( TIMESTAMP SHEILa_DATE_MODIFIED  "%m %d, %y" )

# Initialize the project with some setup information.
project( ${SHEILa_NAME} 
	VERSION     ${SHEILa_VERSION} 
	LANGUAGES   ${SHEILa_LANGUAGES}
	DESCRIPTION ${SHEILa_DESCRIPTION}
)

set( SHEILa_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}" )

set( SHEILa_BINARY_DIR "${CMAKE_CURRENT_LIST_DIR}/bin/${CMAKE_HOST_SYSTEM_PROCESSOR}" )

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

set( SHEILa_CXX_STANDARD ${PROJECT_CXX_STANDARD} )


include(${PROJECT_SOURCE_DIR}/../CppLanguage/CMakeLists.txt)
include(${PROJECT_SOURCE_DIR}/../SHEILa_library/CMakeLists.txt)
include(${PROJECT_SOURCE_DIR}/../SHEILa_daemon/CMakeLists.txt)
include(${PROJECT_SOURCE_DIR}/../SHEILa_runtime/CMakeLists.txt)
