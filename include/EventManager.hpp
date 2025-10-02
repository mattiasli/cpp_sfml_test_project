#pragma once
#include <SFML/Graphics.hpp>

class Handler;

class EventManager {
public:
    EventManager(Handler& handler);

    void processEvents();

    bool getUpIsPressed() const;
    bool getDownIsPressed() const;
    bool getLeftIsPressed() const;
    bool getRightIsPressed() const;
private:
    Handler& handler;
    sf::RenderWindow& renderWindow;
    sf::Event event;

    bool upIsPressed = false, downIsPressed = false, leftIsPressed = false, rightIsPressed = false;
};