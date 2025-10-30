#include "../../include/graphics/Playhead.hpp"
#include "../../include/core/Handler.hpp"

Playhead::Playhead(Handler& handler, Animation* animation)
: handler(handler),
animation(animation),
totalDurationMicroseconds(animation->getTextureRectangleSequence().size() * animation->getDefaultFrameDurationMicroseconds())
{
}

void Playhead::updateLogic()
{
    if(animation != nullptr)
    {
        deltaTimeMicroseconds += constants::microsecondsPerTick;
        deltaTimeMicroseconds = std::fmod(deltaTimeMicroseconds, totalDurationMicroseconds);
        if (deltaTimeMicroseconds < 0.0)
        {
            deltaTimeMicroseconds += totalDurationMicroseconds;
        }
        index = static_cast<std::size_t>(std::floor(deltaTimeMicroseconds / animation->getDefaultFrameDurationMicroseconds()));
        if(index >= static_cast<std::size_t>(animation->getTextureRectangleSequence().size()))
        {
            index = static_cast<std::size_t>(animation->getTextureRectangleSequence().size()) - 1;
        }
    }
}

const sf::IntRect& Playhead::getTextureRectangle() const
{
    if(animation != nullptr)
    {
        return animation->getTextureRectangleSequence()[index];
    }
    else
    {
        return constants::zeroRectangle;
    }
}