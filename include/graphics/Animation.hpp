#pragma once
#include <SFML/Graphics.hpp>

class Handler;

class Animation {
public:
    Animation(Handler& handler, sf::Texture& spriteAtlas, std::vector<sf::IntRect> textureRectangleSequence, double frameDurationMicroseconds);

    void updateLogic();
    sf::Sprite* getSprite();

private:
    Handler& handler;

    sf::Texture& spriteAtlas;
    std::vector<sf::IntRect> textureRectangleSequence;
    double frameDurationMicroseconds;

    double deltaTimeMicroseconds = 0;
    double totalDurationMicroseconds;
    sf::Sprite sprite;
};