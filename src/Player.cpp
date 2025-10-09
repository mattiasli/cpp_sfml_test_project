#include "../include/Player.hpp"
#include "../include/Handler.hpp"

Player::Player(Handler& handler, sf::Vector2f worldCoordinate)
: DynamicEntity(handler, worldCoordinate, BoundingBox(handler,
                                                      worldCoordinate,
                                                      sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                                                      sf::Vector2f{boundingBoxOffsetXWorldCoordinate, boundingBoxOffsetYWorldCoordinate}))
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

    if(handler.getEventManager().getIsKeyboardUpKeyDown()) deltaWorldCoordinate -= {0, movementSpeed * constants::scale};
    if(handler.getEventManager().getIsKeyboardDownKeyDown()) deltaWorldCoordinate += {0, movementSpeed * constants::scale};
    if(handler.getEventManager().getIsKeyboardLeftKeyDown()) deltaWorldCoordinate -= {movementSpeed * constants::scale, 0};
    if(handler.getEventManager().getIsKeyboardRightKeyDown()) deltaWorldCoordinate += {movementSpeed * constants::scale, 0};
}

void Player::render() const
{
    handler.getSpriteManager().getPlayerSprite()->setPosition(worldCoordinate);
    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getPlayerSprite());
}