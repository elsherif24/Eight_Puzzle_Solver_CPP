//
// Created by Al-Sh on 10/22/2023.
//

#include <map>
#include <queue>
#include <unordered_set>
#include "../Headers/Search.h"

const unsigned int GOAL = 0x76543210;

std::vector<std::vector<int>> treeToSteps(std::unordered_map<unsigned int, unsigned int> &parentMap) {
    std::vector<std::vector<int>> steps;
    unsigned int key{GOAL};
    while (true) {
        if (parentMap.at(key) == key) {
            steps.push_back(stateToGrid(key));
            break;
        }
        steps.push_back(stateToGrid(key));
        key = parentMap.at(key);
    }
    std::reverse(steps.begin(), steps.end());
    return steps;
}

std::vector<std::vector<int>>
treeToSteps(std::unordered_map<unsigned int, std::pair<unsigned int, size_t>> &parentMap) {
    std::vector<std::vector<int>> steps;
    unsigned int key{GOAL};
    while (true) {
        if (parentMap.at(key).first == key) {
            steps.push_back(stateToGrid(key));
            break;
        }
        steps.push_back(stateToGrid(key));
        key = parentMap.at(key).first;
    }
    std::reverse(steps.begin(), steps.end());
    return steps;
}

unsigned int reverseBFS() {

    std::queue<unsigned int> frontier;
    std::unordered_set<unsigned int> explored;
    std::unordered_set<unsigned int> inQueue;

    unsigned int start = GOAL;
    frontier.emplace(start);
    inQueue.insert(start);
    unsigned int curr;
    while (!frontier.empty()) {
        curr = frontier.front();
        frontier.pop();
        explored.insert(curr);

        std::vector<unsigned int> neighbors(getNeighbors(curr));
        for (const unsigned int &neighbor: neighbors) {
            if (!explored.count(neighbor) && !inQueue.count(neighbor)) {
                frontier.emplace(neighbor);
                inQueue.insert(neighbor);
            }
        }
    }

    return curr;
}

