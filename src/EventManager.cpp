#include "../include/EventManager.hpp"

EventManager::EventManager() {
}

void EventManager::processEvents(sf::RenderWindow& window)
{
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
            window.close();
            break;

            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                    case sf::Keyboard::Up:
                    upIsPressed = true;
                    break;

                    case sf::Keyboard::Down:
                    downIsPressed = true;
                    break;

                    case sf::Keyboard::Left:
                    leftIsPressed = true;
                    break;

                    case sf::Keyboard::Right:
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
                    upIsPressed = false;
                    break;

                    case sf::Keyboard::Down:
                    downIsPressed = false;
                    break;

                    case sf::Keyboard::Left:
                    leftIsPressed = false;
                    break;

                    case sf::Keyboard::Right:
                    rightIsPressed = false;
                    break;

                    default:
                    break;
                }
            break;

            default:
            break;
            }
        }
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