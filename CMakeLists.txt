cmake_minimum_required(VERSION 3.24)
project(MyFirstGameCpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyFirstGameCpp src/entity.cpp src/calculate.cpp src/console.cpp src/game.h src/game.cpp src/ui.cpp src/ui.h src/level/level_1.cpp src/main.cpp src/Battle.cpp src/Battle.h)
