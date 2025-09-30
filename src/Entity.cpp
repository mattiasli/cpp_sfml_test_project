#include "../include/Entity.hpp"
#include "../include/Handler.hpp"

Entity::Entity(Handler& handler, sf::Vector2f worldCoordinate, BoundingBox boundingBox)
: handler(handler),
worldCoordinate(worldCoordinate),
boundingBox(boundingBox)
{
}

sf::Vector2f Entity::getWorldCoordinate()
{
    return worldCoordinate;
}