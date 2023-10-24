//
// Created by Al-Sh on 10/22/2023.
//

#include "../Headers/State.h"

const int BIT_SHIFT_MULTIPLIER = 4;
const int ZERO_POSITION_MASK = 0xF;
const std::vector<std::vector<int>> data{{3, 1},
                                         {4, 0, 2},
                                         {5, 1},
                                         {0, 6, 4},
                                         {1, 7, 3, 5},
                                         {2, 8, 4},
                                         {3, 7},
                                         {4, 6, 8},
                                         {5, 7}
};

std::vector<unsigned int> getNeighbors(const unsigned int state) {
    unsigned int zeroPosition = state & ZERO_POSITION_MASK;
    std::vector<unsigned int> neighbors(data[zeroPosition].size());
    for (int i = 0; i < data[zeroPosition].size(); ++i) {
        unsigned int neighbor = state;
        neighbor = (neighbor & ~ZERO_POSITION_MASK) | data[zeroPosition][i];
        for (int j = 1; j < 9; j++) {
            int mask = ZERO_POSITION_MASK << (j * BIT_SHIFT_MULTIPLIER);

            if ((mask & state) == (data[zeroPosition][i] << (j * BIT_SHIFT_MULTIPLIER))) {
                neighbor = (neighbor & ~mask) | (zeroPosition << (BIT_SHIFT_MULTIPLIER * j));
                break;
            }
        }
        neighbors[i] = neighbor;
    }
    return neighbors;
}

unsigned int gridToState(const std::vector<int> &grid) {
    unsigned int state = 0;
    for (int i = 0; i < 9; i++) {
        if (grid[i] != 8) {
            state |= (i << (grid[i] * BIT_SHIFT_MULTIPLIER));
        }
    }
    return state;
}

std::vector<int> stateToGrid(const unsigned int &state) {
    std::vector<int> grid(9, 8);
    for (int i = 0; i < 8; i++) {
        grid[(state >> (i * BIT_SHIFT_MULTIPLIER)) & ZERO_POSITION_MASK] = i;
    }
    return grid;
}