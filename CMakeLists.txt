cmake_minimum_required(VERSION 3.10)

PROJECT(extPipe)

# verbose makefiles
#SET(CMAKE_VERBOSE_MAKEFILE ON)
# this helps debugging dependencies - a lot :)
#SET_PROPERTY(GLOBAL PROPERTY GLOBAL_DEPENDS_DEBUG_MODE 1)

INCLUDE(CMake/Base.cmake)

ADD_SUBDIRECTORY(Extension)

