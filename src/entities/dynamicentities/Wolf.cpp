#include "../../../include/entities/dynamicentities/Wolf.hpp"
#include "../../../include/core/Handler.hpp"

Wolf::Wolf(Handler& handler, sf::Vector2f worldCoordinate)
: NPCEntity(handler, worldCoordinate, BoundingBox(handler,
                                                  worldCoordinate,
                                                  sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                                                  sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}))
{
}

void Wolf::render() const
{
    handler.getSpriteManager().getAnimation(constants::EntityType::Wolf, entityState, direction)->getSprite()->setPosition(worldCoordinate);
    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getAnimation(constants::EntityType::Wolf, entityState, direction)->getSprite());
}

void Wolf::applyPathFollowingMovementSpeed()
{
    movementSpeed = std::min(constants::defaultMaxMovementSpeed, handler.getProbabilityManager().generateLogNormalFloat(defaultMovementSpeedExpectedValue, defaultMovementSpeedStandardDeviation));
}

double Wolf::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double Wolf::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}