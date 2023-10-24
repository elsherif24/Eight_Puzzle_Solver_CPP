//
// Created by Al-Sh on 10/24/2023.
//

#include "../Headers/Textbox.h"

namespace EPU {

    void Textbox::inputLogic(int charTyped) {
        // If the key pressed isn't delete, or the two selection keys, then append the text with the char:
        if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
            text << static_cast<char>(charTyped);
        }
            // If the key is deleted, then delete the char:
        else if (charTyped == DELETE_KEY) {
            if (text.str().length() > 0) {
                deleteLastChar();
            }
        }
        // Set the textbox text:
        textbox.setString(text.str() + "_");
    }

    void Textbox::deleteLastChar() {

        std::string t = text.str();
        std::string newT;
        for (int i = 0; i < t.length() - 1; i++) {
            newT += t[i];
        }
        text.str("");
        text << newT;
        textbox.setString(text.str() + "_");
    }

    Textbox::Textbox(int size, sf::Color color, bool sel) {
        textbox.setCharacterSize(size);
        textbox.setColor(color);
        isSelected = sel;

        // Check if the textbox is selected upon creation and display it accordingly:
        if (isSelected)
            textbox.setString("_");
        else
            textbox.setString("");
    }

    void Textbox::setSelected(bool sel) {
        isSelected = sel;

        // If not selected, remove the '_' at the end:
        if (!sel) {
            std::string t = text.str();
            std::string newT;
            for (char i: t) {
                newT += i;
            }
            textbox.setString(newT);
        }
    }

    void Textbox::typedOn(sf::Event input) {
        if (isSelected) {
            int charTyped = input.text.unicode;

            // Only allow normal inputs:
            if (charTyped < 128) {
                if (hasLimit) {
                    // If there's a limit, don't go over it:
                    if (text.str().length() <= limit) {
                        inputLogic(charTyped);
                    }
                        // But allow for char deletions:
                    else if (text.str().length() > limit && charTyped == DELETE_KEY) {
                        deleteLastChar();
                    }
                }
                    // If no limit exists, just run the function:
                else {
                    inputLogic(charTyped);
                }
            }
        }
    }


} // EPU