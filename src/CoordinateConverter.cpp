#include "../include/CoordinateConverter.hpp"
#include "../include/Handler.hpp"

CoordinateConverter::CoordinateConverter(Handler& handler)
: handler(handler)
{
}

int CoordinateConverter::convertTo1DIndex(sf::Vector2i twoDGridCoordinate) const
{
    return twoDGridCoordinate.x + twoDGridCoordinate.y * handler.getMap().getGridWidth();
}

sf::Vector2i CoordinateConverter::convertTo2DGridCoordinate(int oneDIndex) const
{
    return {oneDIndex % handler.getMap().getGridWidth(), oneDIndex / handler.getMap().getGridWidth()};
}

sf::Vector2f CoordinateConverter::convertToWorldCoordinate(sf::Vector2i gridCoordinate) const
{
    return {(float)(gridCoordinate.x * constants::tileWidth * constants::scale),
            (float)(gridCoordinate.y * constants::tileHeight * constants::scale)};
}

sf::Vector2i CoordinateConverter::convertToGridCoordinate(sf::Vector2f worldCoordinate) const
{
    return {(int)worldCoordinate.x / (constants::tileWidth * constants::scale),
    (int)worldCoordinate.y / (constants::tileHeight * constants::scale)};
}

float CoordinateConverter::convertToXWorldCoordinate(int xGridCoordinate) const
{
    return (float)(xGridCoordinate * constants::tileWidth * constants::scale);
}

float CoordinateConverter::convertToYWorldCoordinate(int yGridCoordinate) const
{
    return (float)(yGridCoordinate * constants::tileHeight * constants::scale);
}

int CoordinateConverter::convertToXGridCoordinate(float xWorldCoordinate) const
{
    return (int)xWorldCoordinate / (constants::tileWidth * constants::scale);
}

int CoordinateConverter::convertToYGridCoordinate(float yWorldCoordinate) const
{
    return (int)yWorldCoordinate / (constants::tileHeight * constants::scale);
}