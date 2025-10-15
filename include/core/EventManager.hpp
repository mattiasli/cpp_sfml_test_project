#pragma once
#include <SFML/Graphics.hpp>

class Handler;

class EventManager {
public:
    EventManager(Handler& handler);

    void processEvents();

    bool getIsKeyboardUpKeyDown() const;
    bool getIsKeyboardDownKeyDown() const;
    bool getIsKeyboardLeftKeyDown() const;
    bool getIsKeyboardRightKeyDown() const;

    sf::Vector2i getMousePosition() const;
    bool getIsMouseLeftButtonPressed() const;
    bool getIsMouseLeftButtonDown() const;
    bool getIsMouseLeftButtonReleased() const;
    bool getIsMouseRightButtonPressed() const;
    bool getIsMouseRightButtonDown() const;
    bool getIsMouseRightButtonReleased() const;

private:
    Handler& handler;
    sf::RenderWindow& renderWindow;
    sf::Event event;

    bool isKeyboardUpKeyDown = false, isKeyboardDownKeyDown = false, isKeyboardLeftKeyDown = false, isKeyboardRightKeyDown = false;

    sf::Vector2i mousePosition = {0, 0};
    bool isMouseLeftButtonPressed = false, isMouseLeftButtonDown = false, isMouseLeftButtonReleased = false;
    bool isMouseRightButtonPressed = false, isMouseRightButtonDown = false, isMouseRightButtonReleased = false;

    void resetInputState();
};