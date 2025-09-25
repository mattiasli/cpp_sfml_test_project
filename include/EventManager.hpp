#pragma once
#include <SFML/Graphics.hpp>

class EventManager {
public:
    EventManager(sf::RenderWindow& renderWindow);

    void processEvents();

    bool getUpIsPressed() const;
    bool getDownIsPressed() const;
    bool getLeftIsPressed() const;
    bool getRightIsPressed() const;
private:
    sf::RenderWindow& renderWindow;
    sf::Event event;

    bool upIsPressed = false, downIsPressed = false, leftIsPressed = false, rightIsPressed = false;
};