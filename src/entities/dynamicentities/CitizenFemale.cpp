#include "../../../include/entities/dynamicentities/CitizenFemale.hpp"
#include "../../../include/core/Handler.hpp"

CitizenFemale::CitizenFemale(Handler& handler, sf::Vector2f worldCoordinate)
: NPCEntity(handler,
            worldCoordinate,
            BoundingBox(handler,
                        worldCoordinate,
                        sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                        sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}),
            constants::EntityType::CitizenFemale)
{
}

void CitizenFemale::render() const
{
    handler.getSpriteManager().getSharedAnimator(entityType, entityState, direction)->getSprite()->setPosition(worldCoordinate);
    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSharedAnimator(entityType, entityState, direction)->getSprite());
}

double CitizenFemale::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double CitizenFemale::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}

float CitizenFemale::getDefaultMovementSpeedExpectedValue() const
{
    return defaultMovementSpeedExpectedValue;
}

float CitizenFemale::getDefaultMovementSpeedStandardDeviation() const
{
    return defaultMovementSpeedStandardDeviation;
}