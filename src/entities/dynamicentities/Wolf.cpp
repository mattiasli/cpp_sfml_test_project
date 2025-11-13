#include "../../../include/entities/dynamicentities/Wolf.hpp"
#include "../../../include/core/Handler.hpp"

Wolf::Wolf(Handler& handler, sf::Vector2f worldCoordinate)
: NPCEntity(handler,
            worldCoordinate,
            BoundingBox(handler,
                        worldCoordinate,
                        sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                        sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}),
            constants::EntityType::Wolf)
{
}

void Wolf::render() const
{
    handler.getSpriteManager().getSharedAnimator(entityType, entityState, direction)->getSprite()->setPosition(worldCoordinate);
    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSharedAnimator(entityType, entityState, direction)->getSprite());
}

double Wolf::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double Wolf::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}

float Wolf::getDefaultMovementSpeedExpectedValue() const
{
    return defaultMovementSpeedExpectedValue;
}

float Wolf::getDefaultMovementSpeedStandardDeviation() const
{
    return defaultMovementSpeedStandardDeviation;
}