#include "../../../include/entities/dynamicentities/Snake.hpp"
#include "../../../include/core/Handler.hpp"

Snake::Snake(Handler& handler, sf::Vector2f worldCoordinate)
: NPCEntity(handler, worldCoordinate, BoundingBox(handler,
                                                  worldCoordinate,
                                                  sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                                                  sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}))
{
    movementSpeed = handler.getProbabilityManager().generateLogNormalFloat(defaultMovementSpeedExpectedValue, defaultMovementSpeedStandardDeviation);
}

void Snake::render() const
{
    if(deltaWorldCoordinate == constants::zeroVector)
    {
        switch (lastHorizontalDirection)
        {
            case constants::Direction::Left:
                handler.getSpriteManager().getSnakeIdleLeftAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSnakeIdleLeftAnimation()->getSprite());
            break;
            case constants::Direction::Right:
                handler.getSpriteManager().getSnakeIdleRightAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSnakeIdleRightAnimation()->getSprite());
            break;
            default:
                handler.getSpriteManager().getSnakeIdleRightAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSnakeIdleRightAnimation()->getSprite());
            break;
        }
    }
    else
    {
        switch (direction)
        {
            case constants::Direction::Up:
                handler.getSpriteManager().getSnakeWalkUpAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSnakeWalkUpAnimation()->getSprite());
            break;
            case constants::Direction::Down:
                handler.getSpriteManager().getSnakeWalkDownAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSnakeWalkDownAnimation()->getSprite());
            break;
            case constants::Direction::Left:
                handler.getSpriteManager().getSnakeWalkLeftAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSnakeWalkLeftAnimation()->getSprite());
            break;
            case constants::Direction::Right:
                handler.getSpriteManager().getSnakeWalkRightAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSnakeWalkRightAnimation()->getSprite());
            break;
            default:
                handler.getSpriteManager().getSnakeWalkDownAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getSnakeWalkDownAnimation()->getSprite());
            break;
        }
    }
}

void Snake::updateMovementSpeed()
{
    movementSpeed = std::min(constants::defaultMaxMovementSpeed, handler.getProbabilityManager().generateLogNormalFloat(defaultMovementSpeedExpectedValue, defaultMovementSpeedStandardDeviation));
}

float Snake::getMovementSpeed() const
{
    return movementSpeed;
}

double Snake::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double Snake::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}