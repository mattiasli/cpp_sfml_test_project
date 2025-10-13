#pragma once

namespace constants {
    inline constexpr int windowWidth  = 1920;
    inline constexpr int windowHeight = 1080;
    inline constexpr double timePerTick = 1000000.0 / 60.0;

    inline constexpr int scale = 4;
    inline constexpr int tileWidth = 16;
    inline constexpr int tileHeight = 16;
    inline constexpr int defaultSpriteWidth = 16;
    inline constexpr int defaulSpriteHeight = 16;

    inline const sf::Vector2f zeroVector {0, 0};
    inline const sf::Vector2i invalidCoordinate {-1, -1};
    inline const size_t invalidIndex = -1;

    inline constexpr float defaultArriveRadius = 1.5f;
}