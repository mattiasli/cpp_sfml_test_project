#include "../../../include/entities/dynamicentities/CitizenFemale.hpp"
#include "../../../include/core/Handler.hpp"

CitizenFemale::CitizenFemale(Handler& handler, sf::Vector2f worldCoordinate)
: NPCEntity(handler, worldCoordinate, BoundingBox(handler,
                                                  worldCoordinate,
                                                  sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                                                  sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}))
{
}

void CitizenFemale::render() const
{
    handler.getSpriteManager().getSharedAnimator(constants::EntityType::CitizenFemale, entityState, direction)->getSprite()->setPosition(worldCoordinate);
    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSharedAnimator(constants::EntityType::CitizenFemale, entityState, direction)->getSprite());
}

void CitizenFemale::applyPathFollowingMovementSpeed()
{
    movementSpeed = std::min(constants::defaultMaxMovementSpeed, handler.getProbabilityManager().generateLogNormalFloat(defaultMovementSpeedExpectedValue, defaultMovementSpeedStandardDeviation));
}

double CitizenFemale::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double CitizenFemale::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}