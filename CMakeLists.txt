cmake_minimum_required(VERSION 3.21)
project(Minesweeper)

set(CMAKE_CXX_STANDARD 14)

add_executable(Minesweeper src/main.cpp src/Board.cpp src/Board.hpp src/Cell.cpp src/Cell.hpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/envs/cpp/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/envs/cpp/SFML-2.5.1/include)
target_link_libraries(Minesweeper sfml-system sfml-window sfml-graphics sfml-audio)
