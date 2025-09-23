#pragma once
#include <SFML/Graphics.hpp>

class EventManager {
public:
    EventManager();

    void processEvents(sf::RenderWindow& window);

    bool getUpIsPressed() const;
    bool getDownIsPressed() const;
    bool getLeftIsPressed() const;
    bool getRightIsPressed() const;
private:
    sf::Event event;

    bool upIsPressed = false, downIsPressed = false, leftIsPressed = false, rightIsPressed = false;
};