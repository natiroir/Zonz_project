
#*******************************************************************************
# Authors: Herve Chaminaud
#*******************************************************************************


cmake_minimum_required(VERSION 3.10)
project(splashmem VERSION 1.0)

# set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")


add_subdirectory(src)
add_subdirectory(players)
