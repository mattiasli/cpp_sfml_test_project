#include "../../../include/entities/dynamicentities/GuardSpearman.hpp"
#include "../../../include/core/Handler.hpp"

GuardSpearman::GuardSpearman(Handler& handler, sf::Vector2f worldCoordinate)
: NPCEntity(handler, worldCoordinate, BoundingBox(handler,
                                                  worldCoordinate,
                                                  sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                                                  sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}))
{
}

void GuardSpearman::render() const
{
    handler.getSpriteManager().getSharedAnimator(constants::EntityType::GuardSpearman, entityState, direction)->getSprite()->setPosition(worldCoordinate);
    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSharedAnimator(constants::EntityType::GuardSpearman, entityState, direction)->getSprite());
}

void GuardSpearman::applyPathFollowingMovementSpeed()
{
    movementSpeed = std::min(constants::defaultMaxMovementSpeed, handler.getProbabilityManager().generateLogNormalFloat(defaultMovementSpeedExpectedValue, defaultMovementSpeedStandardDeviation));
}

double GuardSpearman::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double GuardSpearman::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}