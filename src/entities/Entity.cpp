#include "../../include/entities/Entity.hpp"
#include "../../include/core/Handler.hpp"

Entity::Entity(Handler& handler, sf::Vector2f worldCoordinate, const BoundingBox& boundingBox)
: handler(handler),
worldCoordinate(worldCoordinate),
boundingBox(boundingBox)
{
}

sf::Vector2f Entity::getWorldCoordinate()
{
    return worldCoordinate;
}