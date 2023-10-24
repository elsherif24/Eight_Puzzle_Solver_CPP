//
// Created by Al-Sh on 10/22/2023.
//

#ifndef EIGHT_PUZZLE_SOLVER_STATE_H
#define EIGHT_PUZZLE_SOLVER_STATE_H

#include <vector>
#include <algorithm>

std::vector<unsigned int> getNeighbors(unsigned int state);

unsigned int gridToState(const std::vector<int> &grid);

std::vector<int> stateToGrid(const unsigned int &state);


#endif //EIGHT_PUZZLE_SOLVER_STATE_H
