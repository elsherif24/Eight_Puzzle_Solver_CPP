cmake_minimum_required(VERSION 3.26)
project(Eight_Puzzle_Solver)

set(CMAKE_CXX_STANDARD 17)

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
)
