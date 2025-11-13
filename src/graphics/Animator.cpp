#include "../../include/graphics/Animator.hpp"
#include "../../include/core/Handler.hpp"

Animator::Animator(Handler& handler, Animation* animation, graphics::AnimationMode animationMode)
: handler(handler),
playhead(handler, animation, animationMode)
{
    sprite.setTexture(animation->getSpriteAtlas());
    sprite.setTextureRect(animation->getTextureRectangleSequence()[0]);
    sprite.setScale(constants::scale, constants::scale);
}

void Animator::updateLogic()
{
    playhead.updateLogic();
    sprite.setTextureRect(playhead.getTextureRectangle());
}

const sf::Vector2i& Animator::getOffsetPixelPoint() const
{
    return playhead.getOffsetPixelPoint();
}

bool Animator::getIsFinished() const
{
    return playhead.getIsFinished();
}

sf::Sprite* Animator::getSprite()
{
    return &sprite;
}