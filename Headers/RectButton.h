//
// Created by Al-Sh on 10/25/2023.
//

#ifndef EIGHT_PUZZLE_SOLVER_RECTBUTTON_H
#define EIGHT_PUZZLE_SOLVER_RECTBUTTON_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"

namespace EPU {

    class RectButton: public Button {
    public:

        RectButton(sf::Font& font, sf::Vector2f size, sf::Vector2f position);

        ~RectButton();

        void getButtonStatus(sf::RenderWindow& window, sf::Event& event) override;
        void draw(sf::RenderWindow& window) override;
        void setButtonLabel(float charSize, std::string label) override;
        void setButtonLabel(float charSize) override;

        sf::RectangleShape button;

        //end of public

    private:

        sf::FloatRect buttonRect;

        //end of private
    };


} // EPU

#endif //EIGHT_PUZZLE_SOLVER_RECTBUTTON_H
