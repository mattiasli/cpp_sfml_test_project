#include "../../../include/entities/dynamicentities/Player.hpp"
#include "../../../include/core/Handler.hpp"

Player::Player(Handler& handler, sf::Vector2f worldCoordinate)
: DynamicEntity(handler, worldCoordinate, BoundingBox(handler,
                                                      worldCoordinate,
                                                      sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                                                      sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}))
{
}

void Player::updateLogic()
{
    processInput();
    DynamicEntity::updateLogic();
}

void Player::processInput()
{
    if(handler.getEventManager().getIsMouseLeftButtonPressed())
    {
        applyPathFollowingMovementSpeed();
        setPathStatus(handler.getPathFinder().computeAStarPath(handler.getCoordinateConverter().convertToGridCoordinate(boundingBox.getCenterWorldCoordinate()),
                                                               handler.getCoordinateConverter().convertToGridCoordinate((sf::Vector2f)handler.getEventManager().getMousePosition())));
    }

    sf::Vector2f arrowKeyDirection = constants::zeroVector;
    if(handler.getEventManager().getIsKeyboardUpKeyDown())
    {
        pathStatus.index = 0;
        pathStatus.gridCoordinateVector.clear();
        arrowKeyDirection -= {0.f, 1.f};
    }
    if(handler.getEventManager().getIsKeyboardDownKeyDown())
    {
        pathStatus.index = 0;
        pathStatus.gridCoordinateVector.clear();
        arrowKeyDirection += {0.f, 1.f};
    }
    if(handler.getEventManager().getIsKeyboardLeftKeyDown())
    {
        pathStatus.index = 0;
        pathStatus.gridCoordinateVector.clear();
        arrowKeyDirection -= {1.f, 0.f};
    }
    if(handler.getEventManager().getIsKeyboardRightKeyDown())
    {
        pathStatus.index = 0;
        pathStatus.gridCoordinateVector.clear();
        arrowKeyDirection += {1.f, 0.f};
    }

    if(pathStatus.gridCoordinateVector.empty() &&
       arrowKeyDirection == constants::zeroVector)
    {
        deltaWorldCoordinate = constants::zeroVector;
        movementSpeed = 0.f;
    }

    if(arrowKeyDirection != constants::zeroVector)
    {
        movementSpeed = getDefaultMovementSpeed();
        if(arrowKeyDirection.x != 0.f && arrowKeyDirection.y != 0.f)
        {
            deltaWorldCoordinate = arrowKeyDirection * constants::sin45 * movementSpeed * static_cast<float>(constants::scale);
        }
        else
        {
            deltaWorldCoordinate = arrowKeyDirection * movementSpeed * static_cast<float>(constants::scale);
        }
    }
}

void Player::render() const
{
    handler.getSpriteManager().getSharedAnimator(constants::EntityType::CapedWarrior, entityState, direction)->getSprite()->setPosition(worldCoordinate);
    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSharedAnimator(constants::EntityType::CapedWarrior, entityState, direction)->getSprite());
}

float Player::getDefaultMovementSpeed() const
{
    return defaultMovementSpeed;
}