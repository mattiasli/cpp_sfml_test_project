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
    animationVector.push_back(capedWarriorIdleUpAnimation);

    capedWarriorIdleDownAnimation = new Animation(handler, spriteAtlas,  computeTextureRectangleSequence({4, 6}, {1, 1}, 4), 500000.0);
    animationVector.push_back(capedWarriorIdleDownAnimation);

    capedWarriorIdleLeftAnimation = new Animation(handler, spriteAtlas,  computeTextureRectangleSequence({4, 5}, {1, 1}, 4), 500000.0);
    animationVector.push_back(capedWarriorIdleLeftAnimation);

    capedWarriorIdleRightAnimation = new Animation(handler, spriteAtlas,  computeTextureRectangleSequence({4, 4}, {1, 1}, 4), 500000.0);
    animationVector.push_back(capedWarriorIdleRightAnimation);

    capedWarriorRunUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({4, 11}, {1, 1}, 4), 125000.0);
    animationVector.push_back(capedWarriorRunUpAnimation);

    capedWarriorRunDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({4, 10}, {1, 1}, 4), 125000.0);
    animationVector.push_back(capedWarriorRunDownAnimation);

    capedWarriorRunLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({4, 9}, {1, 1}, 4), 125000.0);
    animationVector.push_back(capedWarriorRunLeftAnimation);

    capedWarriorRunRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({4, 8}, {1, 1}, 4), 125000.0);
    animationVector.push_back(capedWarriorRunRightAnimation);

    guardSwordsmanIdleUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 7}, {1, 1}, 4), 500000.0);
    animationVector.push_back(guardSwordsmanIdleUpAnimation);

    guardSwordsmanIdleDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 6}, {1, 1}, 4), 500000.0);
    animationVector.push_back(guardSwordsmanIdleDownAnimation);

    guardSwordsmanIdleLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 5}, {1, 1}, 4), 500000.0);
    animationVector.push_back(guardSwordsmanIdleLeftAnimation);

    guardSwordsmanIdleRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 4}, {1, 1}, 4), 500000.0);
    animationVector.push_back(guardSwordsmanIdleRightAnimation);

    guardSwordsmanRunUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 11}, {1, 1}, 4), 125000.0);
    animationVector.push_back(guardSwordsmanRunUpAnimation);

    guardSwordsmanRunDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 10}, {1, 1}, 4), 125000.0);
    animationVector.push_back(guardSwordsmanRunDownAnimation);

    guardSwordsmanRunLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 9}, {1, 1}, 4), 125000.0);
    animationVector.push_back(guardSwordsmanRunLeftAnimation);

    guardSwordsmanRunRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 8}, {1, 1}, 4), 125000.0);
    animationVector.push_back(guardSwordsmanRunRightAnimation);

    wolfIdleUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 7}, {1, 1}, 4), 500000.0);
    animationVector.push_back(wolfIdleUpAnimation);

    wolfIdleDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 6}, {1, 1}, 4), 500000.0);
    animationVector.push_back(wolfIdleDownAnimation);

    wolfIdleLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 5}, {1, 1}, 4), 500000.0);
    animationVector.push_back(wolfIdleLeftAnimation);

    wolfIdleRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 4}, {1, 1}, 4), 500000.0);
    animationVector.push_back(wolfIdleRightAnimation);

    wolfRunUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 11}, {1, 1}, 4), 125000.0);
    animationVector.push_back(wolfRunUpAnimation);

    wolfRunDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 10}, {1, 1}, 4), 125000.0);
    animationVector.push_back(wolfRunDownAnimation);

    wolfRunLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 9}, {1, 1}, 4), 125000.0);
    animationVector.push_back(wolfRunLeftAnimation);

    wolfRunRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 8}, {1, 1}, 4), 125000.0);
    animationVector.push_back(wolfRunRightAnimation);

    snakeIdleLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 5}, {1, 1}, 4), 500000.0);
    animationVector.push_back(snakeIdleLeftAnimation);

    snakeIdleRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 4}, {1, 1}, 4), 500000.0);
    animationVector.push_back(snakeIdleRightAnimation);

    snakeWalkUpAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 9}, {1, 1}, 4), 250000.0);
    animationVector.push_back(snakeWalkUpAnimation);

    snakeWalkDownAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 8}, {1, 1}, 4), 250000.0);
    animationVector.push_back(snakeWalkDownAnimation);

    snakeWalkLeftAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 7}, {1, 1}, 4), 250000.0);
    animationVector.push_back(snakeWalkLeftAnimation);

    snakeWalkRightAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 6}, {1, 1}, 4), 250000.0);
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