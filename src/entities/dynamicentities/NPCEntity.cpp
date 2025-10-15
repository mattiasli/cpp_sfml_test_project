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

void NPCEntity::updateMovementSpeed()
{
    return;
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
        const int goalXGridCoordinate = handler.getProbabilityManager().generateUniformInteger(0, handler.getMap().getGridWidth() - 1);
        const int goalYGridCoordinate = handler.getProbabilityManager().generateUniformInteger(0, handler.getMap().getGridHeight() - 1);
        updateMovementSpeed();
        setPathStatus(handler.getPathFinder().computeAStarPath(handler.getCoordinateConverter().convertToGridCoordinate(getWorldCoordinate()),
                                                               sf::Vector2i(goalXGridCoordinate, goalYGridCoordinate)));
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
