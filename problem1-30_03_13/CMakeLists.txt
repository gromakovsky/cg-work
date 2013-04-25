cmake_minimum_required(VERSION 2.8)
project(problem1)

find_package(GMP REQUIRED)
include_directories(${GMP_INCLUDE_DIR})

set(SOURCES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${GMP_LIBRARIES})
