//
// Created by Al-Sh on 10/24/2023.
//

#include "../Headers/AStarMan.h"

AStarMan::AStarMan(const std::vector<int> &grid) {
    costOfPath = 0;
    nodesExpanded = 0;
    maxDepthSearch = 0;
    runningTime = 0;
    start = gridToState(grid);
}

bool AStarMan::aStar() {
    size_t h = heuristic(start);
    size_t g = 0;
    size_t f = g + h;
    size_t depth = 0;

    frontier.push({f, {start, depth}});
    parentMap.insert({start, {start, g}});

    while (!frontier.empty()) {

        unsigned int state = frontier.top().second.first;
        g = parentMap.at(state).second;
        depth = frontier.top().second.second;
        maxDepthSearch = std::max(maxDepthSearch, depth);
        frontier.pop();
        if (explored.count(state)) {
            continue;
        }

        if (state == GOAL) {
            return true;
        }
        explored.insert(state);
        std::vector<unsigned int> neighbors(getNeighbors(state));
        for (const unsigned int &neighbor: neighbors) {
            if (!explored.count(neighbor) && !parentMap.count(neighbor)) {
                h = heuristic(neighbor);
                f = g + 1 + h;
                frontier.push({f, {neighbor, depth + 1}});
                parentMap.insert({neighbor, {state, g + 1}});
            } else if (!explored.count(neighbor)) {
                if (g + 1 < parentMap.at(neighbor).second) {
                    h = heuristic(neighbor);
                    f = g + 1 + h;
                    frontier.push({f, {neighbor, depth + 1}});
                    parentMap.at(neighbor) = {state, g + 1};
                }
            }
        }
    }
    return false;
}

void AStarMan::search() {
    auto startTime = std::chrono::high_resolution_clock::now();
    bool success{aStar()};
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

size_t AStarMan::heuristic(unsigned int state) const {
    // Calculate the manhattan distance
    size_t manhattanDistance = 0;
    unsigned int goal{GOAL};
    int eightPosition = 36;
    for (int i = 0; i < 8; ++i) {

        int cellPosition = static_cast<int>(state & 0xF);
        int goalPosition = static_cast<int>(goal & 0xF);

        state >>= 4;
        goal >>= 4;

        eightPosition -= cellPosition;

        if (i == 0) continue;

        int cellRow = cellPosition / 3;
        int cellColumn = cellPosition % 3;
        int goalRow = goalPosition / 3;
        int goalColumn = goalPosition % 3;

        manhattanDistance += abs(cellRow - goalRow) + abs(cellColumn - goalColumn);
    }
    int cellRow = eightPosition / 3;
    int cellColumn = eightPosition % 3;
    manhattanDistance += abs(cellRow - 2) + abs(cellColumn - 2);
    return manhattanDistance;
}



