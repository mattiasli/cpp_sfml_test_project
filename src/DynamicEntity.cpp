#include "../include/DynamicEntity.hpp"
#include "../include/Handler.hpp"

DynamicEntity::DynamicEntity(Handler& handler, float xCoordinate, float yCoordinate)
: Entity(handler, xCoordinate, yCoordinate)
{
}

void DynamicEntity::updateLogic()
{
    updatePosition();
}

void DynamicEntity::updatePosition()
{
    xCoordinate += deltaX;
    yCoordinate += deltaY;
}