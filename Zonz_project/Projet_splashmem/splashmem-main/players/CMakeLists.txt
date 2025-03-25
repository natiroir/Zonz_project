#*******************************************************************************
# Authors: Herve Chaminaud
#*******************************************************************************


# add include in src directory
include_directories(${CMAKE_SOURCE_DIR}/src)

# add one lib for each player called playerX.so
add_library(player1 SHARED player1.c)
add_library(player2 SHARED player2.c)
add_library(player3 SHARED player3.c)
add_library(player4 SHARED player4.c)

