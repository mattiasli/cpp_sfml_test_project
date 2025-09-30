#include "../include/DynamicEntity.hpp"
#include "../include/Handler.hpp"

DynamicEntity::DynamicEntity(Handler& handler, sf::Vector2f worldCoordinate, BoundingBox boundingBox)
: Entity(handler, worldCoordinate, boundingBox)
{
}

void DynamicEntity::updateLogic()
{
    updatePosition();
    boundingBox.setPosition(worldCoordinate);
}

void DynamicEntity::updatePosition()
{
    worldCoordinate += deltaWorldCoordinate;
}