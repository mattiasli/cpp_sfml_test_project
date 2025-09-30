#include "../include/CoordinateConverter.hpp"
#include "../include/Handler.hpp"

CoordinateConverter::CoordinateConverter(Handler& handler)
: handler(handler)
{
}

sf::Vector2f CoordinateConverter::getWorldCoordinate(sf::Vector2i gridCoordinate)
{
    return {(float)(gridCoordinate.x * constants::tileWidth * constants::scale),
            (float)(gridCoordinate.y * constants::tileHeight * constants::scale)};
}

sf::Vector2i CoordinateConverter::getGridCoordinate(sf::Vector2f worldCoordinate)
{
    return {(int)worldCoordinate.x / (constants::tileWidth * constants::scale),
    (int)worldCoordinate.y / (constants::tileHeight * constants::scale)};
}