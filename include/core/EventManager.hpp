#pragma once
#include <SFML/Graphics.hpp>

class Handler;

class EventManager {
public:
    EventManager(Handler& handler);

    void processEvents();

    bool getIsKeyboardUpKeyPressed() const;
    bool getIsKeyboardDownKeyPressed() const;
    bool getIsKeyboardLeftKeyPressed() const;
    bool getIsKeyboardRightKeyPressed() const;
    bool getIsKeyboardUpKeyDown() const;
    bool getIsKeyboardDownKeyDown() const;
    bool getIsKeyboardLeftKeyDown() const;
    bool getIsKeyboardRightKeyDown() const;
    bool getIsKeyboardUpKeyReleased() const;
    bool getIsKeyboardDownKeyReleased() const;
    bool getIsKeyboardLeftKeyReleased() const;
    bool getIsKeyboardRightKeyReleased() const;

    bool getIsKeyboardZKeyPressed() const;
    bool getIsKeyboardZKeyDown() const;
    bool getIsKeyboardZKeyReleased() const;

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

    bool isKeyboardUpKeyPressed = false, isKeyboardUpKeyDown = false, isKeyboardUpKeyReleased = false;
    bool isKeyboardDownKeyPressed = false, isKeyboardDownKeyDown = false, isKeyboardDownKeyReleased = false;
    bool isKeyboardLeftKeyPressed = false, isKeyboardLeftKeyDown = false, isKeyboardLeftKeyReleased = false;
    bool isKeyboardRightKeyPressed = false, isKeyboardRightKeyDown = false, isKeyboardRightKeyReleased = false;

    bool isKeyboardZKeyPressed = false, isKeyboardZKeyDown = false, isKeyboardZKeyReleased = false;

    sf::Vector2i mousePosition = {0, 0};
    bool isMouseLeftButtonPressed = false, isMouseLeftButtonDown = false, isMouseLeftButtonReleased = false;
    bool isMouseRightButtonPressed = false, isMouseRightButtonDown = false, isMouseRightButtonReleased = false;

    void resetInputState();
};