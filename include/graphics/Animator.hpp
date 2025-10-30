#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Playhead.hpp"

class Handler;

class Animator {
public:
    Animator(Handler& handler, Animation* animation);

    void updateLogic();
    sf::Sprite* getSprite();

private:
    Handler& handler;
    Playhead playhead;
    sf::Sprite sprite;
};