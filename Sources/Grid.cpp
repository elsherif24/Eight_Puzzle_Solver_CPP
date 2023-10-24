//
// Created by Al-Sh on 10/24/2023.
//

#include "../Headers/Grid.h"

namespace EPU {
    Grid::Grid(const std::vector<std::vector<int>>& grid, sf::Font &font) : font(font) {
        steps = grid;
        index = 0;
        squares.resize(9);
        numbers.resize(9);
        fill();
        // Draw the index
        stepIndex.setFont(font);
        stepIndex.setCharacterSize(40);
        stepIndex.setFillColor(sf::Color::Black);
        stepIndex.setPosition(300, 750);
    }

    void Grid::nextStep() {
        // Check if the index is out of bounds
        if (index == steps.size() - 1) {
            return;
        }
        ++index;
        fill();
    }

    void Grid::prevStep() {
        // Check if the index is out of bounds
        if (index == 0) {
            return;
        }
        --index;
        fill();
    }

    void Grid::draw(sf::RenderWindow &window) {
        for (int i = 0; i < 9; ++i) {
            window.draw(squares[i]);
            window.draw(numbers[i]);
        }
        window.draw(stepIndex);
    }

    void Grid::fill() {
        // add padding to the squares
        stepIndex.setString("Step number: " + std::to_string(this->index));

        for (int i = 0; i < 9; ++i) {
            squares[i].setSize(sf::Vector2f(200.f, 200.f));
            squares[i].setOutlineColor(sf::Color::Black);
            squares[i].setOutlineThickness(2.f);
            squares[i].setPosition(200.f * (i % 3) + 120, 200.f * (i / 3) + 120); // Adjust the positions of the squares
            squares[i].setFillColor(sf::Color::White);

            numbers[i].setFont(font);
            numbers[i].setCharacterSize(60); // Increase the character size
            numbers[i].setFillColor(sf::Color::Black);
            if (steps[index][i] != 0) {
                numbers[i].setString(std::to_string(steps[index][i]));
            } else {
                numbers[i].setString("");
            }
            // Center the text in the square
            sf::FloatRect textRect = numbers[i].getLocalBounds();
            numbers[i].setOrigin(textRect.left + textRect.width/2.0f,
                                 textRect.top  + textRect.height/2.0f);
            numbers[i].setPosition(squares[i].getPosition().x + squares[i].getSize().x/2.0f,
                                   squares[i].getPosition().y + squares[i].getSize().y/2.0f);

        }
    }
} // EPU