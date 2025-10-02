#pragma once
#include <SFML/Graphics.hpp>

class Handler;

class RenderWindowManager {
public:
    RenderWindowManager(Handler& handler);

    sf::RenderWindow& getRenderWindow();
    void setSize(float width, float height);

private:
    Handler& handler;
    sf::RenderWindow renderWindow;
    sf::View view;
};