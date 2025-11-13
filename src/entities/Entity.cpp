#include "../../include/entities/Entity.hpp"
#include "../../include/core/Handler.hpp"

Entity::Entity(Handler& handler, sf::Vector2f worldCoordinate, const BoundingBox& boundingBox, constants::EntityType entityType)
: handler(handler),
worldCoordinate(worldCoordinate),
boundingBox(boundingBox),
entityType(entityType)
{
}

sf::Vector2f Entity::getWorldCoordinate() const
{
    return worldCoordinate;
}

const BoundingBox& Entity::getBoundingBox() const
{
    return boundingBox;
}

constants::Direction Entity::getDirection() const
{
    return direction;
}