#include "../../../include/entities/dynamicentities/CitizenMale.hpp"
#include "../../../include/core/Handler.hpp"

CitizenMale::CitizenMale(Handler& handler, sf::Vector2f worldCoordinate)
: NPCEntity(handler, worldCoordinate, BoundingBox(handler,
                                                  worldCoordinate,
                                                  sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                                                  sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}))
{
}

void CitizenMale::render() const
{
    handler.getSpriteManager().getSharedAnimator(constants::EntityType::CitizenMale, entityState, direction)->getSprite()->setPosition(worldCoordinate);
    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSharedAnimator(constants::EntityType::CitizenMale, entityState, direction)->getSprite());
}

void CitizenMale::applyPathFollowingMovementSpeed()
{
    movementSpeed = std::min(constants::defaultMaxMovementSpeed, handler.getProbabilityManager().generateLogNormalFloat(defaultMovementSpeedExpectedValue, defaultMovementSpeedStandardDeviation));
}

double CitizenMale::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double CitizenMale::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}