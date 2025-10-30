#pragma once
#include <SFML/Graphics.hpp>

class Handler;

class Animation {
public:
    Animation(Handler& handler, sf::Texture& spriteAtlas, std::vector<sf::IntRect> textureRectangleSequence, double defaultFrameDurationMicroseconds);

    sf::Texture& getSpriteAtlas() const;
    const std::vector<sf::IntRect>& getTextureRectangleSequence() const;
    double getDefaultFrameDurationMicroseconds() const;

private:
    Handler& handler;
    sf::Texture& spriteAtlas;
    std::vector<sf::IntRect> textureRectangleSequence;
    double defaultFrameDurationMicroseconds;
};