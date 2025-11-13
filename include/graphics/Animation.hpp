#pragma once
#include <SFML/Graphics.hpp>

class Handler;

class Animation {
public:
    Animation(Handler& handler, sf::Texture& spriteAtlas, std::vector<sf::IntRect> textureRectangleSequence, sf::Vector2i offsetPixelPoint, double defaultFrameDurationMicroseconds);
    Animation(Handler& handler, sf::Texture& spriteAtlas, std::vector<sf::IntRect> textureRectangleSequence, double defaultFrameDurationMicroseconds);

    sf::Texture& getSpriteAtlas() const;
    const std::vector<sf::IntRect>& getTextureRectangleSequence() const;
    const sf::Vector2i& getOffsetPixelPoint() const;
    double getDefaultFrameDurationMicroseconds() const;

private:
    Handler& handler;
    sf::Texture& spriteAtlas;
    std::vector<sf::IntRect> textureRectangleSequence;
    sf::Vector2i offsetPixelPoint;
    double defaultFrameDurationMicroseconds;
};