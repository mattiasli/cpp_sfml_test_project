#include "../../include/control/PlayerController.hpp"
#include "../../include/core/Handler.hpp"

PlayerController::PlayerController(Handler& handler, DynamicEntity& dynamicEntity)
: DynamicEntityController(handler, dynamicEntity)
{
}

void PlayerController::gatherDecisionContext()
{
    decisionContext.reset();

    if(handler.getEventManager().getIsKeyboardUpKeyDown())
    {
    decisionContext.controlInput.hasKeyboardDirection = true;
    decisionContext.controlInput.keyboardDirection -= {0.f, 1.f};
    }
    if(handler.getEventManager().getIsKeyboardDownKeyDown())
    {
    decisionContext.controlInput.hasKeyboardDirection = true;
    decisionContext.controlInput.keyboardDirection += {0.f, 1.f};
    }
    if(handler.getEventManager().getIsKeyboardLeftKeyDown())
    {
    decisionContext.controlInput.hasKeyboardDirection = true;
    decisionContext.controlInput.keyboardDirection -= {1.f, 0.f};
    }
    if(handler.getEventManager().getIsKeyboardRightKeyDown())
    {
    decisionContext.controlInput.hasKeyboardDirection = true;
    decisionContext.controlInput.keyboardDirection += {1.f, 0.f};
    }

    if(decisionContext.controlInput.keyboardDirection.x != 0.f &&
       decisionContext.controlInput.keyboardDirection.y != 0.f)
    {
        decisionContext.controlInput.keyboardDirection = decisionContext.controlInput.keyboardDirection * constants::sin45;
    }

    decisionContext.controlInput.isKeyboardAttackActive = handler.getEventManager().getIsKeyboardZKeyPressed();

    if(handler.getEventManager().getIsMouseLeftButtonPressed())
    {
        decisionContext.controlInput.hasMouseGoalWorldCoordinate = true;
        decisionContext.controlInput.mouseGoalWorldCoordinate = handler.getEventManager().getMousePosition();
    }
}

void PlayerController::synthesizeIntent()
{
    intent.reset();

    switch (dynamicEntity.getEntityState())
    {
        case constants::EntityState::Idle:
        case constants::EntityState::Walk:
        case constants::EntityState::Run:
            if(decisionContext.controlInput.isKeyboardAttackActive)
            {
                synthesizeAttackIntent();
            }
            else
            {
                synthesizeIdleWalkRunIntent();
            }
        break;

        case constants::EntityState::Attack:
            if(dynamicEntity.getInstanceAnimator().expired())
            {
                if(decisionContext.controlInput.isKeyboardAttackActive)
                {
                    synthesizeAttackIntent();
                }
                else
                {
                    synthesizeIdleWalkRunIntent();
                }
            }
        break;

        default:
        break;
    }
}

void PlayerController::synthesizeIdleWalkRunIntent()
{
    if(decisionContext.controlInput.hasKeyboardDirection)
    {
        intent.hasEntityState = true;
        intent.hasMovementDirection = true;
        intent.movementDirection = decisionContext.controlInput.keyboardDirection;
        intent.movementSpeed = dynamicEntity.getDefaultMovementSpeed();

        if(intent.movementSpeed < dynamicEntity.getRunEntityStateThreshold())
        {
            intent.entityState = constants::EntityState::Walk;
        }
        else
        {
            intent.entityState = constants::EntityState::Run;
        }
    }
    else if(decisionContext.controlInput.hasMouseGoalWorldCoordinate)
    {
        sf::Vector2i goalGridCoordinate = handler.getCoordinateConverter().convertToGridCoordinate(static_cast<sf::Vector2f>(decisionContext.controlInput.mouseGoalWorldCoordinate));

        if(handler.getCoordinateConverter().convertToGridCoordinate(dynamicEntity.getBoundingBox().getCenterWorldCoordinate()) != goalGridCoordinate)
        {
            intent.hasEntityState = true;
            intent.hasGoalGridCoordinate = true;
            intent.goalGridCoordinate = goalGridCoordinate;
            intent.movementSpeed = dynamicEntity.getDefaultMovementSpeed();

            if(intent.movementSpeed < dynamicEntity.getRunEntityStateThreshold())
            {
                intent.entityState = constants::EntityState::Walk;
            }
            else
            {
                intent.entityState = constants::EntityState::Run;
            }
        }
    }
    else if(dynamicEntity.getPathStatus().empty())
    {
        intent.hasEntityState = true;
        intent.entityState = constants::EntityState::Idle;
    }
}

void PlayerController::synthesizeAttackIntent()
{
    intent.hasEntityState = true;
    intent.hasMovementDirection = true;
    intent.entityState = constants::EntityState::Attack;
    intent.movementDirection = constants::zeroVectorF;
}