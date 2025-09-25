#include "../include/Map.hpp"
#include "../include/Handler.hpp"

Map::Map(Handler& handler)
: handler(handler)
{
}

void Map::render()
{
    for(int y = 0; y < mapGrid.size() ; y++)
    {
        for(int x = 0; x < mapGrid[y].size() ; x++)
        { 
        sf::RectangleShape rectangle(sf::Vector2f(64.f, 64.f));

        switch(mapGrid[y][x])
        {
            case '#':
            rectangle.setFillColor(sf::Color::Black);
            break;
            case ' ':
            rectangle.setFillColor(sf::Color::Green);
            break;
            case '~':
            rectangle.setFillColor(sf::Color::Blue);
            break;
            default:
            break;
        }

        rectangle.setPosition(x * 64, y *64);
        handler.getRenderWindow().draw(rectangle);
        }
    }
}