//
// Created by Al-Sh on 10/25/2023.
//

#ifndef EIGHT_PUZZLE_SOLVER_ALGORITHM_H
#define EIGHT_PUZZLE_SOLVER_ALGORITHM_H
#include <vector>

class Algorithm {
public:
    std::vector<std::vector<int>> path;
    size_t costOfPath;
    size_t nodesExpanded;
    size_t maxDepthSearch;
    size_t runningTime;
    virtual void search() = 0;
    virtual ~Algorithm() = default;
};


#endif //EIGHT_PUZZLE_SOLVER_ALGORITHM_H
