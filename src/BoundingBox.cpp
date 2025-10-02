#include "../include/BoundingBox.hpp"
#include "../include/Handler.hpp"

BoundingBox::BoundingBox(Handler& handler, sf::Vector2f worldCoordinate, sf::Vector2f size)
: handler(handler),
  floatRect(worldCoordinate.x, worldCoordinate.y, size.x, size.y)
{
}

void BoundingBox::setPosition(sf::Vector2f worldCoordinate)
{
    floatRect.left = worldCoordinate.x;
    floatRect.top = worldCoordinate.y;
}

void BoundingBox::setXWorldCoordinate(float xWorldCoordinate)
{
    floatRect.left = xWorldCoordinate;
}

void BoundingBox::setYWorldCoordinate(float yWorldCoordinate)
{
    floatRect.top = yWorldCoordinate;
}

sf::Vector2f BoundingBox::getCenterWorldCoordinate()
{
    return floatRect.getPosition() + sf::Vector2f{floatRect.width / 2, floatRect.height / 2};
}

float BoundingBox::getLeftEdgeXWorldCoordinate()
{
    return floatRect.left;
}

float BoundingBox::getRightEdgeXWorldCoordinate()
{
    return floatRect.left + floatRect.width - 1;
}

float BoundingBox::getTopEdgeYWorldCoordinate()
{
    return floatRect.top;
}

float BoundingBox::getBottomEdgeYWorldCoordinate()
{
    return floatRect.top + floatRect.height - 1;
}
