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
    deltaWorldCoordinate = constants::zeroVector;

    if(handler.getEventManager().getIsMouseLeftButtonPressed())
    {
        setPathStatus(handler.getPathFinder().computeAStarPath(handler.getCoordinateConverter().convertToGridCoordinate(boundingBox.getCenterWorldCoordinate()),
                                                               handler.getCoordinateConverter().convertToGridCoordinate((sf::Vector2f)handler.getEventManager().getMousePosition())));
    }
    if(handler.getEventManager().getIsKeyboardUpKeyDown())
    {
        pathStatus.index = 0;
        pathStatus.gridCoordinateVector.clear();
        deltaWorldCoordinate -= {0, defaultMovementSpeed * constants::scale};
    }
    if(handler.getEventManager().getIsKeyboardDownKeyDown())
    {
        pathStatus.index = 0;
        pathStatus.gridCoordinateVector.clear();
        deltaWorldCoordinate += {0, defaultMovementSpeed * constants::scale};
    }
    if(handler.getEventManager().getIsKeyboardLeftKeyDown())
    {
        pathStatus.index = 0;
        pathStatus.gridCoordinateVector.clear();
        deltaWorldCoordinate -= {defaultMovementSpeed * constants::scale, 0};
    }
    if(handler.getEventManager().getIsKeyboardRightKeyDown())
    {
        pathStatus.index = 0;
        pathStatus.gridCoordinateVector.clear();
        deltaWorldCoordinate += {defaultMovementSpeed * constants::scale, 0};
    }
}

void Player::render() const
{
    if(deltaWorldCoordinate == constants::zeroVector)
    {
        switch (direction)
        {
            case constants::Direction::Up:
                handler.getSpriteManager().getCapedWarriorIdleUpAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCapedWarriorIdleUpAnimation()->getSprite());
            break;
            case constants::Direction::Down:
                handler.getSpriteManager().getCapedWarriorIdleDownAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCapedWarriorIdleDownAnimation()->getSprite());
            break;
            case constants::Direction::Left:
                handler.getSpriteManager().getCapedWarriorIdleLeftAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCapedWarriorIdleLeftAnimation()->getSprite());
            break;
            case constants::Direction::Right:
                handler.getSpriteManager().getCapedWarriorIdleRightAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCapedWarriorIdleRightAnimation()->getSprite());
            break;
            default:
                handler.getSpriteManager().getCapedWarriorIdleDownAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCapedWarriorIdleDownAnimation()->getSprite());
            break;
        }
    }
    else
    {
        switch (direction)
        {
            case constants::Direction::Up:
                handler.getSpriteManager().getCapedWarriorRunUpAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCapedWarriorRunUpAnimation()->getSprite());
            break;
            case constants::Direction::Down:
                handler.getSpriteManager().getCapedWarriorRunDownAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCapedWarriorRunDownAnimation()->getSprite());
            break;
            case constants::Direction::Left:
                handler.getSpriteManager().getCapedWarriorRunLeftAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCapedWarriorRunLeftAnimation()->getSprite());
            break;
            case constants::Direction::Right:
                handler.getSpriteManager().getCapedWarriorRunRightAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCapedWarriorRunRightAnimation()->getSprite());
            break;
            default:
                handler.getSpriteManager().getCapedWarriorRunDownAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCapedWarriorRunDownAnimation()->getSprite());
            break;
        }
    }
}

float Player::getMovementSpeed() const
{
    return defaultMovementSpeed;
}