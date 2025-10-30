#include "../../include/graphics/Animator.hpp"
#include "../../include/core/Handler.hpp"

Animator::Animator(Handler& handler, Animation* animation)
: handler(handler),
playhead(handler, animation)
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

sf::Sprite* Animator::getSprite()
{
    return &sprite;
}