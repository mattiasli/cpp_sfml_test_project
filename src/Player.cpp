#include "../include/Player.hpp"
#include "../include/Handler.hpp"

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

    if(handler.getEventManager().GetIsMouseLeftButtonPressed())
    {
        setPathStatus(handler.getPathFinder().computeAStarPath(handler.getCoordinateConverter().convertToGridCoordinate(boundingBox.getCenterWorldCoordinate()),
                                                               handler.getCoordinateConverter().convertToGridCoordinate((sf::Vector2f)handler.getEventManager().GetMousePosition())));
    }
    if(handler.getEventManager().getIsKeyboardUpKeyDown())
    {
        pathStatus.index = 0;
        pathStatus.gridCoordinateVector.clear();
        deltaWorldCoordinate -= {0, movementSpeed * constants::scale};
    }
    if(handler.getEventManager().getIsKeyboardDownKeyDown())
    {
        pathStatus.index = 0;
        pathStatus.gridCoordinateVector.clear();
        deltaWorldCoordinate += {0, movementSpeed * constants::scale};
    }
    if(handler.getEventManager().getIsKeyboardLeftKeyDown())
    {
        pathStatus.index = 0;
        pathStatus.gridCoordinateVector.clear();
        deltaWorldCoordinate -= {movementSpeed * constants::scale, 0};
    }
    if(handler.getEventManager().getIsKeyboardRightKeyDown())
    {
        pathStatus.index = 0;
        pathStatus.gridCoordinateVector.clear();
        deltaWorldCoordinate += {movementSpeed * constants::scale, 0};
    }
}

void Player::render() const
{
    handler.getSpriteManager().getPlayerSprite()->setPosition(worldCoordinate);
    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getPlayerSprite());
}

float Player::getMovementSpeed()
{
    return movementSpeed;
}