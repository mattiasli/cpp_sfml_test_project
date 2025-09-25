#include "../include/Handler.hpp"

Handler::Handler(sf::RenderWindow& renderWindow)
: eventManager(renderWindow)
{
}

EventManager& Handler::getEventManager()
{
    return eventManager;
}