#include "../../../include/entities/dynamicentities/Wolf.hpp"
#include "../../../include/core/Handler.hpp"

Wolf::Wolf(Handler& handler, sf::Vector2f worldCoordinate)
: NPCEntity(handler, worldCoordinate, BoundingBox(handler,
                                                  worldCoordinate,
                                                  sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                                                  sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}))
{
    movementSpeed = handler.getProbabilityManager().generateLogNormalFloat(defaultMovementSpeedExpectedValue, defaultMovementSpeedStandardDeviation);
}

void Wolf::render() const
{
    if(deltaWorldCoordinate == constants::zeroVector)
    {
        switch (direction)
        {
            case constants::Direction::Up:
                handler.getSpriteManager().getWolfIdleUpAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getWolfIdleUpAnimation()->getSprite());
            break;
            case constants::Direction::Down:
                handler.getSpriteManager().getWolfIdleDownAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getWolfIdleDownAnimation()->getSprite());
            break;
            case constants::Direction::Left:
                handler.getSpriteManager().getWolfIdleLeftAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getWolfIdleLeftAnimation()->getSprite());
            break;
            case constants::Direction::Right:
                handler.getSpriteManager().getWolfIdleRightAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getWolfIdleRightAnimation()->getSprite());
            break;
            default:
                handler.getSpriteManager().getWolfIdleDownAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getWolfIdleDownAnimation()->getSprite());
            break;
        }
    }
    else
    {
        if(movementSpeed < getRunAnimationThreshold())
        {
            switch (direction)
            {
                case constants::Direction::Up:
                    handler.getSpriteManager().getWolfWalkUpAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getWolfWalkUpAnimation()->getSprite());
                break;
                case constants::Direction::Down:
                    handler.getSpriteManager().getWolfWalkDownAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getWolfWalkDownAnimation()->getSprite());
                break;
                case constants::Direction::Left:
                    handler.getSpriteManager().getWolfWalkLeftAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getWolfWalkLeftAnimation()->getSprite());
                break;
                case constants::Direction::Right:
                    handler.getSpriteManager().getWolfWalkRightAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getWolfWalkRightAnimation()->getSprite());
                break;
                default:
                    handler.getSpriteManager().getWolfWalkDownAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getWolfWalkDownAnimation()->getSprite());
                break;
            }
        }
        else
        {
            switch (direction)
            {
                case constants::Direction::Up:
                    handler.getSpriteManager().getWolfRunUpAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getWolfRunUpAnimation()->getSprite());
                break;
                case constants::Direction::Down:
                    handler.getSpriteManager().getWolfRunDownAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getWolfRunDownAnimation()->getSprite());
                break;
                case constants::Direction::Left:
                    handler.getSpriteManager().getWolfRunLeftAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getWolfRunLeftAnimation()->getSprite());
                break;
                case constants::Direction::Right:
                    handler.getSpriteManager().getWolfRunRightAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getWolfRunRightAnimation()->getSprite());
                break;
                default:
                    handler.getSpriteManager().getWolfRunDownAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getWolfRunDownAnimation()->getSprite());
                break;
            }
        }
    }
}

void Wolf::updateMovementSpeed()
{
    movementSpeed = std::min(constants::defaultMaxMovementSpeed, handler.getProbabilityManager().generateLogNormalFloat(defaultMovementSpeedExpectedValue, defaultMovementSpeedStandardDeviation));
}

float Wolf::getMovementSpeed() const
{
    return movementSpeed;
}

double Wolf::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double Wolf::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}