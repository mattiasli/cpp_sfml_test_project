#include "../include/Player.hpp"
#include "../include/Handler.hpp"

Player::Player(Handler& handler, float xCoordinate, float yCoordinate)
: DynamicEntity(handler, xCoordinate, yCoordinate)
{
}

void Player::updateLogic()
{
    deltaX = 0;
    deltaY = 0;

    if(handler.getEventManager().getUpIsPressed()) deltaY -= 3.5f;
    if(handler.getEventManager().getDownIsPressed()) deltaY += 3.5f;
    if(handler.getEventManager().getLeftIsPressed()) deltaX -= 3.5f;
    if(handler.getEventManager().getRightIsPressed()) deltaX += 3.5f;

    updatePosition();
}

void Player::render() const
{
        handler.getSpriteManager().getPlayerSprite()->setPosition(xCoordinate, yCoordinate);
        handler.getRenderWindow().draw(*handler.getSpriteManager().getPlayerSprite());
}