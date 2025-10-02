#include "../include/Handler.hpp"

Handler::Handler()
: eventManager(*this),
map(*this),
spriteManager(*this),
coordinateConverter(*this),
renderWindowManager(*this)
{
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

CoordinateConverter& Handler::getCoordinateConverter()
{
    return coordinateConverter;
}

RenderWindowManager& Handler::getRenderWindowManager()
{
    return renderWindowManager;
}