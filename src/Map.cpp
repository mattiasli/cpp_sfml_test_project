#include "../include/Map.hpp"
#include "../include/Handler.hpp"

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
    for(std::size_t y = 0; y < mapGrid.size() ; y++)
    {
        for(std::size_t x = 0; x < mapGrid[y].size() ; x++)
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

