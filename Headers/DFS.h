//
// Created by Al-Sh on 10/24/2023.
//

#ifndef EIGHT_PUZZLE_SOLVER_DFS_H
#define EIGHT_PUZZLE_SOLVER_DFS_H

#include <vector>
#include <stack>
#include <utility>
#include <stdexcept>
#include <unordered_set>
#include <unordered_map>
#include <chrono>
#include <algorithm>
#include "../Headers/State.h"
#include "../Headers/Search.h"

class DFS {
public:
    std::vector<std::vector<int>> path;
    size_t costOfPath;
    size_t nodesExpanded;
    size_t maxDepthSearch;
    size_t runningTime;
    void search();
    explicit DFS(const std::vector<int>& grid);

private:
    unsigned int start;
    const unsigned int GOAL{0x76543210};
    std::unordered_set<unsigned int> explored;
    std::unordered_map<unsigned int, unsigned int> parentMap;
    std::stack<std::pair<unsigned int, size_t>> frontier;
    bool dfs();
};


#endif //EIGHT_PUZZLE_SOLVER_DFS_H
