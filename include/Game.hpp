#pragma once
#include <SFML/Graphics.hpp>
#include "../include/Constants.hpp"
#include "../include/Handler.hpp"

class Game {
public:
    Game();
    void run();

private:
    sf::RenderWindow renderWindow;
    Handler handler;

    float x_pos = 50, y_pos = 50;

    void processEvents();
    void updateLogic();
    void render();
};