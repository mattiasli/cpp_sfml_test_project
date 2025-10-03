#include "../include/EventManager.hpp"
#include "../include/Handler.hpp"

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
                upIsPressed = true;
                break;

                case sf::Keyboard::Down:
                case sf::Keyboard::S:
                downIsPressed = true;
                break;

                case sf::Keyboard::Left:
                case sf::Keyboard::A:
                leftIsPressed = true;
                break;

                case sf::Keyboard::Right:
                case sf::Keyboard::D:
                rightIsPressed = true;
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
                upIsPressed = false;
                break;

                case sf::Keyboard::Down:
                case sf::Keyboard::S:
                downIsPressed = false;
                break;

                case sf::Keyboard::Left:
                case sf::Keyboard::A:
                leftIsPressed = false;
                break;

                case sf::Keyboard::Right:
                case sf::Keyboard::D:
                rightIsPressed = false;
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

bool EventManager::getUpIsPressed() const
{
    return upIsPressed;
}

bool EventManager::getDownIsPressed() const
{
    return downIsPressed;
}

bool EventManager::getLeftIsPressed() const
{
    return leftIsPressed;
}

bool EventManager::getRightIsPressed() const
{
    return rightIsPressed;
}

sf::Vector2i EventManager::GetMousePosition() const
{
    return mousePosition;
}

bool EventManager::GetIsMouseLeftButtonPressed() const
{
    return isMouseLeftButtonPressed;
}

bool EventManager::GetIsMouseLeftButtonDown() const
{
    return isMouseLeftButtonDown;
}

bool EventManager::GetIsMouseLeftButtonReleased() const
{
    return isMouseLeftButtonReleased;
}

bool EventManager::GetIsMouseRightButtonPressed() const
{
    return isMouseRightButtonPressed;
}

bool EventManager::GetIsMouseRightButtonDown() const
{
    return isMouseRightButtonDown;
}

bool EventManager::GetIsMouseRightButtonReleased() const
{
    return isMouseRightButtonReleased;
}
