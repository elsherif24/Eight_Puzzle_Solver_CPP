//
// Created by Al-Sh on 10/24/2023.
//

#ifndef EIGHT_PUZZLE_SOLVER_ASTAREUC_H
#define EIGHT_PUZZLE_SOLVER_ASTAREUC_H

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

class AStarEuc : public Algorithm {
public:
    void search();

    explicit AStarEuc(const std::vector<int> &grid);

    double heuristic(unsigned int state) const;

private:
    unsigned int start;
    const unsigned int GOAL{0x76543210};
    std::unordered_set<unsigned int> explored;
    std::unordered_map<unsigned int, std::pair<unsigned int, size_t>> parentMap;
    std::priority_queue<std::pair<double, std::pair<unsigned int, size_t>>, std::vector<std::pair<double, std::pair<unsigned int, size_t>>>, std::greater<>> frontier;

    bool aStar();

    static double euclideanDistance(std::pair<int, int> a, std::pair<int, int> b);
};


#endif //EIGHT_PUZZLE_SOLVER_ASTAREUC_H
