#pragma once
#include <SFML/Graphics.hpp>
#include "../core/Handler.hpp"

class Game {
public:
    Game();
    void run();

private:
    Handler handler;
    sf::RenderWindow& renderWindow;

    void processEvents();
    void updateLogic();
    void render();
};