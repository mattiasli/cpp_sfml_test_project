#pragma once
#include <SFML/Graphics.hpp>

class Handler;

class CoordinateConverter {
public:
    CoordinateConverter(Handler& handler);

    sf::Vector2f getWorldCoordinate(sf::Vector2i gridCoordinate);

    sf::Vector2i getGridCoordinate(sf::Vector2f worldCoordinate);

private:
    Handler& handler;
};