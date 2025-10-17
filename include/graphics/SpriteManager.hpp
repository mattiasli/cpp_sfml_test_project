#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.hpp"

class Handler;

class SpriteManager {
public:
    SpriteManager(Handler& handler);

    void updateLogic();

    sf::Sprite* getPlayerSprite();
    sf::Sprite* getDirtSprite();
    sf::Sprite* getGrassSprite();
    sf::Sprite* getBoulderSprite();
    sf::Sprite* getGroveSprite();
    sf::Sprite* getWaterSprite();

    Animation* getSnakeIdleLeftAnimation();
    Animation* getSnakeIdleRightAnimation();
    Animation* getSnakeWalkUpAnimation();
    Animation* getSnakeWalkDownAnimation();
    Animation* getSnakeWalkLeftAnimation();
    Animation* getSnakeWalkRightAnimation();

private:
    Handler& handler;

    sf::Texture spriteAtlas;

    sf::Sprite playerSprite;
    sf::Sprite dirtSprite;
    sf::Sprite grassSprite;
    sf::Sprite boulderSprite;
    sf::Sprite groveSprite;
    sf::Sprite waterSprite;

    std::vector<Animation*> animationVector;
    Animation *snakeIdleLeftAnimation, *snakeIdleRightAnimation;
    Animation *snakeWalkUpAnimation, *snakeWalkDownAnimation, *snakeWalkLeftAnimation, *snakeWalkRightAnimation;
};