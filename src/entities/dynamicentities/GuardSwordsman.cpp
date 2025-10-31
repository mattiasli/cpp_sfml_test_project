#include "../../../include/entities/dynamicentities/GuardSwordsman.hpp"
#include "../../../include/core/Handler.hpp"

GuardSwordsman::GuardSwordsman(Handler& handler, sf::Vector2f worldCoordinate)
: NPCEntity(handler, worldCoordinate, BoundingBox(handler,
                                                  worldCoordinate,
                                                  sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                                                  sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}))
{
}

void GuardSwordsman::render() const
{
    handler.getSpriteManager().getSharedAnimator(constants::EntityType::GuardSwordsman, entityState, direction)->getSprite()->setPosition(worldCoordinate);
    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSharedAnimator(constants::EntityType::GuardSwordsman, entityState, direction)->getSprite());
}

void GuardSwordsman::applyPathFollowingMovementSpeed()
{
    movementSpeed = std::min(constants::defaultMaxMovementSpeed, handler.getProbabilityManager().generateLogNormalFloat(defaultMovementSpeedExpectedValue, defaultMovementSpeedStandardDeviation));
}

double GuardSwordsman::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double GuardSwordsman::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}