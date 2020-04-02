cmake_minimum_required(VERSION 3.10)
project(lab_13)

set(CMAKE_CXX_STANDARD 17)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(lab_13
                src/main.cpp
                include/my_array.h)