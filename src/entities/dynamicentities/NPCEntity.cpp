#include "../../../include/entities/dynamicentities/NPCEntity.hpp"
#include "../../../include/core/Handler.hpp"

NPCEntity::NPCEntity(Handler& handler, sf::Vector2f worldCoordinate, const BoundingBox& boundingBox)
: DynamicEntity(handler, worldCoordinate, boundingBox)
{
    waitTimeRemainingMicroseconds = handler.getProbabilityManager().generateUniformFloat(getMinWaitTimeMicroseconds(), getMaxWaitTimeMicroseconds());
}

void NPCEntity::updateLogic()
{
    updateAction();
    DynamicEntity::updateLogic();
}

void NPCEntity::updateAction()
{
    if(pathStatus.gridCoordinateVector.empty())
    {
    waitTimeRemainingMicroseconds -= constants::microsecondsPerTick;
    waitTimeRemainingMicroseconds = std::max(0.0, waitTimeRemainingMicroseconds);
    if(waitTimeRemainingMicroseconds <= 0)
        {
        waitTimeRemainingMicroseconds = handler.getProbabilityManager().generateUniformFloat(getMinWaitTimeMicroseconds(), getMaxWaitTimeMicroseconds());
        applyPathFollowingMovementSpeed();
        const sf::Vector2i goalGridCoordinate = {handler.getProbabilityManager().generateUniformInteger(0, handler.getMap().getGridWidth() - 1),
                                                 handler.getProbabilityManager().generateUniformInteger(0, handler.getMap().getGridHeight() - 1)};
        setPathStatus(handler.getPathFinder().computeAStarPath(handler.getCoordinateConverter().convertToGridCoordinate(getWorldCoordinate()),
                                                               goalGridCoordinate));
        }
    }
}

double NPCEntity::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double NPCEntity::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}
