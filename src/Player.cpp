#include "../include/Player.hpp"
#include "../include/Handler.hpp"

Player::Player(Handler& handler, sf::Vector2f worldCoordinate)
: DynamicEntity(handler, worldCoordinate, BoundingBox(handler,
                                                      worldCoordinate,
                                                      {constants::defaultSpriteWidth * constants::scale, constants::defaulSpriteHeight * constants::scale}))
{
}

void Player::updateLogic()
{
    processInput();
    DynamicEntity::updateLogic();
}

void Player::processInput()
{
    deltaWorldCoordinate = {0, 0};

    if(handler.getEventManager().getIsKeyboardUpKeyDown()) deltaWorldCoordinate -= {0, 4};
    if(handler.getEventManager().getIsKeyboardDownKeyDown()) deltaWorldCoordinate += {0, 4};
    if(handler.getEventManager().getIsKeyboardLeftKeyDown()) deltaWorldCoordinate -= {4, 0};
    if(handler.getEventManager().getIsKeyboardRightKeyDown()) deltaWorldCoordinate += {4, 0};
}

void Player::render() const
{
    handler.getSpriteManager().getPlayerSprite()->setPosition(worldCoordinate);
    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getPlayerSprite());
}