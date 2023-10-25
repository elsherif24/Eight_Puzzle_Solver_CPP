//
// Created by Al-Sh on 10/24/2023.
//

#ifndef EIGHT_PUZZLE_SOLVER_BFS_H
#define EIGHT_PUZZLE_SOLVER_BFS_H

#include <vector>
#include <queue>
#include <utility>
#include <stdexcept>
#include <unordered_set>
#include <unordered_map>
#include <chrono>
#include <algorithm>
#include "../Headers/State.h"
#include "../Headers/Search.h"
#include "Algorithm.h"

class BFS : public Algorithm {
public:
    void search();
    explicit BFS(const std::vector<int>& grid);
private:
    unsigned int start;
    const unsigned int GOAL{0x76543210};
    std::unordered_set<unsigned int> explored;
    std::unordered_map<unsigned int, unsigned int> parentMap;
    std::queue<std::pair<unsigned int, size_t>> frontier;
    bool bfs();
};


#endif //EIGHT_PUZZLE_SOLVER_BFS_H
