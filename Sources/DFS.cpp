//
// Created by Al-Sh on 10/24/2023.
//

#include "../Headers/DFS.h"

DFS::DFS(const std::vector<int> &grid) {
    costOfPath = 0;
    nodesExpanded = 0;
    maxDepthSearch = 0;
    runningTime = 0;
    start = gridToState(grid);
}

bool DFS::dfs() {
    frontier.emplace(start, 0);
    parentMap.insert({start, start});

    while (!frontier.empty()) {
        unsigned int state = frontier.top().first;
        size_t depth = frontier.top().second;
        maxDepthSearch = std::max(maxDepthSearch, depth);
        frontier.pop();

        if (state == GOAL) {
            return true;
        }
        explored.insert(state);
        std::vector<unsigned int> neighbors(getNeighbors(state));
        for (const unsigned int &neighbor: neighbors) {
            if (!explored.count(neighbor) && !parentMap.count(neighbor)) {
                frontier.emplace(neighbor, depth + 1);
                parentMap.insert({neighbor, state});
            }
        }
    }
    return false;
}

void DFS::search() {

    auto startTime = std::chrono::high_resolution_clock::now();
    bool success{dfs()};
    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime);
    runningTime = duration.count();
    nodesExpanded = explored.size();

    if (!success) {
        throw std::invalid_argument("No solution exist for this state.\n");
    }
    path = treeToSteps(parentMap);
    costOfPath = path.size() - 1;
}


