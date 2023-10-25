cmake_minimum_required(VERSION 3.26)
project(Eight_Puzzle_Solver)

set(CMAKE_CXX_STANDARD 17)
include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FetchContent_MakeAvailable(SFML)

enable_testing()
add_subdirectory(googletest)
add_subdirectory(test)
add_executable(Eight_Puzzle_Solver "Sources/main.cpp"
        "Sources/State.cpp"
        "Headers/State.h"
        "Sources/Search.cpp"
        "Headers/Search.h"
        "Sources/BFS.cpp"
        "Headers/BFS.h"
        Sources/DFS.cpp
        Headers/DFS.h
        Sources/AStarMan.cpp
        Headers/AStarMan.h
        Sources/AStarEuc.cpp
        Headers/AStarEuc.h
        Sources/Grid.cpp
        Headers/Grid.h
        Sources/Textbox.cpp
        Headers/Textbox.h
        Sources/Button.cpp
        Headers/Button.h
        Sources/RectButton.cpp
        Headers/RectButton.h
        Sources/Solver.cpp
        Headers/Solver.h
        Headers/Algorithm.h
)

target_link_libraries(Eight_Puzzle_Solver sfml-graphics sfml-window sfml-system)