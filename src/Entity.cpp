#include "../include/Entity.hpp"
#include "../include/Handler.hpp"

Entity::Entity(Handler& handler, float xCoordinate, float yCoordinate)
: handler(handler),
xCoordinate(xCoordinate),
yCoordinate(yCoordinate)
{
}

float Entity::getXCoordinate()
{
    return xCoordinate;
}

float Entity::getYCoordinate()
{
    return yCoordinate;
}