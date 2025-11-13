#include "../../include/graphics/Animation.hpp"
#include "../../include/core/Handler.hpp"
#include <vector>

Animation::Animation(Handler& handler, sf::Texture& spriteAtlas, std::vector<sf::IntRect> textureRectangleSequence, sf::Vector2i offsetPixelPoint, double defaultFrameDurationMicroseconds)
: handler(handler),
spriteAtlas(spriteAtlas),
textureRectangleSequence(std::move(textureRectangleSequence)),
offsetPixelPoint(offsetPixelPoint),
defaultFrameDurationMicroseconds(defaultFrameDurationMicroseconds)
{
}

Animation::Animation(Handler& handler, sf::Texture& spriteAtlas, std::vector<sf::IntRect> textureRectangleSequence, double defaultFrameDurationMicroseconds)
: handler(handler),
spriteAtlas(spriteAtlas),
textureRectangleSequence(std::move(textureRectangleSequence)),
offsetPixelPoint(constants::zeroVectorI),
defaultFrameDurationMicroseconds(defaultFrameDurationMicroseconds)
{
}

sf::Texture& Animation::getSpriteAtlas() const
{
    return spriteAtlas;
}

const std::vector<sf::IntRect>& Animation::getTextureRectangleSequence() const
{
    return textureRectangleSequence;
}

const sf::Vector2i& Animation::getOffsetPixelPoint() const
{
    return offsetPixelPoint;
}

double Animation::getDefaultFrameDurationMicroseconds() const
{
    return defaultFrameDurationMicroseconds;
}