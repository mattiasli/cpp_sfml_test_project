#include "../../include/graphics/SpriteManager.hpp"
#include "../../include/core/Handler.hpp"

SpriteManager::SpriteManager(Handler& handler)
: handler(handler)
{
    spriteAtlas.loadFromFile("../res/spritesheet.png");

    playerSprite.setTexture(spriteAtlas);
    playerSprite.setTextureRect({0 * constants::defaultSpriteWidth, 3 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight});
    playerSprite.setScale(constants::scale , constants::scale);

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

    snakeIdleLeftAnimation = new Animation(handler, spriteAtlas, {{0 * constants::defaultSpriteWidth, 5 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                  {1 * constants::defaultSpriteWidth, 5 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                  {2 * constants::defaultSpriteWidth, 5 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                  {3 * constants::defaultSpriteWidth, 5 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 500000.0);
    animationVector.push_back(snakeIdleLeftAnimation);

    snakeIdleRightAnimation = new Animation(handler, spriteAtlas, {{0 * constants::defaultSpriteWidth, 4 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                   {1 * constants::defaultSpriteWidth, 4 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                   {2 * constants::defaultSpriteWidth, 4 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                   {3 * constants::defaultSpriteWidth, 4 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 500000.0);
    animationVector.push_back(snakeIdleRightAnimation);

    snakeWalkUpAnimation = new Animation(handler, spriteAtlas, {{0 * constants::defaultSpriteWidth, 9 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                {1 * constants::defaultSpriteWidth, 9 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                {2 * constants::defaultSpriteWidth, 9 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                {3 * constants::defaultSpriteWidth, 9 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 250000.0);
    animationVector.push_back(snakeWalkUpAnimation);

    snakeWalkDownAnimation = new Animation(handler, spriteAtlas, {{0 * constants::defaultSpriteWidth, 8 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                  {1 * constants::defaultSpriteWidth, 8 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                  {2 * constants::defaultSpriteWidth, 8 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                  {3 * constants::defaultSpriteWidth, 8 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 250000.0);
    animationVector.push_back(snakeWalkDownAnimation);

    snakeWalkLeftAnimation = new Animation(handler, spriteAtlas, {{0 * constants::defaultSpriteWidth, 7 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                  {1 * constants::defaultSpriteWidth, 7 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                  {2 * constants::defaultSpriteWidth, 7 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                  {3 * constants::defaultSpriteWidth, 7 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 250000.0);
    animationVector.push_back(snakeWalkLeftAnimation);

    snakeWalkRightAnimation = new Animation(handler, spriteAtlas, {{0 * constants::defaultSpriteWidth, 6 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                   {1 * constants::defaultSpriteWidth, 6 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                   {2 * constants::defaultSpriteWidth, 6 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                   {3 * constants::defaultSpriteWidth, 6 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 250000.0);
    animationVector.push_back(snakeWalkRightAnimation);

}

void SpriteManager::updateLogic()
{
    for(Animation* animation : animationVector)
    {
        animation->updateLogic();
    }
}

sf::Sprite* SpriteManager::getPlayerSprite()
{
    return &playerSprite;
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