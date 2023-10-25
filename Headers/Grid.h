//
// Created by Al-Sh on 10/24/2023.
//

#ifndef EIGHT_PUZZLE_SOLVER_GRID_H
#define EIGHT_PUZZLE_SOLVER_GRID_H

#include "../Headers/AStarEuc.h"
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace EPU {

    class Grid {
    public:
        explicit Grid(const std::vector<std::vector<int>> &grid, sf::Font &font);

        void nextStep();

        void prevStep();

        void draw(sf::RenderWindow &window);

        std::vector<std::vector<int>> steps;

        void fill();

    private:
        int index;
        std::vector<sf::RectangleShape> squares;
        std::vector<sf::Text> numbers;
        sf::Font font;
        sf::Text stepIndex;

    };

} // EPU

#endif //EIGHT_PUZZLE_SOLVER_GRID_H
