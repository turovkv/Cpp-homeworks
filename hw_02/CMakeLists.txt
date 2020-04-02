cmake_minimum_required(VERSION 3.10)
project(hw_02)

set(CMAKE_CXX_STANDARD 17)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

include_directories("include")
add_executable(
        hw_02
        main.cpp
        src/Board.cpp
        include/Board.hpp
        src/StdioBoardView.cpp
        include/StdioBoardView.hpp
        src/GameController.cpp
        include/GameController.hpp
        src/BoardView.cpp
        include/BoardView.hpp
        src/NcursesBoardView.cpp
        include/NcursesBoardView.hpp)

add_executable(
        test_hw_02
        src/Board.cpp
        include/Board.hpp
        test/Test.cpp
        include/Test.hpp
        test/BoardTest.cpp
        include/BoardTest.hpp)

target_link_libraries(hw_02 ncurses)