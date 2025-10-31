#include "../../include/graphics/Playhead.hpp"
#include "../../include/core/Handler.hpp"

Playhead::Playhead(Handler& handler, Animation* animation, graphics::AnimationMode animationMode)
: handler(handler),
animation(animation),
animationMode(animationMode),
frameDurationMicroseconds(animation->getDefaultFrameDurationMicroseconds()),
totalDurationMicroseconds(animation->getTextureRectangleSequence().size() * animation->getDefaultFrameDurationMicroseconds())
{
}

void Playhead::updateLogic()
{
    if(animation == nullptr || isFinished) return;

    elapsedTimeMicroseconds += constants::microsecondsPerTick;

    if(animationMode == graphics::AnimationMode::Shared)
    {
        elapsedTimeMicroseconds = std::fmod(elapsedTimeMicroseconds, totalDurationMicroseconds);
        if (elapsedTimeMicroseconds < 0.0) elapsedTimeMicroseconds += totalDurationMicroseconds;

        index = static_cast<std::size_t>(elapsedTimeMicroseconds / frameDurationMicroseconds);
    }
    else
    {
        if(elapsedTimeMicroseconds >= totalDurationMicroseconds)
        {
            elapsedTimeMicroseconds = totalDurationMicroseconds;
            index = animation->getTextureRectangleSequence().size() - 1;
            isFinished = true;
        }
        else
        {
            index = static_cast<std::size_t>(elapsedTimeMicroseconds / frameDurationMicroseconds);
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

bool Playhead::getIsFinished() const
{
    return isFinished;
}