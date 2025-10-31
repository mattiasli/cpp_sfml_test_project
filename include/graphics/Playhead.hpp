#pragma once
#include <SFML/Graphics.hpp>
#include "../core/constants.hpp"
#include "Animation.hpp"
#include "graphics.hpp"

class Handler;

class Playhead {
public:
    Playhead(Handler& handler, Animation* animation, graphics::AnimationMode animationMode = graphics::AnimationMode::Shared);

    void updateLogic();
    const sf::IntRect& getTextureRectangle() const;
    bool getIsFinished() const;

private:

    Handler& handler;
    Animation* animation = nullptr;
    graphics::AnimationMode animationMode = graphics::AnimationMode::Shared;
    double frameDurationMicroseconds = 0;
    double totalDurationMicroseconds = 0;
    double elapsedTimeMicroseconds = 0;
    std::size_t index = 0;
    bool isFinished = false;
};