#include "../../include/control/NPCEntityController.hpp"
#include "../../include/core/Handler.hpp"

NPCEntityController::NPCEntityController(Handler& handler, DynamicEntity& dynamicEntity)
: DynamicEntityController(handler, dynamicEntity)
{
}

void NPCEntityController::gatherDecisionContext()
{
    decisionContext.reset();
}

void NPCEntityController::synthesizeIntent()
{
    intent.reset();

    switch (dynamicEntity.getEntityState())
    {
        case constants::EntityState::Idle:
            if(workingMemory.idleTimeRemainingMicroseconds > 0)
            {
                workingMemory.idleTimeRemainingMicroseconds -= constants::microsecondsPerTick;
            }
            else
            {
                synthesizeWalkRunIntent();
            }
        break;
        case constants::EntityState::Walk:
        case constants::EntityState::Run:
            if(dynamicEntity.getPathStatus().empty())
            {
                synthesizeIdleIntent();
            }
        break;

        default:
        break;
    }
}

void NPCEntityController::synthesizeIdleIntent()
{
    intent.hasEntityState = true;
    intent.entityState = constants::EntityState::Idle;
    workingMemory.idleTimeRemainingMicroseconds = handler.getProbabilityManager().generateUniformFloat(dynamicEntity.getMinWaitTimeMicroseconds(),
                                                                                                       dynamicEntity.getMaxWaitTimeMicroseconds());
}

void NPCEntityController::synthesizeWalkRunIntent()
{
    sf::Vector2i goalGridCoordinate;
    do
    {
        goalGridCoordinate = {handler.getProbabilityManager().generateUniformInteger(0, handler.getMap().getGridWidth() - 1),
                              handler.getProbabilityManager().generateUniformInteger(0, handler.getMap().getGridHeight() - 1)};
    } while (goalGridCoordinate ==  handler.getCoordinateConverter().convertToGridCoordinate(dynamicEntity.getBoundingBox().getCenterWorldCoordinate()));


    intent.hasEntityState = true;
    intent.hasGoalGridCoordinate = true;
    intent.goalGridCoordinate = goalGridCoordinate;
    intent.movementSpeed = handler.getProbabilityManager().generateLogNormalFloat(dynamicEntity.getDefaultMovementSpeedExpectedValue(),
                                                                                  dynamicEntity.getDefaultMovementSpeedStandardDeviation());
    if(intent.movementSpeed < dynamicEntity.getRunEntityStateThreshold())
    {
        intent.entityState = constants::EntityState::Walk;
    }
    else
    {
        intent.entityState = constants::EntityState::Run;
    }
}