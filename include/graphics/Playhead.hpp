#pragma once
#include <SFML/Graphics.hpp>
#include "../core/constants.hpp"
#include "Animation.hpp"

class Handler;

class Playhead {
public:
    Playhead(Handler& handler, Animation* animation);

    void updateLogic();
    const sf::IntRect& getTextureRectangle() const;

private:

    Handler& handler;
    Animation* animation = nullptr;
    double totalDurationMicroseconds = 0;
    double deltaTimeMicroseconds = 0;
    std::size_t index = 0;
};