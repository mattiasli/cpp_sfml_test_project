#include "../../include/graphics/SpriteManager.hpp"
#include "../../include/core/Handler.hpp"

SpriteManager::SpriteManager(Handler& handler)
: handler(handler)
{
    spriteAtlas.loadFromFile("../res/spritesheet.png");

    dirtSprite.setTexture(spriteAtlas);
    dirtSprite.setTextureRect({0 * constants::tileWidth, 1 * constants::tileHeight, 1 * constants::tileWidth, 1 * constants::tileHeight});
    dirtSprite.setScale(constants::scale , constants::scale);

    grassSprite.setTexture(spriteAtlas);
    grassSprite.setTextureRect({1 * constants::tileWidth, 1 * constants::tileHeight, 1 * constants::tileWidth, 1 * constants::tileHeight});
    grassSprite.setScale(constants::scale , constants::scale);

    boulderSprite.setTexture(spriteAtlas);
    boulderSprite.setTextureRect({0 * constants::tileWidth, 0 * constants::tileHeight, 1 * constants::tileWidth, 1 * constants::tileHeight});
    boulderSprite.setScale(constants::scale , constants::scale);

    groveSprite.setTexture(spriteAtlas);
    groveSprite.setTextureRect({1 * constants::tileWidth, 0 * constants::tileHeight, 1 * constants::tileWidth, 1 * constants::tileHeight});
    groveSprite.setScale(constants::scale , constants::scale);

    waterSprite.setTexture(spriteAtlas);
    waterSprite.setTextureRect({0 * constants::tileWidth, 2 * constants::tileHeight, 1 * constants::tileWidth, 1 * constants::tileHeight});
    waterSprite.setScale(constants::scale , constants::scale);

    capedWarriorIdleUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({4, 7}, {1, 1}, 4), 500000.0);
    capedWarriorIdleDownAnimation = new Animation(handler, spriteAtlas,  computeTextureRectangleSequence({4, 6}, {1, 1}, 4), 500000.0);
    capedWarriorIdleLeftAnimation = new Animation(handler, spriteAtlas,  computeTextureRectangleSequence({4, 5}, {1, 1}, 4), 500000.0);
    capedWarriorIdleRightAnimation = new Animation(handler, spriteAtlas,  computeTextureRectangleSequence({4, 4}, {1, 1}, 4), 500000.0);
    capedWarriorRunUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({4, 11}, {1, 1}, 4), 125000.0);
    capedWarriorRunDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({4, 10}, {1, 1}, 4), 125000.0);
    capedWarriorRunLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({4, 9}, {1, 1}, 4), 125000.0);
    capedWarriorRunRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({4, 8}, {1, 1}, 4), 125000.0);

    animationVector.push_back(capedWarriorIdleUpAnimation);
    animationVector.push_back(capedWarriorIdleDownAnimation);
    animationVector.push_back(capedWarriorIdleLeftAnimation);
    animationVector.push_back(capedWarriorIdleRightAnimation);
    animationVector.push_back(capedWarriorRunUpAnimation);
    animationVector.push_back(capedWarriorRunDownAnimation);
    animationVector.push_back(capedWarriorRunLeftAnimation);
    animationVector.push_back(capedWarriorRunRightAnimation);

    guardSwordsmanIdleUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 7}, {1, 1}, 4), 500000.0);
    guardSwordsmanIdleDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 6}, {1, 1}, 4), 500000.0);
    guardSwordsmanIdleLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 5}, {1, 1}, 4), 500000.0);
    guardSwordsmanIdleRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 4}, {1, 1}, 4), 500000.0);
    guardSwordsmanWalkUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 11}, {1, 1}, 4), 187500.0);
    guardSwordsmanWalkDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 10}, {1, 1}, 4), 187500.0);
    guardSwordsmanWalkLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 9}, {1, 1}, 4), 187500.0);
    guardSwordsmanWalkRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 8}, {1, 1}, 4), 187500.0);
    guardSwordsmanRunUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 15}, {1, 1}, 4), 125000.0);
    guardSwordsmanRunDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 14}, {1, 1}, 4), 125000.0);
    guardSwordsmanRunLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 13}, {1, 1}, 4), 125000.0);
    guardSwordsmanRunRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 12}, {1, 1}, 4), 125000.0);

    animationVector.push_back(guardSwordsmanIdleUpAnimation);
    animationVector.push_back(guardSwordsmanIdleDownAnimation);
    animationVector.push_back(guardSwordsmanIdleLeftAnimation);
    animationVector.push_back(guardSwordsmanIdleRightAnimation);
    animationVector.push_back(guardSwordsmanWalkUpAnimation);
    animationVector.push_back(guardSwordsmanWalkDownAnimation);
    animationVector.push_back(guardSwordsmanWalkLeftAnimation);
    animationVector.push_back(guardSwordsmanWalkRightAnimation);
    animationVector.push_back(guardSwordsmanRunUpAnimation);
    animationVector.push_back(guardSwordsmanRunDownAnimation);
    animationVector.push_back(guardSwordsmanRunLeftAnimation);
    animationVector.push_back(guardSwordsmanRunRightAnimation);

    citizenMaleIdleUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 7}, {1, 1}, 4), 500000.0);
    citizenMaleIdleDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 6}, {1, 1}, 4), 500000.0);
    citizenMaleIdleLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 5}, {1, 1}, 4), 500000.0);
    citizenMaleIdleRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 4}, {1, 1}, 4), 500000.0);
    citizenMaleWalkUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 11}, {1, 1}, 4), 187500.0);
    citizenMaleWalkDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 10}, {1, 1}, 4), 187500.0);
    citizenMaleWalkLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 9}, {1, 1}, 4), 187500.0);
    citizenMaleWalkRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 8}, {1, 1}, 4), 187500.0);
    citizenMaleRunUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 15}, {1, 1}, 4), 125000.0);
    citizenMaleRunDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 14}, {1, 1}, 4), 125000.0);
    citizenMaleRunLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 13}, {1, 1}, 4), 125000.0);
    citizenMaleRunRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 12}, {1, 1}, 4), 125000.0);

    animationVector.push_back(citizenMaleIdleUpAnimation);
    animationVector.push_back(citizenMaleIdleDownAnimation);
    animationVector.push_back(citizenMaleIdleLeftAnimation);
    animationVector.push_back(citizenMaleIdleRightAnimation);
    animationVector.push_back(citizenMaleWalkUpAnimation);
    animationVector.push_back(citizenMaleWalkDownAnimation);
    animationVector.push_back(citizenMaleWalkLeftAnimation);
    animationVector.push_back(citizenMaleWalkRightAnimation);
    animationVector.push_back(citizenMaleRunUpAnimation);
    animationVector.push_back(citizenMaleRunDownAnimation);
    animationVector.push_back(citizenMaleRunLeftAnimation);
    animationVector.push_back(citizenMaleRunRightAnimation);

    citizenFemaleIdleUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 7}, {1, 1}, 4), 500000.0);
    citizenFemaleIdleDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 6}, {1, 1}, 4), 500000.0);
    citizenFemaleIdleLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 5}, {1, 1}, 4), 500000.0);
    citizenFemaleIdleRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 4}, {1, 1}, 4), 500000.0);
    citizenFemaleWalkUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 11}, {1, 1}, 4), 187500.0);
    citizenFemaleWalkDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 10}, {1, 1}, 4), 187500.0);
    citizenFemaleWalkLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 9}, {1, 1}, 4), 187500.0);
    citizenFemaleWalkRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 8}, {1, 1}, 4), 187500.0);
    citizenFemaleRunUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 15}, {1, 1}, 4), 125000.0);
    citizenFemaleRunDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 14}, {1, 1}, 4), 125000.0);
    citizenFemaleRunLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 13}, {1, 1}, 4), 125000.0);
    citizenFemaleRunRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 12}, {1, 1}, 4), 125000.0);

    animationVector.push_back(citizenFemaleIdleUpAnimation);
    animationVector.push_back(citizenFemaleIdleDownAnimation);
    animationVector.push_back(citizenFemaleIdleLeftAnimation);
    animationVector.push_back(citizenFemaleIdleRightAnimation);
    animationVector.push_back(citizenFemaleWalkUpAnimation);
    animationVector.push_back(citizenFemaleWalkDownAnimation);
    animationVector.push_back(citizenFemaleWalkLeftAnimation);
    animationVector.push_back(citizenFemaleWalkRightAnimation);
    animationVector.push_back(citizenFemaleRunUpAnimation);
    animationVector.push_back(citizenFemaleRunDownAnimation);
    animationVector.push_back(citizenFemaleRunLeftAnimation);
    animationVector.push_back(citizenFemaleRunRightAnimation);

    wolfIdleUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 7}, {1, 1}, 4), 500000.0);
    wolfIdleDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 6}, {1, 1}, 4), 500000.0);
    wolfIdleLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 5}, {1, 1}, 4), 500000.0);
    wolfIdleRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 4}, {1, 1}, 4), 500000.0);
    wolfWalkUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 11}, {1, 1}, 4), 187500.0);
    wolfWalkDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 10}, {1, 1}, 4), 187500.0);
    wolfWalkLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 9}, {1, 1}, 4), 187500.0);
    wolfWalkRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 8}, {1, 1}, 4), 187500.0);
    wolfRunUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 15}, {1, 1}, 4), 125000.0);
    wolfRunDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 14}, {1, 1}, 4), 125000.0);
    wolfRunLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 13}, {1, 1}, 4), 125000.0);
    wolfRunRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 12}, {1, 1}, 4), 125000.0);

    animationVector.push_back(wolfIdleUpAnimation);
    animationVector.push_back(wolfIdleDownAnimation);
    animationVector.push_back(wolfIdleLeftAnimation);
    animationVector.push_back(wolfIdleRightAnimation);
    animationVector.push_back(wolfWalkUpAnimation);
    animationVector.push_back(wolfWalkDownAnimation);
    animationVector.push_back(wolfWalkLeftAnimation);
    animationVector.push_back(wolfWalkRightAnimation);
    animationVector.push_back(wolfRunUpAnimation);
    animationVector.push_back(wolfRunDownAnimation);
    animationVector.push_back(wolfRunLeftAnimation);
    animationVector.push_back(wolfRunRightAnimation);

    snakeIdleLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 5}, {1, 1}, 4), 500000.0);
    snakeIdleRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 4}, {1, 1}, 4), 500000.0);
    snakeWalkUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 9}, {1, 1}, 4), 250000.0);
    snakeWalkDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 8}, {1, 1}, 4), 250000.0);
    snakeWalkLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 7}, {1, 1}, 4), 250000.0);
    snakeWalkRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 6}, {1, 1}, 4), 250000.0);

    animationVector.push_back(snakeIdleLeftAnimation);
    animationVector.push_back(snakeIdleRightAnimation);
    animationVector.push_back(snakeWalkUpAnimation);
    animationVector.push_back(snakeWalkDownAnimation);
    animationVector.push_back(snakeWalkLeftAnimation);
    animationVector.push_back(snakeWalkRightAnimation);
}

void SpriteManager::updateLogic()
{
    for(Animation* animation : animationVector)
    {
        animation->updateLogic();
    }
}

std::vector<sf::IntRect> SpriteManager::computeTextureRectangleSequence(sf::Vector2i startTexureGridIndex, sf::Vector2i rectangleTextureGridSize, std::uint8_t seqenceLength)
{
    std::vector<sf::IntRect> textureRectangleSequence;
    textureRectangleSequence.reserve(seqenceLength);

    for(std::uint8_t i = 0; i < seqenceLength; i++)
    {
        textureRectangleSequence.emplace_back((startTexureGridIndex.x + i) * constants::defaultSpriteWidth,
                                              startTexureGridIndex.y * constants::defaulSpriteHeight,
                                              rectangleTextureGridSize.x * constants::defaultSpriteWidth,
                                              rectangleTextureGridSize.y * constants::defaultSpriteWidth);
    }

    return textureRectangleSequence;
}

sf::Sprite* SpriteManager::getDirtSprite()
{
    return &dirtSprite;
}

sf::Sprite* SpriteManager::getGrassSprite()
{
    return &grassSprite;
}

sf::Sprite* SpriteManager::getBoulderSprite()
{
    return &boulderSprite;
}

sf::Sprite* SpriteManager::getGroveSprite()
{
    return &groveSprite;
}

sf::Sprite* SpriteManager::getWaterSprite()
{
    return &waterSprite;
}

Animation* SpriteManager::getCapedWarriorIdleUpAnimation()
{
    return capedWarriorIdleUpAnimation;
}

Animation* SpriteManager::getCapedWarriorIdleDownAnimation()
{
    return capedWarriorIdleDownAnimation;
}

Animation* SpriteManager::getCapedWarriorIdleLeftAnimation()
{
    return capedWarriorIdleLeftAnimation;
}

Animation* SpriteManager::getCapedWarriorIdleRightAnimation()
{
    return capedWarriorIdleRightAnimation;
}

Animation* SpriteManager::getCapedWarriorRunUpAnimation()
{
    return capedWarriorRunUpAnimation;
}

Animation* SpriteManager::getCapedWarriorRunDownAnimation()
{
    return capedWarriorRunDownAnimation;
}

Animation* SpriteManager::getCapedWarriorRunLeftAnimation()
{
    return capedWarriorRunLeftAnimation;
}

Animation* SpriteManager::getCapedWarriorRunRightAnimation()
{
    return capedWarriorRunRightAnimation;
}

Animation* SpriteManager::getGuardSwordsmanIdleUpAnimation()
{
    return guardSwordsmanIdleUpAnimation;
}

Animation* SpriteManager::getGuardSwordsmanIdleDownAnimation()
{
    return guardSwordsmanIdleDownAnimation;
}

Animation* SpriteManager::getGuardSwordsmanIdleLeftAnimation()
{
    return guardSwordsmanIdleLeftAnimation;
}

Animation* SpriteManager::getGuardSwordsmanIdleRightAnimation()
{
    return guardSwordsmanIdleRightAnimation;
}

Animation* SpriteManager::getGuardSwordsmanWalkUpAnimation()
{
    return guardSwordsmanWalkUpAnimation;
}

Animation* SpriteManager::getGuardSwordsmanWalkDownAnimation()
{
    return guardSwordsmanWalkDownAnimation;
}

Animation* SpriteManager::getGuardSwordsmanWalkLeftAnimation()
{
    return guardSwordsmanWalkLeftAnimation;
}

Animation* SpriteManager::getGuardSwordsmanWalkRightAnimation()
{
    return guardSwordsmanWalkRightAnimation;
}

Animation* SpriteManager::getGuardSwordsmanRunUpAnimation()
{
    return guardSwordsmanRunUpAnimation;
}

Animation* SpriteManager::getGuardSwordsmanRunDownAnimation()
{
    return guardSwordsmanRunDownAnimation;
}

Animation* SpriteManager::getGuardSwordsmanRunLeftAnimation()
{
    return guardSwordsmanRunLeftAnimation;
}

Animation* SpriteManager::getGuardSwordsmanRunRightAnimation()
{
    return guardSwordsmanRunRightAnimation;
}

Animation* SpriteManager::getCitizenMaleIdleUpAnimation()
{
    return citizenMaleIdleUpAnimation;
}

Animation* SpriteManager::getCitizenMaleIdleDownAnimation()
{
    return citizenMaleIdleDownAnimation;
}

Animation* SpriteManager::getCitizenMaleIdleLeftAnimation()
{
    return citizenMaleIdleLeftAnimation;
}

Animation* SpriteManager::getCitizenMaleIdleRightAnimation()
{
    return citizenMaleIdleRightAnimation;
}

Animation* SpriteManager::getCitizenMaleWalkUpAnimation()
{
    return citizenMaleWalkUpAnimation;
}

Animation* SpriteManager::getCitizenMaleWalkDownAnimation()
{
    return citizenMaleWalkDownAnimation;
}

Animation* SpriteManager::getCitizenMaleWalkLeftAnimation()
{
    return citizenMaleWalkLeftAnimation;
}

Animation* SpriteManager::getCitizenMaleWalkRightAnimation()
{
    return citizenMaleWalkRightAnimation;
}

Animation* SpriteManager::getCitizenMaleRunUpAnimation()
{
    return citizenMaleRunUpAnimation;
}

Animation* SpriteManager::getCitizenMaleRunDownAnimation()
{
    return citizenMaleRunDownAnimation;
}

Animation* SpriteManager::getCitizenMaleRunLeftAnimation()
{
    return citizenMaleRunLeftAnimation;
}

Animation* SpriteManager::getCitizenMaleRunRightAnimation()
{
    return citizenMaleRunRightAnimation;
}

Animation* SpriteManager::getCitizenFemaleIdleUpAnimation()
{
    return citizenFemaleIdleUpAnimation;
}

Animation* SpriteManager::getCitizenFemaleIdleDownAnimation()
{
    return citizenFemaleIdleDownAnimation;
}

Animation* SpriteManager::getCitizenFemaleIdleLeftAnimation()
{
    return citizenFemaleIdleLeftAnimation;
}

Animation* SpriteManager::getCitizenFemaleIdleRightAnimation()
{
    return citizenFemaleIdleRightAnimation;
}

Animation* SpriteManager::getCitizenFemaleWalkUpAnimation()
{
    return citizenFemaleWalkUpAnimation;
}

Animation* SpriteManager::getCitizenFemaleWalkDownAnimation()
{
    return citizenFemaleWalkDownAnimation;
}

Animation* SpriteManager::getCitizenFemaleWalkLeftAnimation()
{
    return citizenFemaleWalkLeftAnimation;
}

Animation* SpriteManager::getCitizenFemaleWalkRightAnimation()
{
    return citizenFemaleWalkRightAnimation;
}

Animation* SpriteManager::getCitizenFemaleRunUpAnimation()
{
    return citizenFemaleRunUpAnimation;
}

Animation* SpriteManager::getCitizenFemaleRunDownAnimation()
{
    return citizenFemaleRunDownAnimation;
}

Animation* SpriteManager::getCitizenFemaleRunLeftAnimation()
{
    return citizenFemaleRunLeftAnimation;
}

Animation* SpriteManager::getCitizenFemaleRunRightAnimation()
{
    return citizenFemaleRunRightAnimation;
}

Animation* SpriteManager::getWolfIdleUpAnimation()
{
    return wolfIdleUpAnimation;
}

Animation* SpriteManager::getWolfIdleDownAnimation()
{
    return wolfIdleDownAnimation;
}

Animation* SpriteManager::getWolfIdleLeftAnimation()
{
    return wolfIdleLeftAnimation;
}

Animation* SpriteManager::getWolfIdleRightAnimation()
{
    return wolfIdleRightAnimation;
}

Animation* SpriteManager::getWolfWalkUpAnimation()
{
    return wolfWalkUpAnimation;
}

Animation* SpriteManager::getWolfWalkDownAnimation()
{
    return wolfWalkDownAnimation;
}

Animation* SpriteManager::getWolfWalkLeftAnimation()
{
    return wolfWalkLeftAnimation;
}

Animation* SpriteManager::getWolfWalkRightAnimation()
{
    return wolfWalkRightAnimation;
}

Animation* SpriteManager::getWolfRunUpAnimation()
{
    return wolfRunUpAnimation;
}

Animation* SpriteManager::getWolfRunDownAnimation()
{
    return wolfRunDownAnimation;
}

Animation* SpriteManager::getWolfRunLeftAnimation()
{
    return wolfRunLeftAnimation;
}

Animation* SpriteManager::getWolfRunRightAnimation()
{
    return wolfRunRightAnimation;
}

Animation* SpriteManager::getSnakeIdleLeftAnimation()
{
    return snakeIdleLeftAnimation;
}

Animation* SpriteManager::getSnakeIdleRightAnimation()
{
    return snakeIdleRightAnimation;
}

Animation* SpriteManager::getSnakeWalkUpAnimation()
{
    return snakeWalkUpAnimation;
}

Animation* SpriteManager::getSnakeWalkDownAnimation()
{
    return snakeWalkDownAnimation;
}

Animation* SpriteManager::getSnakeWalkLeftAnimation()
{
    return snakeWalkLeftAnimation;
}

Animation* SpriteManager::getSnakeWalkRightAnimation()
{
    return snakeWalkRightAnimation;
}