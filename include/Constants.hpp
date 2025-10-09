#pragma once

namespace constants {
    constexpr int windowWidth  = 1920;
    constexpr int windowHeight = 1080;
    constexpr double timePerTick = 1000000.0 / 60.0;

    constexpr int scale = 4;
    constexpr int tileWidth = 16;
    constexpr int tileHeight = 16;
    constexpr int defaultSpriteWidth = 16;
    constexpr int defaulSpriteHeight = 16;

    inline const sf::Vector2f zeroVector {0, 0};
    inline const sf::Vector2i invalidCoordinate {-1, -1};
}