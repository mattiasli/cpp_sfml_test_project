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

    // std::cout << " x: " << handler.getCoordinateConverter().getGridCoordinate(boundingBox.getCenterWorldCoordinate()).x
    // << " y: " << handler.getCoordinateConverter().getGridCoordinate(boundingBox.getCenterWorldCoordinate()).y
    // << " solid: " << handler.getMap().isGridCoordinateSolid(handler.getCoordinateConverter().getGridCoordinate(boundingBox.getCenterWorldCoordinate())) << std::endl; // TODO: remove
}

void Player::processInput()
{
    deltaWorldCoordinate = {0, 0};

    if(handler.getEventManager().getUpIsPressed()) deltaWorldCoordinate -= {0, 4};
    if(handler.getEventManager().getDownIsPressed()) deltaWorldCoordinate += {0, 4};
    if(handler.getEventManager().getLeftIsPressed()) deltaWorldCoordinate -= {4, 0};
    if(handler.getEventManager().getRightIsPressed()) deltaWorldCoordinate += {4, 0};
}

void Player::render() const
{
    handler.getSpriteManager().getPlayerSprite()->setPosition(worldCoordinate);
    handler.getRenderWindow().draw(*handler.getSpriteManager().getPlayerSprite());
}