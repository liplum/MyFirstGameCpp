cmake_minimum_required(VERSION 3.24)
project(MyFirstGameCpp)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.2  # Specify the desired version or commit hash
)
FetchContent_MakeAvailable(nlohmann_json)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.3.2 # or a later release
)

add_executable(
        MyFirstGameCpp
        src/entity.h src/entity.cpp
        src/calculate.h src/calculate.cpp
        src/console.h src/console.cpp
        src/game.h src/game.cpp
        src/ui.h src/ui.cpp
        src/Battle.h src/Battle.cpp
        src/main.cpp
        src/level/level_1.cpp
)

target_link_libraries(MyFirstGameCpp PRIVATE nlohmann_json::nlohmann_json)
