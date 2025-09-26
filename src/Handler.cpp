#include "../include/Handler.hpp"

Handler::Handler(sf::RenderWindow& renderWindow)
: renderWindow(renderWindow),
eventManager(renderWindow),
map(*this),
spriteManager(*this)
{
}

sf::RenderWindow& Handler::getRenderWindow()
{
    return renderWindow;
}

EventManager& Handler::getEventManager()
{
    return eventManager;
}

Map& Handler::getMap()
{
    return map;
}

SpriteManager& Handler::getSpriteManager()
{
    return spriteManager;
}