#include "../../include/graphics/Animation.hpp"
#include "../../include/core/Handler.hpp"
#include <vector>

Animation::Animation(Handler& handler, sf::Texture& spriteAtlas, std::vector<sf::IntRect> textureRectangleSequence, double frameDurationMicroseconds)
: handler(handler),
spriteAtlas(spriteAtlas),
textureRectangleSequence(std::move(textureRectangleSequence)),
frameDurationMicroseconds(frameDurationMicroseconds),
totalDurationMicroseconds(this->textureRectangleSequence.size() * frameDurationMicroseconds)
{
    sprite.setTexture(this->spriteAtlas);
    sprite.setTextureRect(this->textureRectangleSequence[0]);
    sprite.setScale(constants::scale, constants::scale);
}

void Animation::updateLogic()
{
    deltaTimeMicroseconds += constants::microsecondsPerTick;
    deltaTimeMicroseconds = std::fmod(deltaTimeMicroseconds, totalDurationMicroseconds);
    if (deltaTimeMicroseconds < 0.0)
    {
        deltaTimeMicroseconds += totalDurationMicroseconds;
    }

    std::size_t index = static_cast<std::size_t>(std::floor(deltaTimeMicroseconds / frameDurationMicroseconds));

    if(index >= static_cast<std::size_t>(textureRectangleSequence.size()))
    {
        index = static_cast<std::size_t>(textureRectangleSequence.size()) - 1;
    }

    sprite.setTextureRect(textureRectangleSequence[index]);
}

sf::Sprite* Animation::getSprite()
{
    return &sprite;
}