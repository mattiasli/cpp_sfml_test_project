#include "../../../include/entities/dynamicentities/Player.hpp"
#include "../../../include/core/Handler.hpp"

Player::Player(Handler& handler, sf::Vector2f worldCoordinate)
: DynamicEntity(handler,
                worldCoordinate,
                BoundingBox(handler,
                            worldCoordinate,
                            sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                            sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}),
                constants::EntityType::CapedWarrior)
{
    dynamicEntityController = std::make_unique<PlayerController>(handler, *this);
}

void Player::updateLogic()
{
    DynamicEntity::updateLogic();
}

void Player::render() const
{
    if(instanceAnimator.expired())
    {
        handler.getSpriteManager().getSharedAnimator(entityType, entityState, direction)->getSprite()->setPosition(worldCoordinate);
        handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSharedAnimator(entityType, entityState, direction)->getSprite());
    }
    else
    {
        instanceAnimator.lock()->getSprite()->setPosition(worldCoordinate + static_cast<sf::Vector2f>(instanceAnimator.lock()->getOffsetPixelPoint()) * static_cast<float>(constants::scale));
        handler.getRenderWindowManager().getRenderWindow().draw(*instanceAnimator.lock()->getSprite());
    }
}

float Player::getDefaultMovementSpeed() const
{
    return defaultMovementSpeed;
}