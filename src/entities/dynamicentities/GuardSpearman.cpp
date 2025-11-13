#include "../../../include/entities/dynamicentities/GuardSpearman.hpp"
#include "../../../include/core/Handler.hpp"

GuardSpearman::GuardSpearman(Handler& handler, sf::Vector2f worldCoordinate)
: NPCEntity(handler,
            worldCoordinate,
            BoundingBox(handler,
                        worldCoordinate,
                        sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                        sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}),
            constants::EntityType::GuardSpearman)
{
}

void GuardSpearman::render() const
{
    handler.getSpriteManager().getSharedAnimator(entityType, entityState, direction)->getSprite()->setPosition(worldCoordinate);
    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSharedAnimator(entityType, entityState, direction)->getSprite());
}

double GuardSpearman::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double GuardSpearman::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}

float GuardSpearman::getDefaultMovementSpeedExpectedValue() const
{
    return defaultMovementSpeedExpectedValue;
}

float GuardSpearman::getDefaultMovementSpeedStandardDeviation() const
{
    return defaultMovementSpeedStandardDeviation;
}