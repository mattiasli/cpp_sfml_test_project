#include "../../../include/entities/dynamicentities/CitizenFemale.hpp"
#include "../../../include/core/Handler.hpp"

CitizenFemale::CitizenFemale(Handler& handler, sf::Vector2f worldCoordinate)
: NPCEntity(handler, worldCoordinate, BoundingBox(handler,
                                                  worldCoordinate,
                                                  sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                                                  sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}))
{
    movementSpeed = handler.getProbabilityManager().generateLogNormalFloat(defaultMovementSpeedExpectedValue, defaultMovementSpeedStandardDeviation);
}

void CitizenFemale::render() const
{
    if(deltaWorldCoordinate == constants::zeroVector)
    {
        switch (direction)
        {
            case constants::Direction::Up:
                handler.getSpriteManager().getCitizenFemaleIdleUpAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenFemaleIdleUpAnimation()->getSprite());
            break;
            case constants::Direction::Down:
                handler.getSpriteManager().getCitizenFemaleIdleDownAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenFemaleIdleDownAnimation()->getSprite());
            break;
            case constants::Direction::Left:
                handler.getSpriteManager().getCitizenFemaleIdleLeftAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenFemaleIdleLeftAnimation()->getSprite());
            break;
            case constants::Direction::Right:
                handler.getSpriteManager().getCitizenFemaleIdleRightAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenFemaleIdleRightAnimation()->getSprite());
            break;
            default:
                handler.getSpriteManager().getCitizenFemaleIdleDownAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenFemaleIdleDownAnimation()->getSprite());
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
                    handler.getSpriteManager().getCitizenFemaleWalkUpAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenFemaleWalkUpAnimation()->getSprite());
                break;
                case constants::Direction::Down:
                    handler.getSpriteManager().getCitizenFemaleWalkDownAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenFemaleWalkDownAnimation()->getSprite());
                break;
                case constants::Direction::Left:
                    handler.getSpriteManager().getCitizenFemaleWalkLeftAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenFemaleWalkLeftAnimation()->getSprite());
                break;
                case constants::Direction::Right:
                    handler.getSpriteManager().getCitizenFemaleWalkRightAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenFemaleWalkRightAnimation()->getSprite());
                break;
                default:
                    handler.getSpriteManager().getCitizenFemaleWalkDownAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenFemaleWalkDownAnimation()->getSprite());
                break;
            }
        }
        else
        {
            switch (direction)
            {
                case constants::Direction::Up:
                    handler.getSpriteManager().getCitizenFemaleRunUpAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenFemaleRunUpAnimation()->getSprite());
                break;
                case constants::Direction::Down:
                    handler.getSpriteManager().getCitizenFemaleRunDownAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenFemaleRunDownAnimation()->getSprite());
                break;
                case constants::Direction::Left:
                    handler.getSpriteManager().getCitizenFemaleRunLeftAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenFemaleRunLeftAnimation()->getSprite());
                break;
                case constants::Direction::Right:
                    handler.getSpriteManager().getCitizenFemaleRunRightAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenFemaleRunRightAnimation()->getSprite());
                break;
                default:
                    handler.getSpriteManager().getCitizenFemaleRunDownAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getCitizenFemaleRunDownAnimation()->getSprite());
                break;
            }
        }
    }
}

void CitizenFemale::updateMovementSpeed()
{
    movementSpeed = std::min(constants::defaultMaxMovementSpeed, handler.getProbabilityManager().generateLogNormalFloat(defaultMovementSpeedExpectedValue, defaultMovementSpeedStandardDeviation));
}

float CitizenFemale::getMovementSpeed() const
{
    return movementSpeed;
}

double CitizenFemale::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double CitizenFemale::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}