//
// Created by Al-Sh on 10/24/2023.
//

#ifndef EIGHT_PUZZLE_SOLVER_TEXTBOX_H
#define EIGHT_PUZZLE_SOLVER_TEXTBOX_H

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>


namespace EPU {

    // Define keys:
    class Textbox {
    public:
        Textbox(int size, sf::Color color, bool sel);

        // Make sure font is passed by reference:
        void setFont(sf::Font &fonts) {
            textbox.setFont(fonts);
        }

        void setPosition(sf::Vector2f point) {
            textbox.setPosition(point);
        }

        // Set char limits:
        void setLimit(bool ToF) {
            hasLimit = ToF;
        }

        void setLimit(bool ToF, int lim) {
            hasLimit = ToF;
            limit = lim - 1;
        }

        // Change selected state:
        void setSelected(bool sel);

        std::string getText() {
            return text.str();
        }

        void drawTo(sf::RenderWindow &window) {
            window.draw(textbox);
        }

        // Function for event loop:
        void typedOn(sf::Event input);

        std::ostringstream text;
    private:
        sf::Text textbox;

        bool isSelected = false;
        bool hasLimit = false;
        int limit = 0;

        // Delete the last character of the text:
        void deleteLastChar();

        // Get user input:
        void inputLogic(int charTyped);

        const char DELETE_KEY{8};
        const char ENTER_KEY{13};
        const char ESCAPE_KEY{27};
    };

} // EPU

#endif //EIGHT_PUZZLE_SOLVER_TEXTBOX_H
