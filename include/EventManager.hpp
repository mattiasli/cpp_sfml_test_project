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

    sf::Vector2i GetMousePosition() const;
    bool GetIsMouseLeftButtonPressed() const;
    bool GetIsMouseLeftButtonDown() const;
    bool GetIsMouseLeftButtonReleased() const;
    bool GetIsMouseRightButtonPressed() const;
    bool GetIsMouseRightButtonDown() const;
    bool GetIsMouseRightButtonReleased() const;

private:
    Handler& handler;
    sf::RenderWindow& renderWindow;
    sf::Event event;

    bool upIsPressed = false, downIsPressed = false, leftIsPressed = false, rightIsPressed = false;

    sf::Vector2i mousePosition = {0, 0};
    bool isMouseLeftButtonPressed = false, isMouseLeftButtonDown = false, isMouseLeftButtonReleased = false;
    bool isMouseRightButtonPressed = false, isMouseRightButtonDown = false, isMouseRightButtonReleased = false;

    void resetInputState();
};