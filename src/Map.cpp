#include "../include/Map.hpp"
#include "../include/Handler.hpp"
#include <iostream>

Map::Map(Handler& handler)
: handler(handler),
player(handler, handler.getCoordinateConverter().convertToWorldCoordinate({4, 4}))
{
    solidTable['#'] = true; // TODO: update to flyweight algorithm.
    solidTable['~'] = true;
    solidTable['^'] = true;
}

void Map::updateLogic()
{
    player.updateLogic();
}

void Map::render()
{
    sf::Sprite* spritePointer = nullptr;
    for(int y = 0; y < mapGrid.size() ; y++)
    {
        for(int x = 0; x < mapGrid[y].size() ; x++)
        {
            switch(mapGrid[y][x])
            {
                case ' ':
                spritePointer = handler.getSpriteManager().getDirtSprite();
                break;
                case '_':
                spritePointer = handler.getSpriteManager().getGrassSprite();
                break;
                case '#':
                spritePointer = handler.getSpriteManager().getBoulderSprite();
                break;
                case '^':
                spritePointer = handler.getSpriteManager().getGroveSprite();
                break;
                case '~':
                spritePointer = handler.getSpriteManager().getWaterSprite();
                break;
                default:
                break;
            }
            if(spritePointer != nullptr)
            {
                spritePointer->setPosition(x * constants::tileWidth * constants::scale, y * constants::tileWidth * constants::scale);
                handler.getRenderWindowManager().getRenderWindow().draw(*spritePointer);
            }
        }
    }



            if(handler.getEventManager().GetIsMouseLeftButtonDown()) // TODO, remove
            {
            std::cout << "xgrid: " << handler.getCoordinateConverter().convertToXGridCoordinate(handler.getEventManager().GetMousePosition().x)
            << "  ygrid: " << handler.getCoordinateConverter().convertToYGridCoordinate(handler.getEventManager().GetMousePosition().y) << std::endl;


            std::vector<sf::Vector2i> tempv = handler.getPathFinder().aStarPath(handler.getCoordinateConverter().convertToGridCoordinate(player.getWorldCoordinate()),
                                                                                handler.getCoordinateConverter().convertToGridCoordinate((sf::Vector2f)handler.getEventManager().GetMousePosition()));

            for(sf::Vector2i coord : tempv)
            {
                handler.getSpriteManager().getWaterSprite()->setPosition(handler.getCoordinateConverter().convertToWorldCoordinate(coord));
                handler.getSpriteManager().getWaterSprite()->setColor(sf::Color::Magenta);

                handler.getRenderWindowManager().getRenderWindow().draw(*handler.getSpriteManager().getWaterSprite());
                handler.getSpriteManager().getWaterSprite()->setColor(sf::Color::White);
                std::cout << "x: "<< coord.x << "   y: " << coord.y << std::endl;
            }
            }

    player.render();
}

bool Map::isTileSolid(char tile)
{
    return solidTable[(unsigned char)tile];
}

bool Map::isGridCoordinateSolid(sf::Vector2i gridCoordinate)
{
    return isTileSolid(mapGrid[gridCoordinate.y][gridCoordinate.x]);
}

bool Map::isGridCoordinateInsideMapGrid(sf::Vector2i gridCoordinate) const
{
    return gridCoordinate.x >= 0 &&
           gridCoordinate.y >= 0 &&
           gridCoordinate.x < getGridWidth() &&
           gridCoordinate.y < getGridHeight();
}

int Map::getGridWidth() const
{
    return mapGrid.size();
}

int Map::getGridHeight() const
{
    return mapGrid[0].size();
}

