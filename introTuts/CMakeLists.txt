cmake_minimum_required(VERSION 2.8)
project( loadAndDisplay )

find_package( OpenCV )
include_directories( ${OpenCV_INCLUDE_DIRS} )
set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )

add_executable( loadAndDisplay loadAndDisplay.cpp )
target_link_libraries( loadAndDisplay ${OpenCV_LIBS} )