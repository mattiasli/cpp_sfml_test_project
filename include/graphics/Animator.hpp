#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Graphics.hpp"
#include "Playhead.hpp"

class Handler;

class Animator {
public:
    Animator(Handler& handler, Animation* animation, graphics::AnimationMode animationMode = graphics::AnimationMode::Shared);

    void updateLogic();
    const sf::Vector2i& getOffsetPixelPoint() const;
    bool getIsFinished() const;
    sf::Sprite* getSprite();

private:
    Handler& handler;
    Playhead playhead;
    sf::Sprite sprite;
};