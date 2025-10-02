#include "../include/EventManager.hpp"
#include "../include/Handler.hpp"

EventManager::EventManager(Handler& handler)
: handler(handler),
renderWindow(handler.getRenderWindowManager().getRenderWindow())
{
}

void EventManager::processEvents()
{
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

            case sf::Event::JoystickButtonPressed:
            if(event.joystickButton.button == sf::Joystick::PovX) rightIsPressed = true;
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