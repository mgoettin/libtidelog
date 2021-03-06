### Basic settings ###
PROJECT(libtidelog)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#set(CMAKE_VERBOSE_MAKEFILE on)

INCLUDE(FindPkgConfig)

# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

### Install Directories ###
SET(PREFIX ${CMAKE_INSTALL_PREFIX})
SET(BINDIR "${PREFIX}/bin")
SET(INCLUDEDIR "${PREFIX}/include/${CMAKE_PROJECT_NAME}")
SET(MANDIR "${PREFIX}/man")
SET(LIBDIR "${PREFIX}/lib")
SET(DATADIR "${PREFIX}/share/${CMAKE_PROJECT_NAME}")
SET(CFGDIR "${PREFIX}/etc/${CMAKE_PROJECT_NAME}")
SET(IW_PLUGINDIR "${PREFIX}/lib/iceWing")

set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_CPP_FLAGS "-D_FILE_OFFSET_BITS=64")

### Some Options (static and editable) ###
#OPTION(IW_DEBUG "En-/disables iceWing debug outputs" OFF)
#IF(IW_DEBUG)
#  ADD_DEFINITIONS(-DIW_DEBUG)
#ENDIF(IW_DEBUG)

#PKG_CHECK_MODULES(OPENCV REQUIRED ${OPENCV_PC})
#IF(OPENCV_FOUND)
#	MESSAGE("using opencv with: ")
#	MESSAGE("     INCLUDE_DIRS:  " ${OPENCV_INCLUDE_DIRS})
#	MESSAGE("     LIBRARIES:     " ${OPENCV_LIBRARIES})
#	MESSAGE("     LIBRARY_DIRS:  " ${OPENCV_LIBRARY_DIRS})
#	MESSAGE("     LDFLAGS:       " ${OPENCV_LDFLAGS})
#	MESSAGE("     LDFLAGS_OTHER: " ${OPENCV_LDFLAGS_OTHER})
#	MESSAGE("     CFLAGS:        " ${OPENCV_CFLAGS})
#	MESSAGE("     CFLAGS_OTHER:  " ${OPENCV_CFLAGS_OTHER})
#ELSE(OPENCV_FOUND)
#       MESSAGE(FATAL_ERROR "opencv not found")
#ENDIF(OPENCV_FOUND)

#SET_SOURCE_FILES_PROPERTIES(
#  GradientDiscretizerPlugin.cpp
#  COMPILE_FLAGS
#  ${FTD_CFLAGS}
#)

add_subdirectory(lib)

include_directories(lib)
link_directories(lib)
add_subdirectory(test)


