#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include <cstdint>

class Handler;

class SpriteManager {
public:
    SpriteManager(Handler& handler);

    void updateLogic();

    std::vector<sf::IntRect> computeTextureRectangleSequence(sf::Vector2i startTexureGridIndex, sf::Vector2i rectangleTextureGridSize, std::uint8_t seqenceLength);

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

    Animation* getGuardSwordsmanIdleUpAnimation();
    Animation* getGuardSwordsmanIdleDownAnimation();
    Animation* getGuardSwordsmanIdleLeftAnimation();
    Animation* getGuardSwordsmanIdleRightAnimation();
    Animation* getGuardSwordsmanRunUpAnimation();
    Animation* getGuardSwordsmanRunDownAnimation();
    Animation* getGuardSwordsmanRunLeftAnimation();
    Animation* getGuardSwordsmanRunRightAnimation();

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

    Animation *capedWarriorIdleUpAnimation;
    Animation *capedWarriorIdleDownAnimation;
    Animation *capedWarriorIdleLeftAnimation;
    Animation *capedWarriorIdleRightAnimation;
    Animation *capedWarriorRunUpAnimation;
    Animation *capedWarriorRunDownAnimation;
    Animation *capedWarriorRunLeftAnimation;
    Animation *capedWarriorRunRightAnimation;

    Animation *guardSwordsmanIdleUpAnimation;
    Animation *guardSwordsmanIdleDownAnimation;
    Animation *guardSwordsmanIdleLeftAnimation;
    Animation *guardSwordsmanIdleRightAnimation;
    Animation *guardSwordsmanRunUpAnimation;
    Animation *guardSwordsmanRunDownAnimation;
    Animation *guardSwordsmanRunLeftAnimation;
    Animation *guardSwordsmanRunRightAnimation;

    Animation *wolfIdleUpAnimation;
    Animation *wolfIdleDownAnimation;
    Animation *wolfIdleLeftAnimation;
    Animation *wolfIdleRightAnimation;
    Animation *wolfRunUpAnimation;
    Animation *wolfRunDownAnimation;
    Animation *wolfRunLeftAnimation;
    Animation *wolfRunRightAnimation;

    Animation *snakeIdleLeftAnimation;
    Animation *snakeIdleRightAnimation;
    Animation *snakeWalkUpAnimation;
    Animation *snakeWalkDownAnimation;
    Animation *snakeWalkLeftAnimation;
    Animation *snakeWalkRightAnimation;
};