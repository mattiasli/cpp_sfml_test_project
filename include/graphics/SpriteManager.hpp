#pragma once
#include <SFML/Graphics.hpp>

class Handler;

class SpriteManager {
public:
    SpriteManager(Handler& handler);

    sf::Sprite* getSnakeSprite();
    sf::Sprite* getPlayerSprite();
    sf::Sprite* getDirtSprite();
    sf::Sprite* getGrassSprite();
    sf::Sprite* getBoulderSprite();
    sf::Sprite* getGroveSprite();
    sf::Sprite* getWaterSprite();

private:
    Handler& handler;

    sf::Texture spriteAtlas;

    sf::Sprite snakeSprite;
    sf::Sprite playerSprite;
    sf::Sprite dirtSprite;
    sf::Sprite grassSprite;
    sf::Sprite boulderSprite;
    sf::Sprite groveSprite;
    sf::Sprite waterSprite;
};