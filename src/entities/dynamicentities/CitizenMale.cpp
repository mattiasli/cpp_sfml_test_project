#include "../../../include/entities/dynamicentities/CitizenMale.hpp"
#include "../../../include/core/Handler.hpp"

CitizenMale::CitizenMale(Handler& handler, sf::Vector2f worldCoordinate)
: NPCEntity(handler, worldCoordinate, BoundingBox(handler,
                                                  worldCoordinate,
                                                  sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                                                  sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}))
{
    movementSpeed = handler.getProbabilityManager().generateLogNormalFloat(defaultMovementSpeedExpectedValue, defaultMovementSpeedStandardDeviation);
}

void CitizenMale::render() const
{
    if(deltaWorldCoordinate == constants::zeroVector)
    {
        switch (direction)
        {
            case constants::Direction::Up:
                handler.getSpriteManager().getCitizenMaleIdleUpAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenMaleIdleUpAnimation()->getSprite());
            break;
            case constants::Direction::Down:
                handler.getSpriteManager().getCitizenMaleIdleDownAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenMaleIdleDownAnimation()->getSprite());
            break;
            case constants::Direction::Left:
                handler.getSpriteManager().getCitizenMaleIdleLeftAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenMaleIdleLeftAnimation()->getSprite());
            break;
            case constants::Direction::Right:
                handler.getSpriteManager().getCitizenMaleIdleRightAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenMaleIdleRightAnimation()->getSprite());
            break;
            default:
                handler.getSpriteManager().getCitizenMaleIdleDownAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenMaleIdleDownAnimation()->getSprite());
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
                    handler.getSpriteManager().getCitizenMaleWalkUpAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenMaleWalkUpAnimation()->getSprite());
                break;
                case constants::Direction::Down:
                    handler.getSpriteManager().getCitizenMaleWalkDownAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenMaleWalkDownAnimation()->getSprite());
                break;
                case constants::Direction::Left:
                    handler.getSpriteManager().getCitizenMaleWalkLeftAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenMaleWalkLeftAnimation()->getSprite());
                break;
                case constants::Direction::Right:
                    handler.getSpriteManager().getCitizenMaleWalkRightAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenMaleWalkRightAnimation()->getSprite());
                break;
                default:
                    handler.getSpriteManager().getCitizenMaleWalkDownAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenMaleWalkDownAnimation()->getSprite());
                break;
            }
        }
        else
        {
            switch (direction)
            {
                case constants::Direction::Up:
                    handler.getSpriteManager().getCitizenMaleRunUpAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenMaleRunUpAnimation()->getSprite());
                break;
                case constants::Direction::Down:
                    handler.getSpriteManager().getCitizenMaleRunDownAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenMaleRunDownAnimation()->getSprite());
                break;
                case constants::Direction::Left:
                    handler.getSpriteManager().getCitizenMaleRunLeftAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenMaleRunLeftAnimation()->getSprite());
                break;
                case constants::Direction::Right:
                    handler.getSpriteManager().getCitizenMaleRunRightAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenMaleRunRightAnimation()->getSprite());
                break;
                default:
                    handler.getSpriteManager().getCitizenMaleRunDownAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenMaleRunDownAnimation()->getSprite());
                break;
            }
        }
    }
}

void CitizenMale::updateMovementSpeed()
{
    movementSpeed = std::min(constants::defaultMaxMovementSpeed, handler.getProbabilityManager().generateLogNormalFloat(defaultMovementSpeedExpectedValue, defaultMovementSpeedStandardDeviation));
}

float CitizenMale::getMovementSpeed() const
{
    return movementSpeed;
}

double CitizenMale::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double CitizenMale::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}