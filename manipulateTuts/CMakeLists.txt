cmake_minimum_required(VERSION 2.8)
project(changeImage)

find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(changeImage changeImage.cpp)
target_link_libraries(changeImage ${OpenCV_LIBS})