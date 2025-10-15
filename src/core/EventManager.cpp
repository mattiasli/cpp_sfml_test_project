#include "../../include/core/EventManager.hpp"
#include "../../include/core/Handler.hpp"

EventManager::EventManager(Handler& handler)
: handler(handler),
renderWindow(handler.getRenderWindowManager().getRenderWindow())
{
}

void EventManager::processEvents()
{
    resetInputState();
    while (renderWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
        renderWindow.close();
        break;

        case sf::Event::Resized:
        handler.getRenderWindowManager().setSize(event.size.width, event.size.height);
        break;

        case sf::Event::KeyPressed:
            switch (event.key.code)
            {
                case sf::Keyboard::Up:
                case sf::Keyboard::W:
                isKeyboardUpKeyDown = true;
                break;

                case sf::Keyboard::Down:
                case sf::Keyboard::S:
                isKeyboardDownKeyDown = true;
                break;

                case sf::Keyboard::Left:
                case sf::Keyboard::A:
                isKeyboardLeftKeyDown = true;
                break;

                case sf::Keyboard::Right:
                case sf::Keyboard::D:
                isKeyboardRightKeyDown = true;
                break;

                default:
                break;
            }
        break;

        case sf::Event::KeyReleased:
            switch (event.key.code)
            {
                case sf::Keyboard::Up:
                case sf::Keyboard::W:
                isKeyboardUpKeyDown = false;
                break;

                case sf::Keyboard::Down:
                case sf::Keyboard::S:
                isKeyboardDownKeyDown = false;
                break;

                case sf::Keyboard::Left:
                case sf::Keyboard::A:
                isKeyboardLeftKeyDown = false;
                break;

                case sf::Keyboard::Right:
                case sf::Keyboard::D:
                isKeyboardRightKeyDown = false;
                break;

                default:
                break;
            }
        break;

        case sf::Event::MouseButtonPressed:
            switch (event.mouseButton.button)
            {
                case sf::Mouse::Left:
                isMouseLeftButtonPressed = true;
                isMouseLeftButtonDown = true;
                break;

                case sf::Mouse::Right:
                isMouseRightButtonPressed = true;
                isMouseRightButtonDown = true;
                break;

                default:
                break;
            }
        break;

        case sf::Event::MouseButtonReleased:
            switch (event.mouseButton.button)
            {
                case sf::Mouse::Left:
                isMouseLeftButtonDown = false;
                isMouseLeftButtonReleased = true;
                break;

                case sf::Mouse::Right:
                isMouseRightButtonDown = false;
                isMouseRightButtonReleased = true;
                break;

                default:
                break;
            }
        break;

        case sf::Event::MouseMoved:
            mousePosition = {event.mouseMove.x , event.mouseMove.y};
        break;

        default:
        break;
        }
    }
}

void EventManager::resetInputState()
{
    isMouseLeftButtonPressed = false;
    isMouseLeftButtonReleased = false;
    isMouseRightButtonPressed = false;
    isMouseRightButtonReleased = false;
}

bool EventManager::getIsKeyboardUpKeyDown() const
{
    return isKeyboardUpKeyDown;
}

bool EventManager::getIsKeyboardDownKeyDown() const
{
    return isKeyboardDownKeyDown;
}

bool EventManager::getIsKeyboardLeftKeyDown() const
{
    return isKeyboardLeftKeyDown;
}

bool EventManager::getIsKeyboardRightKeyDown() const
{
    return isKeyboardRightKeyDown;
}

sf::Vector2i EventManager::getMousePosition() const
{
    return mousePosition;
}

bool EventManager::getIsMouseLeftButtonPressed() const
{
    return isMouseLeftButtonPressed;
}

bool EventManager::getIsMouseLeftButtonDown() const
{
    return isMouseLeftButtonDown;
}

bool EventManager::getIsMouseLeftButtonReleased() const
{
    return isMouseLeftButtonReleased;
}

bool EventManager::getIsMouseRightButtonPressed() const
{
    return isMouseRightButtonPressed;
}

bool EventManager::getIsMouseRightButtonDown() const
{
    return isMouseRightButtonDown;
}

bool EventManager::getIsMouseRightButtonReleased() const
{
    return isMouseRightButtonReleased;
}
