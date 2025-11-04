#include "../../include/world/Map.hpp"
#include "../../include/core/Handler.hpp"

Map::Map(Handler& handler)
: handler(handler)
{
    solidTable['#'] = true; // TODO: update to flyweight algorithm.
    solidTable['~'] = true;
    solidTable['^'] = true;

    tempEntityVector.push_back(new Player(handler, handler.getCoordinateConverter().convertToWorldCoordinate({8, 3}))); // TODO: fix this to something more robust.

    tempEntityVector.push_back(new GuardSwordsman(handler, handler.getCoordinateConverter().convertToWorldCoordinate({1, 1})));
    tempEntityVector.push_back(new GuardSwordsman(handler, handler.getCoordinateConverter().convertToWorldCoordinate({2, 1})));
    tempEntityVector.push_back(new GuardSwordsman(handler, handler.getCoordinateConverter().convertToWorldCoordinate({3, 1})));
    tempEntityVector.push_back(new GuardSwordsman(handler, handler.getCoordinateConverter().convertToWorldCoordinate({4, 1})));

    tempEntityVector.push_back(new GuardSpearman(handler, handler.getCoordinateConverter().convertToWorldCoordinate({10, 20})));
    tempEntityVector.push_back(new GuardSpearman(handler, handler.getCoordinateConverter().convertToWorldCoordinate({11, 20})));
    tempEntityVector.push_back(new GuardSpearman(handler, handler.getCoordinateConverter().convertToWorldCoordinate({12, 20})));
    tempEntityVector.push_back(new GuardSpearman(handler, handler.getCoordinateConverter().convertToWorldCoordinate({13, 20})));

    tempEntityVector.push_back(new CitizenMale(handler, handler.getCoordinateConverter().convertToWorldCoordinate({7, 5})));
    tempEntityVector.push_back(new CitizenMale(handler, handler.getCoordinateConverter().convertToWorldCoordinate({7, 4})));
    tempEntityVector.push_back(new CitizenMale(handler, handler.getCoordinateConverter().convertToWorldCoordinate({7, 3})));
    tempEntityVector.push_back(new CitizenMale(handler, handler.getCoordinateConverter().convertToWorldCoordinate({8, 3})));

    tempEntityVector.push_back(new CitizenFemale(handler, handler.getCoordinateConverter().convertToWorldCoordinate({7, 5})));
    tempEntityVector.push_back(new CitizenFemale(handler, handler.getCoordinateConverter().convertToWorldCoordinate({7, 4})));
    tempEntityVector.push_back(new CitizenFemale(handler, handler.getCoordinateConverter().convertToWorldCoordinate({7, 3})));
    tempEntityVector.push_back(new CitizenFemale(handler, handler.getCoordinateConverter().convertToWorldCoordinate({8, 3})));

    tempEntityVector.push_back(new Snake(handler, handler.getCoordinateConverter().convertToWorldCoordinate({7, 5})));
    tempEntityVector.push_back(new Snake(handler, handler.getCoordinateConverter().convertToWorldCoordinate({7, 4})));
    tempEntityVector.push_back(new Snake(handler, handler.getCoordinateConverter().convertToWorldCoordinate({7, 3})));
    tempEntityVector.push_back(new Snake(handler, handler.getCoordinateConverter().convertToWorldCoordinate({8, 3})));

    tempEntityVector.push_back(new Wolf(handler, handler.getCoordinateConverter().convertToWorldCoordinate({1, 1})));
    tempEntityVector.push_back(new Wolf(handler, handler.getCoordinateConverter().convertToWorldCoordinate({3, 3})));
    tempEntityVector.push_back(new Wolf(handler, handler.getCoordinateConverter().convertToWorldCoordinate({29, 29})));
    tempEntityVector.push_back(new Wolf(handler, handler.getCoordinateConverter().convertToWorldCoordinate({29, 27})));
    tempEntityVector.push_back(new Wolf(handler, handler.getCoordinateConverter().convertToWorldCoordinate({15, 15})));

    tempEntityVector.push_back(new GuardSwordsman(handler, handler.getCoordinateConverter().convertToWorldCoordinate({16, 16})));

}

void Map::updateLogic()
{

    for(auto& de : tempEntityVector)
    {
    de->updateLogic();
    }
    handler.getSpriteManager().updateLogic();
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

    for(DynamicEntity* de : tempEntityVector) // TODO: fix this to something more robust.
    {
    de->render();
    }

    if(handler.getEventManager().getIsKeyboardZKeyPressed())   /////////////////////// TODO: remove this temporary test.
    {
        tempAnimator = handler.getSpriteManager().getInstanceAnimator(constants::EntityType::CapedWarrior, constants::EntityState::Attack, tempEntityVector.front()->getDirection());
    }

    if(!tempAnimator.expired())
    {
        tempAnimator.lock().get()->getSprite()->setPosition(100, 100);
        handler.getRenderWindowManager().getRenderWindow().draw(*tempAnimator.lock().get()->getSprite());
    } //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

