//
// Created by Al-Sh on 10/22/2023.
//

#ifndef EIGHT_PUZZLE_SOLVER_SEARCH_H
#define EIGHT_PUZZLE_SOLVER_SEARCH_H

#include <unordered_map>
#include <vector>
#include <algorithm>
#include "../Headers/State.h"
std::vector<std::vector<int>> treeToSteps(std::unordered_map<unsigned int, unsigned int> &parentMap);
std::vector<std::vector<int>> treeToSteps(std::unordered_map<unsigned int, std::pair<unsigned int, size_t>> &parentMap);
#endif //EIGHT_PUZZLE_SOLVER_SEARCH_H
