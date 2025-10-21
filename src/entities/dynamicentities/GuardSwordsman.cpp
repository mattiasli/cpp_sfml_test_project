#include "../../../include/entities/dynamicentities/GuardSwordsman.hpp"
#include "../../../include/core/Handler.hpp"

GuardSwordsman::GuardSwordsman(Handler& handler, sf::Vector2f worldCoordinate)
: NPCEntity(handler, worldCoordinate, BoundingBox(handler,
                                                  worldCoordinate,
                                                  sf::Vector2f{boundingBoxWidth, boundingBoxHeight},
                                                  sf::Vector2f{boundingBoxOffsetRelativeXWorldCoordinate, boundingBoxOffsetRelativeYWorldCoordinate}))
{
    movementSpeed = handler.getProbabilityManager().generateLogNormalFloat(defaultMovementSpeedExpectedValue, defaultMovementSpeedStandardDeviation);
}

void GuardSwordsman::render() const
{
    if(deltaWorldCoordinate == constants::zeroVector)
    {
        switch (direction)
        {
            case constants::Direction::Up:
                handler.getSpriteManager().getGuardSwordsmanIdleUpAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getGuardSwordsmanIdleUpAnimation()->getSprite());
            break;
            case constants::Direction::Down:
                handler.getSpriteManager().getGuardSwordsmanIdleDownAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getGuardSwordsmanIdleDownAnimation()->getSprite());
            break;
            case constants::Direction::Left:
                handler.getSpriteManager().getGuardSwordsmanIdleLeftAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getGuardSwordsmanIdleLeftAnimation()->getSprite());
            break;
            case constants::Direction::Right:
                handler.getSpriteManager().getGuardSwordsmanIdleRightAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getGuardSwordsmanIdleRightAnimation()->getSprite());
            break;
            default:
                handler.getSpriteManager().getGuardSwordsmanIdleDownAnimation()->getSprite()->setPosition(worldCoordinate);
                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getGuardSwordsmanIdleDownAnimation()->getSprite());
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
                    handler.getSpriteManager().getGuardSwordsmanWalkUpAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getGuardSwordsmanWalkUpAnimation()->getSprite());
                break;
                case constants::Direction::Down:
                    handler.getSpriteManager().getGuardSwordsmanWalkDownAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getGuardSwordsmanWalkDownAnimation()->getSprite());
                break;
                case constants::Direction::Left:
                    handler.getSpriteManager().getGuardSwordsmanWalkLeftAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getGuardSwordsmanWalkLeftAnimation()->getSprite());
                break;
                case constants::Direction::Right:
                    handler.getSpriteManager().getGuardSwordsmanWalkRightAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getGuardSwordsmanWalkRightAnimation()->getSprite());
                break;
                default:
                    handler.getSpriteManager().getGuardSwordsmanWalkDownAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getGuardSwordsmanWalkDownAnimation()->getSprite());
                break;
            }
        }
        else
        {
            switch (direction)
            {
                case constants::Direction::Up:
                    handler.getSpriteManager().getGuardSwordsmanRunUpAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getGuardSwordsmanRunUpAnimation()->getSprite());
                break;
                case constants::Direction::Down:
                    handler.getSpriteManager().getGuardSwordsmanRunDownAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getGuardSwordsmanRunDownAnimation()->getSprite());
                break;
                case constants::Direction::Left:
                    handler.getSpriteManager().getGuardSwordsmanRunLeftAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getGuardSwordsmanRunLeftAnimation()->getSprite());
                break;
                case constants::Direction::Right:
                    handler.getSpriteManager().getGuardSwordsmanRunRightAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getGuardSwordsmanRunRightAnimation()->getSprite());
                break;
                default:
                    handler.getSpriteManager().getGuardSwordsmanRunDownAnimation()->getSprite()->setPosition(worldCoordinate);
                    handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getGuardSwordsmanRunDownAnimation()->getSprite());
                break;
            }
        }
    }
}

void GuardSwordsman::updateMovementSpeed()
{
    movementSpeed = std::min(constants::defaultMaxMovementSpeed, handler.getProbabilityManager().generateLogNormalFloat(defaultMovementSpeedExpectedValue, defaultMovementSpeedStandardDeviation));
}

float GuardSwordsman::getMovementSpeed() const
{
    return movementSpeed;
}

double GuardSwordsman::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double GuardSwordsman::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}