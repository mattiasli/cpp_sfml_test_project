#include "../../../include/entities/dynamicentities/Snake.hpp"
#include "../../../include/core/Handler.hpp"

Snake::Snake(Handler& handler, sf::Vector2f worldCoordinate)
: NPCEntity(handler,
            worldCoordinate,
            BoundingBox(handler,
                        worldCoordinate,
                        sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                        sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}),
            constants::EntityType::Snake)
{
}

void Snake::render() const
{
    if(entityState == constants::EntityState::Idle)
    {
        handler.getSpriteManager().getSharedAnimator(entityType, entityState, lastHorizontalDirection)->getSprite()->setPosition(worldCoordinate);
        handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSharedAnimator(entityType, entityState, lastHorizontalDirection)->getSprite());
    }
    else
    {
        handler.getSpriteManager().getSharedAnimator(entityType, constants::EntityState::Walk, direction)->getSprite()->setPosition(worldCoordinate);
        handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSharedAnimator(entityType, constants::EntityState::Walk, direction)->getSprite());
    }
}

double Snake::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double Snake::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}

float Snake::getDefaultMovementSpeedExpectedValue() const
{
    return defaultMovementSpeedExpectedValue;
}

float Snake::getDefaultMovementSpeedStandardDeviation() const
{
    return defaultMovementSpeedStandardDeviation;
}