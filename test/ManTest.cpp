//
// Created by Al-Sh on 10/24/2023.
//
#include <gtest/gtest.h>
#include <vector>
#include "../Headers/AStarMan.h"
#include "../Headers/State.h"
#include "../Headers/Search.h"
#include "../Sources/AStarMan.cpp"
#include "../Sources/State.cpp"
#include "../Sources/Search.cpp"

TEST(ManhattanDistance, test0) {
    std::vector<int> grid({0, 1, 2, 3, 4, 5, 6, 7, 8});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 0);
}

TEST(ManhattanDistance, test1) {
    std::vector<int> grid({4, 2, 8, 5, 1, 0, 6, 3, 7});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 11);
}

TEST(ManhattanDistance, test2) {
    std::vector<int> grid({7, 3, 1, 2, 5, 0, 8, 4, 6});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 15);
}

TEST(ManhattanDistance, test3) {
    std::vector<int> grid({5, 1, 8, 0, 7, 4, 2, 3, 6});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 15);
}

TEST(ManhattanDistance, test4) {
    std::vector<int> grid({6, 1, 5, 2, 0, 8, 7, 4, 3});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 12);
}

TEST(ManhattanDistance, test5) {
    std::vector<int> grid({6, 0, 4, 1, 7, 5, 3, 2, 8});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 11);
}

TEST(ManhattanDistance, test6) {
    std::vector<int> grid({1, 5, 3, 8, 4, 6, 7, 0, 2});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 15);
}

TEST(ManhattanDistance, test7) {
    std::vector<int> grid({7, 8, 3, 6, 1, 5, 4, 0, 2});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 15);
}

TEST(ManhattanDistance, test8) {
    std::vector<int> grid({7, 2, 0, 3, 1, 4, 6, 8, 5});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 8);
}

TEST(ManhattanDistance, test9) {
    std::vector<int> grid({3, 2, 7, 0, 5, 1, 4, 8, 6});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 13);
}

TEST(ManhattanDistance, test10) {
    std::vector<int> grid({1, 3, 4, 8, 2, 7, 0, 5, 6});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 16);
}

TEST(ManhattanDistance, test11) {
    std::vector<int> grid({2, 8, 5, 1, 0, 3, 7, 4, 6});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 14);
}

TEST(ManhattanDistance, test12) {
    std::vector<int> grid({1, 0, 6, 8, 5, 4, 3, 7, 2});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 13);
}

TEST(ManhattanDistance, test13) {
    std::vector<int> grid({6, 1, 7, 0, 8, 3, 5, 2, 4});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 17);
}

TEST(ManhattanDistance, test14) {
    std::vector<int> grid({8, 1, 7, 0, 3, 4, 6, 2, 5});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 13);
}

TEST(ManhattanDistance, test15) {
    std::vector<int> grid({5, 7, 6, 3, 0, 1, 2, 8, 4});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 18);
}

TEST(ManhattanDistance, test16) {
    std::vector<int> grid({5, 8, 1, 2, 4, 7, 6, 3, 0});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 14);
}

TEST(ManhattanDistance, test17) {
    std::vector<int> grid({2, 1, 8, 5, 7, 3, 4, 0, 6});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 13);
}

TEST(ManhattanDistance, test18) {
    std::vector<int> grid({6, 8, 3, 1, 2, 7, 4, 5, 0});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 18);
}

TEST(ManhattanDistance, test19) {
    std::vector<int> grid({1, 6, 2, 4, 0, 8, 5, 7, 3});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 12);
}

TEST(ManhattanDistance, test20) {
    std::vector<int> grid({5, 8, 4, 1, 7, 0, 3, 6, 2});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 15);
}

TEST(ManhattanDistance, test21) {
    std::vector<int> grid({1, 2, 6, 8, 4, 5, 3, 0, 7});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 11);
}

TEST(ManhattanDistance, test22) {
    std::vector<int> grid({3, 4, 2, 7, 6, 0, 8, 5, 1});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 13);
}

TEST(ManhattanDistance, test23) {
    std::vector<int> grid({1, 3, 8, 2, 7, 5, 0, 6, 4});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 12);
}

TEST(ManhattanDistance, test24) {
    std::vector<int> grid({7, 4, 5, 8, 0, 3, 2, 6, 1});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 18);
}

TEST(ManhattanDistance, test25) {
    std::vector<int> grid({6, 4, 0, 8, 2, 3, 1, 5, 7});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 16);
}

TEST(ManhattanDistance, test26) {
    std::vector<int> grid({4, 6, 5, 2, 7, 8, 0, 3, 1});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 16);
}

TEST(ManhattanDistance, test27) {
    std::vector<int> grid({7, 6, 8, 0, 3, 1, 4, 2, 5});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 17);
}

TEST(ManhattanDistance, test28) {
    std::vector<int> grid({4, 8, 3, 6, 2, 7, 0, 1, 5});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 16);
}

TEST(ManhattanDistance, test29) {
    std::vector<int> grid({3, 6, 1, 2, 7, 8, 0, 5, 4});
    AStarMan x = AStarMan(grid);
    unsigned int state = gridToState(grid);
    size_t v = x.heuristic(state);
    ASSERT_EQ(v, 14);
}



