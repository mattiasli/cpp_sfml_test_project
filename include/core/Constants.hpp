#pragma once
#include <cmath>
#include <cstdint>

namespace constants {
    enum class EntityType : std::uint8_t {CapedWarrior, GuardSwordsman, GuardSpearman, CitizenMale, CitizenFemale, Wolf, Snake};
    enum class EntityState : std::uint8_t {Idle, Walk, Run, Attack};
    enum class Direction : std::uint8_t {Up, Down, Left, Right};

    inline constexpr int windowWidth  = 1920;
    inline constexpr int windowHeight = 1080;
    inline constexpr double microsecondsPerTick = 1000000.0 / 60.0;

    inline constexpr int scale = 4;
    inline constexpr int tileWidth = 16;
    inline constexpr int tileHeight = 16;
    inline constexpr int defaultSpriteWidth = 16;
    inline constexpr int defaultSpriteHeight = 16;

    inline const sf::Vector2f zeroVector {0, 0};
    inline const sf::IntRect zeroRectangle {0, 0, 0, 0};
    inline const float sin45 {std::sin(45)};
    inline const sf::Vector2i invalidCoordinate {-1, -1};
    inline const size_t invalidIndex = -1;

    inline constexpr float defaultArriveRadius = 0.75f;
    inline constexpr float defaultMaxMovementSpeed = 1.25f;
}