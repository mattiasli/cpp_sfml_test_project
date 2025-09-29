#include "../include/Map.hpp"
#include "../include/Handler.hpp"

Map::Map(Handler& handler)
: handler(handler),
player(handler, 128, 128)
{
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
                handler.getRenderWindow().draw(*spritePointer);
            }
        }
    }

    player.render();
}