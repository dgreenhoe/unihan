#==============================================================================
# CMake Script file
# Daniel J. Greenhoe
#==============================================================================

#--------------------------------------
# Build Environment Setup
#--------------------------------------
 cmake_minimum_required( VERSION 3.17 )
 set( CMAKE_VERBOSE_MAKEFILE   $<BOOL:true>                )
 set( CMAKE_C_COMPILER_WORKS   $<BOOL:true>                )
 set( CMAKE_CXX_COMPILER_WORKS $<BOOL:true>                )
 set( CMAKE_SYSTEM_NAME        CMAKE_HOST_SYSTEM_NAME      )
 set( CMAKE_SYSTEM_PROCESSOR   CMAKE_HOST_SYSTEM_PROCESSOR )
 set( CMAKE_CROSSCOMPILING     $<BOOL:false>               )
 set( CMAKE_C_STANDARD         99                          )
 set( CMAKE_CXX_STANDARD       11                          )

#--------------------------------------
# Project
#--------------------------------------
 project( var2map
          VERSION     0
          DESCRIPTION "Traditional to Simplified Chinese character converter"
         #HOMEPAGE    https://github.com/dgreenhoe/unihan
          LANGUAGES   C
        )
 set( TARGET ${PROJECT_NAME} )

#--------------------------------------
# Set Directory locations
#--------------------------------------
 set( DIR_GNU C:/CVSSource/Libraries/GNU/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32 )
 set( DIR_BCC C:/CVSSource/Libraries/bcc102 )
 set( DIR_TOOLCHAIN ${DIR_GNU} )
 set( DIR_TOOLCHAIN_INCLUDES  ${DIR_TOOLCHAIN}/include/windows/crtl )
 set( CMAKE_CXX_COMPILER ${DIR_TOOLCHAIN}/bin/g++.exe )

#--------------------------------------
# Set Flags
#--------------------------------------
 set( FLAGS_COMPILE
      #-v
      -Wall
      -Werror
    )

 set( FLAGS_LINK
      #-v
      -Wall
      -Werror
    )

#--------------------------------------
# Source Files
#ERROR using spin_spintoR1(c): c=0(0x30) is not in the valid domain {A,B,C,D,E,F}
#--------------------------------------
 set( SOURCES_TARGET
      var2map.c
    )

#--------------------------------------
# Builds
#--------------------------------------
 add_executable(             ${TARGET}                                                )
 set_target_properties(      ${TARGET} PROPERTIES OUTPUT_NAME ${TARGET} SUFFIX ".exe" )
 target_compile_options(     ${TARGET} PRIVATE    ${FLAGS_COMPILE}                    )
 target_link_options(        ${TARGET} PRIVATE    ${FLAGS_LINK}                       )
 target_sources(             ${TARGET} PRIVATE    ${SOURCES_TARGET}                   )
 target_include_directories( ${TARGET} PRIVATE    ${DIR_TOOLCHAIN_INCLUDES} ..        )
