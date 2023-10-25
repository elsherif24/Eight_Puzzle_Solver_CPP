//
// Created by Al-Sh on 10/25/2023.
//

#ifndef EIGHT_PUZZLE_SOLVER_SOLVER_H
#define EIGHT_PUZZLE_SOLVER_SOLVER_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include "../Headers/BFS.h"
#include "../Headers/DFS.h"
#include "../Headers/AStarMan.h"
#include "../Headers/AStarEuc.h"

void run(std::vector<std::vector<int>> &vector1, std::string basicString, sf::Text &info);

bool verifyInput(std::string &input);

#endif //EIGHT_PUZZLE_SOLVER_SOLVER_H
