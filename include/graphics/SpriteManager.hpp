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
    Animation* getGuardSwordsmanWalkUpAnimation();
    Animation* getGuardSwordsmanWalkDownAnimation();
    Animation* getGuardSwordsmanWalkLeftAnimation();
    Animation* getGuardSwordsmanWalkRightAnimation();
    Animation* getGuardSwordsmanRunUpAnimation();
    Animation* getGuardSwordsmanRunDownAnimation();
    Animation* getGuardSwordsmanRunLeftAnimation();
    Animation* getGuardSwordsmanRunRightAnimation();

    Animation* getCitizenMaleIdleUpAnimation();
    Animation* getCitizenMaleIdleDownAnimation();
    Animation* getCitizenMaleIdleLeftAnimation();
    Animation* getCitizenMaleIdleRightAnimation();
    Animation* getCitizenMaleWalkUpAnimation();
    Animation* getCitizenMaleWalkDownAnimation();
    Animation* getCitizenMaleWalkLeftAnimation();
    Animation* getCitizenMaleWalkRightAnimation();
    Animation* getCitizenMaleRunUpAnimation();
    Animation* getCitizenMaleRunDownAnimation();
    Animation* getCitizenMaleRunLeftAnimation();
    Animation* getCitizenMaleRunRightAnimation();

    Animation* getCitizenFemaleIdleUpAnimation();
    Animation* getCitizenFemaleIdleDownAnimation();
    Animation* getCitizenFemaleIdleLeftAnimation();
    Animation* getCitizenFemaleIdleRightAnimation();
    Animation* getCitizenFemaleWalkUpAnimation();
    Animation* getCitizenFemaleWalkDownAnimation();
    Animation* getCitizenFemaleWalkLeftAnimation();
    Animation* getCitizenFemaleWalkRightAnimation();
    Animation* getCitizenFemaleRunUpAnimation();
    Animation* getCitizenFemaleRunDownAnimation();
    Animation* getCitizenFemaleRunLeftAnimation();
    Animation* getCitizenFemaleRunRightAnimation();

    Animation* getWolfIdleUpAnimation();
    Animation* getWolfIdleDownAnimation();
    Animation* getWolfIdleLeftAnimation();
    Animation* getWolfIdleRightAnimation();
    Animation* getWolfWalkUpAnimation();
    Animation* getWolfWalkDownAnimation();
    Animation* getWolfWalkLeftAnimation();
    Animation* getWolfWalkRightAnimation();
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
    Animation *guardSwordsmanWalkUpAnimation;
    Animation *guardSwordsmanWalkDownAnimation;
    Animation *guardSwordsmanWalkLeftAnimation;
    Animation *guardSwordsmanWalkRightAnimation;
    Animation *guardSwordsmanRunUpAnimation;
    Animation *guardSwordsmanRunDownAnimation;
    Animation *guardSwordsmanRunLeftAnimation;
    Animation *guardSwordsmanRunRightAnimation;

    Animation *citizenMaleIdleUpAnimation;
    Animation *citizenMaleIdleDownAnimation;
    Animation *citizenMaleIdleLeftAnimation;
    Animation *citizenMaleIdleRightAnimation;
    Animation *citizenMaleWalkUpAnimation;
    Animation *citizenMaleWalkDownAnimation;
    Animation *citizenMaleWalkLeftAnimation;
    Animation *citizenMaleWalkRightAnimation;
    Animation *citizenMaleRunUpAnimation;
    Animation *citizenMaleRunDownAnimation;
    Animation *citizenMaleRunLeftAnimation;
    Animation *citizenMaleRunRightAnimation;

    Animation *citizenFemaleIdleUpAnimation;
    Animation *citizenFemaleIdleDownAnimation;
    Animation *citizenFemaleIdleLeftAnimation;
    Animation *citizenFemaleIdleRightAnimation;
    Animation *citizenFemaleWalkUpAnimation;
    Animation *citizenFemaleWalkDownAnimation;
    Animation *citizenFemaleWalkLeftAnimation;
    Animation *citizenFemaleWalkRightAnimation;
    Animation *citizenFemaleRunUpAnimation;
    Animation *citizenFemaleRunDownAnimation;
    Animation *citizenFemaleRunLeftAnimation;
    Animation *citizenFemaleRunRightAnimation;

    Animation *wolfIdleUpAnimation;
    Animation *wolfIdleDownAnimation;
    Animation *wolfIdleLeftAnimation;
    Animation *wolfIdleRightAnimation;
    Animation *wolfWalkUpAnimation;
    Animation *wolfWalkDownAnimation;
    Animation *wolfWalkLeftAnimation;
    Animation *wolfWalkRightAnimation;
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