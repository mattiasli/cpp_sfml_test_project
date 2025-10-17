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

    capedWarriorIdleUpAnimation = new Animation(handler, spriteAtlas, {{4 * constants::defaultSpriteWidth, 7 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                       {5 * constants::defaultSpriteWidth, 7 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                       {6 * constants::defaultSpriteWidth, 7 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                       {7 * constants::defaultSpriteWidth, 7 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 500000.0);
    animationVector.push_back(capedWarriorIdleUpAnimation);

    capedWarriorIdleDownAnimation = new Animation(handler, spriteAtlas, {{4 * constants::defaultSpriteWidth, 6 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                         {5 * constants::defaultSpriteWidth, 6 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                         {6 * constants::defaultSpriteWidth, 6 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                         {7 * constants::defaultSpriteWidth, 6 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 500000.0);
    animationVector.push_back(capedWarriorIdleDownAnimation);

    capedWarriorIdleLeftAnimation = new Animation(handler, spriteAtlas, {{4 * constants::defaultSpriteWidth, 5 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                         {5 * constants::defaultSpriteWidth, 5 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                         {6 * constants::defaultSpriteWidth, 5 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                         {7 * constants::defaultSpriteWidth, 5 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 500000.0);
    animationVector.push_back(capedWarriorIdleLeftAnimation);

    capedWarriorIdleRightAnimation = new Animation(handler, spriteAtlas, {{4 * constants::defaultSpriteWidth, 4 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                          {5 * constants::defaultSpriteWidth, 4 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                          {6 * constants::defaultSpriteWidth, 4 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                          {7 * constants::defaultSpriteWidth, 4 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 500000.0);
    animationVector.push_back(capedWarriorIdleRightAnimation);

    capedWarriorRunUpAnimation = new Animation(handler, spriteAtlas, {{4 * constants::defaultSpriteWidth, 11 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                      {5 * constants::defaultSpriteWidth, 11 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                      {6 * constants::defaultSpriteWidth, 11 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                      {7 * constants::defaultSpriteWidth, 11 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 125000.0);
    animationVector.push_back(capedWarriorRunUpAnimation);

    capedWarriorRunDownAnimation = new Animation(handler, spriteAtlas, {{4 * constants::defaultSpriteWidth, 10 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                        {5 * constants::defaultSpriteWidth, 10 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                        {6 * constants::defaultSpriteWidth, 10 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                        {7 * constants::defaultSpriteWidth, 10 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 125000.0);
    animationVector.push_back(capedWarriorRunDownAnimation);

    capedWarriorRunLeftAnimation = new Animation(handler, spriteAtlas, {{4 * constants::defaultSpriteWidth, 9 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                        {5 * constants::defaultSpriteWidth, 9 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                        {6 * constants::defaultSpriteWidth, 9 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                        {7 * constants::defaultSpriteWidth, 9 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 125000.0);
    animationVector.push_back(capedWarriorRunLeftAnimation);

    capedWarriorRunRightAnimation = new Animation(handler, spriteAtlas, {{4 * constants::defaultSpriteWidth, 8 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                         {5 * constants::defaultSpriteWidth, 8 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                         {6 * constants::defaultSpriteWidth, 8 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                         {7 * constants::defaultSpriteWidth, 8 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 125000.0);
    animationVector.push_back(capedWarriorRunRightAnimation);

    wolfIdleUpAnimation = new Animation(handler, spriteAtlas, {{8 * constants::defaultSpriteWidth, 7 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                               {9 * constants::defaultSpriteWidth, 7 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                               {10 * constants::defaultSpriteWidth, 7 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                               {11 * constants::defaultSpriteWidth, 7 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 500000.0);
    animationVector.push_back(wolfIdleUpAnimation);

    wolfIdleDownAnimation = new Animation(handler, spriteAtlas, {{8 * constants::defaultSpriteWidth, 6 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                 {9 * constants::defaultSpriteWidth, 6 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                 {10 * constants::defaultSpriteWidth, 6 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                 {11 * constants::defaultSpriteWidth, 6 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 500000.0);
    animationVector.push_back(wolfIdleDownAnimation);

    wolfIdleLeftAnimation = new Animation(handler, spriteAtlas, {{8 * constants::defaultSpriteWidth, 5 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                 {9 * constants::defaultSpriteWidth, 5 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                 {10 * constants::defaultSpriteWidth, 5 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                 {11 * constants::defaultSpriteWidth, 5 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 500000.0);
    animationVector.push_back(wolfIdleLeftAnimation);

    wolfIdleRightAnimation = new Animation(handler, spriteAtlas, {{8 * constants::defaultSpriteWidth, 4 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                  {9 * constants::defaultSpriteWidth, 4 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                  {10 * constants::defaultSpriteWidth, 4 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                  {11 * constants::defaultSpriteWidth, 4 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 500000.0);
    animationVector.push_back(wolfIdleRightAnimation);

    wolfRunUpAnimation = new Animation(handler, spriteAtlas, {{8 * constants::defaultSpriteWidth, 11 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                              {9 * constants::defaultSpriteWidth, 11 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                              {10 * constants::defaultSpriteWidth, 11 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                              {11 * constants::defaultSpriteWidth, 11 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 125000.0);
    animationVector.push_back(wolfRunUpAnimation);

    wolfRunDownAnimation = new Animation(handler, spriteAtlas, {{8 * constants::defaultSpriteWidth, 10 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                {9 * constants::defaultSpriteWidth, 10 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                {10 * constants::defaultSpriteWidth, 10 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                {11 * constants::defaultSpriteWidth, 10 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 125000.0);
    animationVector.push_back(wolfRunDownAnimation);

    wolfRunLeftAnimation = new Animation(handler, spriteAtlas, {{8 * constants::defaultSpriteWidth, 9 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                {9 * constants::defaultSpriteWidth, 9 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                {10 * constants::defaultSpriteWidth, 9 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                {11 * constants::defaultSpriteWidth, 9 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 125000.0);
    animationVector.push_back(wolfRunLeftAnimation);

    wolfRunRightAnimation = new Animation(handler, spriteAtlas, {{8 * constants::defaultSpriteWidth, 8 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                 {9 * constants::defaultSpriteWidth, 8 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                 {10 * constants::defaultSpriteWidth, 8 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight},
                                                                 {11 * constants::defaultSpriteWidth, 8 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight}}, 125000.0);
    animationVector.push_back(wolfRunRightAnimation);

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