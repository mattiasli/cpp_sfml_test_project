#include "../../include/graphics/SpriteManager.hpp"
#include "../../include/core/Handler.hpp"

SpriteManager::SpriteManager(Handler& handler)
: handler(handler)
{
    spriteAtlas.loadFromFile("../res/spritesheet.png");

    dirtSprite.setTexture(spriteAtlas);
    dirtSprite.setTextureRect({0 * constants::tileWidth, 1 * constants::tileHeight, 1 * constants::tileWidth, 1 * constants::tileHeight});
    dirtSprite.setScale(constants::scale , constants::scale);

    grassSprite.setTexture(spriteAtlas);
    grassSprite.setTextureRect({1 * constants::tileWidth, 1 * constants::tileHeight, 1 * constants::tileWidth, 1 * constants::tileHeight});
    grassSprite.setScale(constants::scale , constants::scale);

    boulderSprite.setTexture(spriteAtlas);
    boulderSprite.setTextureRect({2 * constants::tileWidth, 0 * constants::tileHeight, 1 * constants::tileWidth, 1 * constants::tileHeight});
    boulderSprite.setScale(constants::scale , constants::scale);

    groveSprite.setTexture(spriteAtlas);
    groveSprite.setTextureRect({1 * constants::tileWidth, 0 * constants::tileHeight, 1 * constants::tileWidth, 1 * constants::tileHeight});
    groveSprite.setScale(constants::scale , constants::scale);

    waterSprite.setTexture(spriteAtlas);
    waterSprite.setTextureRect({0 * constants::tileWidth, 2 * constants::tileHeight, 1 * constants::tileWidth, 1 * constants::tileHeight});
    waterSprite.setScale(constants::scale , constants::scale);

    nullAnimation = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 0}, {1, 1}, 1), 1000000.0);

    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Idle, constants::Direction::Up}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({4, 7}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Idle, constants::Direction::Down}] = new Animation(handler, spriteAtlas,  computeTextureRectangleSequence({4, 6}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Idle, constants::Direction::Left}] = new Animation(handler, spriteAtlas,  computeTextureRectangleSequence({4, 5}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Idle, constants::Direction::Right}] = new Animation(handler, spriteAtlas,  computeTextureRectangleSequence({4, 4}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Walk, constants::Direction::Up}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({4, 11}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Walk, constants::Direction::Down}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({4, 10}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Walk, constants::Direction::Left}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({4, 9}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Walk, constants::Direction::Right}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({4, 8}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Run, constants::Direction::Up}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({4, 15}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Run, constants::Direction::Down}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({4, 14}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Run, constants::Direction::Left}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({4, 13}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Run, constants::Direction::Right}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({4, 12}, {1, 1}, 4), 125000.0);

    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Idle, constants::Direction::Up}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 7}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Idle, constants::Direction::Down}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 6}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Idle, constants::Direction::Left}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 5}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Idle, constants::Direction::Right}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 4}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Walk, constants::Direction::Up}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 11}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Walk, constants::Direction::Down}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 10}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Walk, constants::Direction::Left}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 9}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Walk, constants::Direction::Right}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 8}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Run, constants::Direction::Up}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 15}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Run, constants::Direction::Down}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 14}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Run, constants::Direction::Left}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 13}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Run, constants::Direction::Right}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({12, 12}, {1, 1}, 4), 125000.0);

    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Idle, constants::Direction::Up}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 7}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Idle, constants::Direction::Down}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 6}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Idle, constants::Direction::Left}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 5}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Idle, constants::Direction::Right}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 4}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Walk, constants::Direction::Up}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 11}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Walk, constants::Direction::Down}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 10}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Walk, constants::Direction::Left}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 9}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Walk, constants::Direction::Right}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 8}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Run, constants::Direction::Up}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 15}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Run, constants::Direction::Down}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 14}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Run, constants::Direction::Left}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 13}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Run, constants::Direction::Right}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({16, 12}, {1, 1}, 4), 125000.0);

    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Idle, constants::Direction::Up}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 7}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Idle, constants::Direction::Down}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 6}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Idle, constants::Direction::Left}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 5}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Idle, constants::Direction::Right}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 4}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Walk, constants::Direction::Up}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 11}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Walk, constants::Direction::Down}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 10}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Walk, constants::Direction::Left}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 9}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Walk, constants::Direction::Right}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 8}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Run, constants::Direction::Up}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 15}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Run, constants::Direction::Down}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 14}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Run, constants::Direction::Left}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 13}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Run, constants::Direction::Right}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({20, 12}, {1, 1}, 4), 125000.0);

    animationMap[{constants::EntityType::Wolf, constants::EntityState::Idle, constants::Direction::Up}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 7}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Idle, constants::Direction::Down}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 6}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Idle, constants::Direction::Left}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 5}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Idle, constants::Direction::Right}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 4}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Walk, constants::Direction::Up}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 11}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Walk, constants::Direction::Down}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 10}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Walk, constants::Direction::Left}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 9}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Walk, constants::Direction::Right}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 8}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Run, constants::Direction::Up}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 15}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Run, constants::Direction::Down}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 14}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Run, constants::Direction::Left}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 13}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Run, constants::Direction::Right}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({8, 12}, {1, 1}, 4), 125000.0);

    animationMap[{constants::EntityType::Snake, constants::EntityState::Idle, constants::Direction::Left}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 5}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::Snake, constants::EntityState::Idle, constants::Direction::Right}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 4}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::Snake, constants::EntityState::Walk, constants::Direction::Up}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 9}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::Snake, constants::EntityState::Walk, constants::Direction::Down}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 8}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::Snake, constants::EntityState::Walk, constants::Direction::Left}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 7}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::Snake, constants::EntityState::Walk, constants::Direction::Right}] = new Animation(handler, spriteAtlas, computeTextureRectangleSequence({0, 6}, {1, 1}, 4), 187500.0);

    animationVector.clear();
    animationVector.reserve(animationMap.size());
    for (const std::pair<const graphics::AnimationKey, Animation*>& pair : animationMap)
    {
        animationVector.push_back(pair.second);
    }
}

void SpriteManager::updateLogic()
{
    for(Animation* animation : animationVector)
    {
        animation->updateLogic();
    }
}

std::vector<sf::IntRect> SpriteManager::computeTextureRectangleSequence(sf::Vector2i startTexureGridIndex, sf::Vector2i rectangleTextureGridSize, std::uint8_t seqenceLength)
{
    std::vector<sf::IntRect> textureRectangleSequence;
    textureRectangleSequence.reserve(seqenceLength);

    for(std::uint8_t i = 0; i < seqenceLength; i++)
    {
        textureRectangleSequence.emplace_back((startTexureGridIndex.x + i) * constants::defaultSpriteWidth,
                                              startTexureGridIndex.y * constants::defaulSpriteHeight,
                                              rectangleTextureGridSize.x * constants::defaultSpriteWidth,
                                              rectangleTextureGridSize.y * constants::defaultSpriteWidth);
    }

    return textureRectangleSequence;
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

Animation* SpriteManager::getAnimation(constants::EntityType entityType, constants::EntityState entityState, constants::Direction direction)
{
    auto iterator = animationMap.find({entityType, entityState, direction});
    if(iterator == animationMap.end())
    {
        return nullAnimation;
    }
    else
    {
        return  iterator->second;
    }
}