#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <minwindef.h>
#include "../Headers/Grid.h"
#include "../Headers/Textbox.h"
#include "../Headers/RectButton.h"
#include "../Headers/Solver.h"


int WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow) {
    std::vector<std::vector<int>> grid({{0, 0, 0, 0, 0, 0, 0, 0, 0}});

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1280, 1024),
                            "SFML window",
                            sf::Style::Titlebar | sf::Style::Close);

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("../Resources/backGround.png"))
        return EXIT_FAILURE;
    // center the sprite
    sf::Sprite sprite(texture);
    sprite.setPosition({0, 0});


    // Create a graphical info to display
    sf::Font font;
    if (!font.loadFromFile("../Resources/arial.ttf"))
        return EXIT_FAILURE;

    window.setKeyRepeatEnabled(true);

    EPU::Grid g(grid, font);

    EPU::Textbox stateInput(40, sf::Color::Black, true);
    stateInput.setPosition({800, 260});
    stateInput.setLimit(true, 10);
    stateInput.setFont(font);

    EPU::RectButton searchButton(font , sf::Vector2f(150.f, 50.f), sf::Vector2f(1000, 350));
    searchButton.setButtonLabel(24.f, "Start Search");
    searchButton.setButtonFont(font);
    searchButton.setButtonColor(sf::Color::White);

    // Write on the screen
    sf::Text info("", font, 30);
    info.setFillColor(sf::Color::Black);
    info.setPosition({780, 440});
    // Start the game loop
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            searchButton.getButtonStatus(window, event);
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
                g.prevStep();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
                g.nextStep();

            if (event.type == sf::Event::TextEntered)
                stateInput.typedOn(event);

            if (searchButton.isPressed) {
                g = EPU::Grid(grid, font);
                run(g.steps, stateInput.getText(), info);
                stateInput.text.clear();
                g.fill();
                break;
            }
        }

        // Clear screen
        window.clear();

        window.draw(sprite);
        window.draw(info);
        g.draw(window);
        stateInput.drawTo(window);
        searchButton.draw(window);

        window.display();
    }

    return EXIT_SUCCESS;
}