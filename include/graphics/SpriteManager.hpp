#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.hpp"

class Handler;

class SpriteManager {
public:
    SpriteManager(Handler& handler);

    void updateLogic();

    sf::Sprite* getDirtSprite();
    sf::Sprite* getGrassSprite();
    sf::Sprite* getBoulderSprite();
    sf::Sprite* getGroveSprite();
    sf::Sprite* getWaterSprite();

    Animation* getCapedWarriorIdleUpAnimation();
    Animation* getCapedWarriorIdleDownAnimation();
    Animation* getCapedWarriorIdleLeftAnimation();
    Animation* getCapedWarriorIdleRightAnimation();
    Animation* getCapedWarriorRunUpAnimation();
    Animation* getCapedWarriorRunDownAnimation();
    Animation* getCapedWarriorRunLeftAnimation();
    Animation* getCapedWarriorRunRightAnimation();

    Animation* getWolfIdleUpAnimation();
    Animation* getWolfIdleDownAnimation();
    Animation* getWolfIdleLeftAnimation();
    Animation* getWolfIdleRightAnimation();
    Animation* getWolfRunUpAnimation();
    Animation* getWolfRunDownAnimation();
    Animation* getWolfRunLeftAnimation();
    Animation* getWolfRunRightAnimation();

    Animation* getSnakeIdleLeftAnimation();
    Animation* getSnakeIdleRightAnimation();
    Animation* getSnakeWalkUpAnimation();
    Animation* getSnakeWalkDownAnimation();
    Animation* getSnakeWalkLeftAnimation();
    Animation* getSnakeWalkRightAnimation();

private:
    Handler& handler;

    sf::Texture spriteAtlas;

    sf::Sprite dirtSprite;
    sf::Sprite grassSprite;
    sf::Sprite boulderSprite;
    sf::Sprite groveSprite;
    sf::Sprite waterSprite;

    std::vector<Animation*> animationVector;

    Animation *capedWarriorIdleUpAnimation, *capedWarriorIdleDownAnimation, *capedWarriorIdleLeftAnimation, *capedWarriorIdleRightAnimation;
    Animation *capedWarriorRunUpAnimation, *capedWarriorRunDownAnimation, *capedWarriorRunLeftAnimation, *capedWarriorRunRightAnimation;

    Animation *wolfIdleUpAnimation, *wolfIdleDownAnimation, *wolfIdleLeftAnimation, *wolfIdleRightAnimation;
    Animation *wolfRunUpAnimation, *wolfRunDownAnimation, *wolfRunLeftAnimation, *wolfRunRightAnimation;

    Animation *snakeIdleLeftAnimation, *snakeIdleRightAnimation;
    Animation *snakeWalkUpAnimation, *snakeWalkDownAnimation, *snakeWalkLeftAnimation, *snakeWalkRightAnimation;
};