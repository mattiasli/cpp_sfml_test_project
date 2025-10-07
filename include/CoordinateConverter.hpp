#pragma once
#include <SFML/Graphics.hpp>

class Handler;

class CoordinateConverter {
public:
    CoordinateConverter(Handler& handler);

    int convertTo1DIndex(sf::Vector2i twoDGridCoordinate) const;

    sf::Vector2i convertTo2DGridCoordinate(int oneDIndex) const;

    sf::Vector2f convertToWorldCoordinate(sf::Vector2i gridCoordinate) const;

    sf::Vector2i convertToGridCoordinate(sf::Vector2f worldCoordinate) const;

    float convertToXWorldCoordinate(int xGridCoordinate) const;

    float convertToYWorldCoordinate(int yGridCoordinate) const;

    int convertToXGridCoordinate(float xWorldCoordinate) const;

    int convertToYGridCoordinate(float yWorldCoordinate) const;

private:
    Handler& handler;
};