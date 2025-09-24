#pragma once
#include <SFML/Graphics.hpp>
#include "../include/EventManager.hpp"
#include "../include/Constants.hpp"

class Game {
public:
    Game();
    void run();

private:
    sf::RenderWindow window;
    EventManager eventManager;

    float x_pos = 50, y_pos = 50;

    void processEvents();
    void updateLogic();
    void render();
};