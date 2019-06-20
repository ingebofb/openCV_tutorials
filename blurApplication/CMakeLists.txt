cmake_minimum_required(VERSION 2.8)
project( BlurImage )

find_package( OpenCV )
include_directories( ${OpenCV_INCLUDE_DIRS} )
set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )
add_executable( BlurImage BlurImage.cpp )
target_link_libraries( BlurImage ${OpenCV_LIBS} )