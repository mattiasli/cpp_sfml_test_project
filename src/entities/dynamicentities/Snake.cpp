#include "../../../include/entities/dynamicentities/Snake.hpp"
#include "../../../include/core/Handler.hpp"

Snake::Snake(Handler& handler, sf::Vector2f worldCoordinate)
: NPCEntity(handler, worldCoordinate, BoundingBox(handler,
                                                  worldCoordinate,
                                                  sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                                                  sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}))
{
}

void Snake::render() const
{
    if(entityState == constants::EntityState::Idle)
    {
        handler.getSpriteManager().getAnimator(constants::EntityType::Snake, entityState, lastHorizontalDirection)->getSprite()->setPosition(worldCoordinate);
        handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getAnimator(constants::EntityType::Snake, entityState, lastHorizontalDirection)->getSprite());
    }
    else
    {
        handler.getSpriteManager().getAnimator(constants::EntityType::Snake, constants::EntityState::Walk, direction)->getSprite()->setPosition(worldCoordinate);
        handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getAnimator(constants::EntityType::Snake, constants::EntityState::Walk, direction)->getSprite());
    }
}

void Snake::applyPathFollowingMovementSpeed()
{
    movementSpeed = std::min(constants::defaultMaxMovementSpeed, handler.getProbabilityManager().generateLogNormalFloat(defaultMovementSpeedExpectedValue, defaultMovementSpeedStandardDeviation));
}

double Snake::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double Snake::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}