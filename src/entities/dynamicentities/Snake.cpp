#include "../../../include/entities/dynamicentities/Snake.hpp"
#include "../../../include/core/Handler.hpp"

Snake::Snake(Handler& handler, sf::Vector2f worldCoordinate)
: NPCEntity(handler, worldCoordinate, BoundingBox(handler,
                                                  worldCoordinate,
                                                  sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                                                  sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}))
{
    movementSpeed = handler.getProbabilityManager().generateLogNormalFloat(defaultMovementSpeedExpectedValue, defaultMovementSpeedStandardDeviation);
}

void Snake::render() const
{
    handler.getSpriteManager().getSnakeSprite()->setPosition(worldCoordinate);
    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSnakeSprite());
}

void Snake::updateMovementSpeed()
{
    movementSpeed = std::min(constants::defaultMaxMovementSpeed, handler.getProbabilityManager().generateLogNormalFloat(defaultMovementSpeedExpectedValue, defaultMovementSpeedStandardDeviation));
}

float Snake::getMovementSpeed() const
{
    return movementSpeed;
}

double Snake::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double Snake::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}