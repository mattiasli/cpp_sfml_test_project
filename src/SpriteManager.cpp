#include "../include/SpriteManager.hpp"
#include "../include/Handler.hpp"

SpriteManager::SpriteManager(Handler& handler)
: handler(handler)
{
    spriteAtlas.loadFromFile("../res/spritesheet.png");

    playerSprite.setTexture(spriteAtlas);
    playerSprite.setTextureRect({0 * constants::defaultSpriteWidth, 3 * constants::defaulSpriteHeight, 1 * constants::defaultSpriteWidth, 1 * constants::defaulSpriteHeight});
    playerSprite.setScale(constants::scale , constants::scale);

    dirtSprite.setTexture(spriteAtlas);
    dirtSprite.setTextureRect({0 * constants::tileWidth, 1 * constants::tileHeight, 1 * constants::tileWidth, 1 * constants::tileHeight});
    dirtSprite.setScale(constants::scale , constants::scale);

    grassSprite.setTexture(spriteAtlas);
    grassSprite.setTextureRect({1 * constants::tileWidth, 1 * constants::tileHeight, 1 * constants::tileWidth, 1 * constants::tileHeight});
    grassSprite.setScale(constants::scale , constants::scale);

    boulderSprite.setTexture(spriteAtlas);
    boulderSprite.setTextureRect({0 * constants::tileWidth, 0 * constants::tileHeight, 1 * constants::tileWidth, 1 * constants::tileHeight});
    boulderSprite.setScale(constants::scale , constants::scale);

    groveSprite.setTexture(spriteAtlas);
    groveSprite.setTextureRect({1 * constants::tileWidth, 0 * constants::tileHeight, 1 * constants::tileWidth, 1 * constants::tileHeight});
    groveSprite.setScale(constants::scale , constants::scale);

    waterSprite.setTexture(spriteAtlas);
    waterSprite.setTextureRect({0 * constants::tileWidth, 2 * constants::tileHeight, 1 * constants::tileWidth, 1 * constants::tileHeight});
    waterSprite.setScale(constants::scale , constants::scale);
}

sf::Sprite* SpriteManager::getPlayerSprite()
{
    return &playerSprite;
}

sf::Sprite* SpriteManager::getDirtSprite()
{
    return &dirtSprite;
}

sf::Sprite* SpriteManager::getGrassSprite()
{
    return &grassSprite;
}

sf::Sprite* SpriteManager::getBoulderSprite()
{
    return &boulderSprite;
}

sf::Sprite* SpriteManager::getGroveSprite()
{
    return &groveSprite;
}

sf::Sprite* SpriteManager::getWaterSprite()
{
    return &waterSprite;
}