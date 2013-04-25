cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(cg-work)

SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cg/CMake/Modules)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

find_package(GMP REQUIRED)

find_package(Boost REQUIRED)

include_directories(cg/include ${Boost_INCLUDE_DIR} ${GMP_INCLUDE_DIR})

add_subdirectory(cg)
add_subdirectory(problem1-30_03_13)

