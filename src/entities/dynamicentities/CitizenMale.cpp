#include "../../../include/entities/dynamicentities/CitizenMale.hpp"
#include "../../../include/core/Handler.hpp"

CitizenMale::CitizenMale(Handler& handler, sf::Vector2f worldCoordinate)
: NPCEntity(handler,
            worldCoordinate,
            BoundingBox(handler,
                        worldCoordinate,
                        sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                        sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}),
            constants::EntityType::CitizenMale)
{
}

void CitizenMale::render() const
{
    handler.getSpriteManager().getSharedAnimator(entityType, entityState, direction)->getSprite()->setPosition(worldCoordinate);
    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSharedAnimator(entityType, entityState, direction)->getSprite());
}

double CitizenMale::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double CitizenMale::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}

float CitizenMale::getDefaultMovementSpeedExpectedValue() const
{
    return defaultMovementSpeedExpectedValue;
}

float CitizenMale::getDefaultMovementSpeedStandardDeviation() const
{
    return defaultMovementSpeedStandardDeviation;
}