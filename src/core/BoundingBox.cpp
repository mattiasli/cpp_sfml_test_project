#include "../../include/core/BoundingBox.hpp"
#include "../../include/core/Handler.hpp"

BoundingBox::BoundingBox(Handler& handler, sf::Vector2f entityWorldCoordinate, sf::Vector2f size, sf::Vector2f rectangleOffsetRelativeWorldCoordinate)
: handler(handler),
  entityWorldCoordinate(entityWorldCoordinate),
  rectangle(entityWorldCoordinate + rectangleOffsetRelativeWorldCoordinate * static_cast<float>(constants::scale), size),
  rectangleOffsetRelativeWorldCoordinate(rectangleOffsetRelativeWorldCoordinate)
{
}

void BoundingBox::setEntityWorldCoordinate(sf::Vector2f entityWorldCoordinat)
{
    entityWorldCoordinate = entityWorldCoordinat;
    updateRectangleFromEntityWorldCoordinate();
}

void BoundingBox::setEntityXWorldCoordinate(float entityXWorldCoordinate)
{
    entityWorldCoordinate.x = entityXWorldCoordinate;
    updateRectangleFromEntityWorldCoordinate();
}

void BoundingBox::setEntityYWorldCoordinate(float entityYWorldCoordinate)
{
    entityWorldCoordinate.y = entityYWorldCoordinate;
    updateRectangleFromEntityWorldCoordinate();
}

void BoundingBox::updateRectangleFromEntityWorldCoordinate()
{
    rectangle.left = entityWorldCoordinate.x + rectangleOffsetRelativeWorldCoordinate.x * constants::scale;
    rectangle.top = entityWorldCoordinate.y + rectangleOffsetRelativeWorldCoordinate.y * constants::scale;
}

sf::Vector2f BoundingBox::getEntityWorldCoordinate() const
{
    return entityWorldCoordinate;
}

float BoundingBox::getEntityXWorldCoordinate() const
{
    return entityWorldCoordinate.x;
}

float BoundingBox::getEntityYWorldCoordinate() const
{
    return entityWorldCoordinate.y;
}

void BoundingBox::setRectangleWorldCoordinate(sf::Vector2f rectangleWorldCoordinate)
{
    rectangle.left = rectangleWorldCoordinate.x;
    rectangle.top = rectangleWorldCoordinate.y;
    updateEntityWorldCoordinateFromRectangle();
}

void BoundingBox::setRectangleXWorldCoordinate(float rectangleXWorldCoordinate)
{
    rectangle.left = rectangleXWorldCoordinate;
    updateEntityWorldCoordinateFromRectangle();
}

void BoundingBox::setRectangleYWorldCoordinate(float rectangleYWorldCoordinate)
{
    rectangle.top = rectangleYWorldCoordinate;
    updateEntityWorldCoordinateFromRectangle();
}

void BoundingBox::updateEntityWorldCoordinateFromRectangle()
{
    entityWorldCoordinate = rectangle.getPosition() - rectangleOffsetRelativeWorldCoordinate * static_cast<float>(constants::scale);
}

sf::Vector2f BoundingBox::getRectangleWorldCoordinate() const
{
    return rectangle.getPosition();
}

float BoundingBox::getRectangleXWorldCoordinate() const
{
    return rectangle.left;
}

float BoundingBox::getRectangleYWorldCoordinate() const
{
    return rectangle.top;
}

float BoundingBox::getWidth() const
{
    return rectangle.width * constants::scale;
}

float BoundingBox::getHeight() const
{
    return rectangle.height * constants::scale;
}

float BoundingBox::getLeftEdgeXWorldCoordinate() const
{
    return rectangle.left;
}

float BoundingBox::getRightEdgeXWorldCoordinate() const
{
    return rectangle.left + rectangle.width * constants::scale - 1;
}

float BoundingBox::getTopEdgeYWorldCoordinate() const
{
    return rectangle.top;
}

float BoundingBox::getBottomEdgeYWorldCoordinate() const
{
    return rectangle.top + rectangle.height * constants::scale - 1;
}

sf::Vector2f BoundingBox::getCenterWorldCoordinate() const
{
    return rectangle.getPosition() + sf::Vector2f((rectangle.width * constants::scale) / 2, (rectangle.height * constants::scale) / 2);
}
