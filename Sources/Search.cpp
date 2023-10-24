//
// Created by Al-Sh on 10/22/2023.
//

#include "../Headers/Search.h"

const unsigned int GOAL = 0x76543210;

std::vector<std::vector<int>> treeToSteps(std::unordered_map<unsigned int, unsigned int> &parentMap) {
    std::vector<std::vector<int>> steps;
    unsigned int key{GOAL};
    steps.push_back(stateToGrid(key));
    do {
        key = parentMap.at(key);
        steps.push_back(stateToGrid(key));
    } while (parentMap.at(key) != key);
    std::reverse(steps.begin(), steps.end());
    return steps;
}
std::vector<std::vector<int>> treeToSteps(std::unordered_map<unsigned int, std::pair<unsigned int, size_t>> &parentMap) {
    std::vector<std::vector<int>> steps;
    unsigned int key{GOAL};
    steps.push_back(stateToGrid(key));
    do {
        key = parentMap.at(key).first;
        steps.push_back(stateToGrid(key));
    } while (parentMap.at(key).first != key);
    std::reverse(steps.begin(), steps.end());
    return steps;
}