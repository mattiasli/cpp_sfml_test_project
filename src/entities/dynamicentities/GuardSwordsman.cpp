#include "../../../include/entities/dynamicentities/GuardSwordsman.hpp"
#include "../../../include/core/Handler.hpp"

GuardSwordsman::GuardSwordsman(Handler& handler, sf::Vector2f worldCoordinate)
: NPCEntity(handler,
            worldCoordinate,
            BoundingBox(handler,
                        worldCoordinate,
                        sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                        sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}),
            constants::EntityType::GuardSwordsman)
{
}

void GuardSwordsman::render() const
{
    handler.getSpriteManager().getSharedAnimator(entityType, entityState, direction)->getSprite()->setPosition(worldCoordinate);
    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSharedAnimator(entityType, entityState, direction)->getSprite());
}

double GuardSwordsman::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double GuardSwordsman::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}

float GuardSwordsman::getDefaultMovementSpeedExpectedValue() const
{
    return defaultMovementSpeedExpectedValue;
}

float GuardSwordsman::getDefaultMovementSpeedStandardDeviation() const
{
    return defaultMovementSpeedStandardDeviation;
}