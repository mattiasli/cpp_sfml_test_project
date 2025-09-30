#include "../include/BoundingBox.hpp"
#include "../include/Handler.hpp"

BoundingBox::BoundingBox(Handler& handler, sf::Vector2f worldCoordinate, sf::Vector2f size)
: handler(handler),
  floatRect(worldCoordinate.x, worldCoordinate.y, size.x, size.y),
  centerOffsetWorldCoordinate({size.x / 2, size.y / 2})
{
}

void BoundingBox::setPosition(sf::Vector2f worldCoordinate)
{
    floatRect.left = worldCoordinate.x;
    floatRect.top = worldCoordinate.y;
}

sf::Vector2f BoundingBox::getCenterWorldCoordinate()
{
    return floatRect.getPosition() + centerOffsetWorldCoordinate;
}