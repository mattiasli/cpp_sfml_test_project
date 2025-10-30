#include "../../include/graphics/Animation.hpp"
#include "../../include/core/Handler.hpp"
#include <vector>

Animation::Animation(Handler& handler, sf::Texture& spriteAtlas, std::vector<sf::IntRect> textureRectangleSequence, double defaultFrameDurationMicroseconds)
: handler(handler),
spriteAtlas(spriteAtlas),
textureRectangleSequence(std::move(textureRectangleSequence)),
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

double Animation::getDefaultFrameDurationMicroseconds() const
{
    return defaultFrameDurationMicroseconds;
}