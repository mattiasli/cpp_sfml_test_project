#include "../../include/graphics/SpriteManager.hpp"
#include "../../include/core/Handler.hpp"

SpriteManager::SpriteManager(Handler& handler)
: handler(handler)
{
    loadSpriteAtlas();

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

    nullAnimation = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({0, 0}, {1, 1}, 1), 1000000.0);
    nullAnimator = std::make_unique<Animator>(handler, nullAnimation.get());

    animationMap.clear();

    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Idle, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({4, 7}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Idle, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas,  computeTextureRectangleSequence({4, 6}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Idle, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas,  computeTextureRectangleSequence({4, 5}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Idle, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas,  computeTextureRectangleSequence({4, 4}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Walk, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({4, 11}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Walk, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({4, 10}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Walk, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({4, 9}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Walk, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({4, 8}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Run, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({4, 15}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Run, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({4, 14}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Run, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({4, 13}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Run, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({4, 12}, {1, 1}, 4), 125000.0);

    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Attack, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({0, 22}, {2, 2}, 4), constants::offsetLeft8Up8PixelPoint, 62500.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Attack, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({0, 20}, {2, 2}, 4), constants::offsetLeft8Up8PixelPoint, 62500.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Attack, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({0, 18}, {2, 2}, 4), constants::offsetLeft8Up8PixelPoint, 62500.0);
    animationMap[{constants::EntityType::CapedWarrior, constants::EntityState::Attack, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({0, 16}, {2, 2}, 4), constants::offsetLeft8Up8PixelPoint, 62500.0);

    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Idle, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({12, 7}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Idle, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({12, 6}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Idle, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({12, 5}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Idle, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({12, 4}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Walk, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({12, 11}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Walk, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({12, 10}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Walk, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({12, 9}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Walk, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({12, 8}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Run, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({12, 15}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Run, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({12, 14}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Run, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({12, 13}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::GuardSwordsman, constants::EntityState::Run, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({12, 12}, {1, 1}, 4), 125000.0);

    animationMap[{constants::EntityType::GuardSpearman, constants::EntityState::Idle, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({24, 7}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::GuardSpearman, constants::EntityState::Idle, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({24, 6}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::GuardSpearman, constants::EntityState::Idle, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({24, 5}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::GuardSpearman, constants::EntityState::Idle, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({24, 4}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::GuardSpearman, constants::EntityState::Walk, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({24, 11}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::GuardSpearman, constants::EntityState::Walk, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({24, 10}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::GuardSpearman, constants::EntityState::Walk, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({24, 9}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::GuardSpearman, constants::EntityState::Walk, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({24, 8}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::GuardSpearman, constants::EntityState::Run, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({24, 15}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::GuardSpearman, constants::EntityState::Run, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({24, 14}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::GuardSpearman, constants::EntityState::Run, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({24, 13}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::GuardSpearman, constants::EntityState::Run, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({24, 12}, {1, 1}, 4), 125000.0);

    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Idle, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({16, 7}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Idle, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({16, 6}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Idle, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({16, 5}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Idle, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({16, 4}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Walk, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({16, 11}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Walk, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({16, 10}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Walk, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({16, 9}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Walk, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({16, 8}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Run, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({16, 15}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Run, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({16, 14}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Run, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({16, 13}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::CitizenMale, constants::EntityState::Run, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({16, 12}, {1, 1}, 4), 125000.0);

    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Idle, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({20, 7}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Idle, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({20, 6}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Idle, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({20, 5}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Idle, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({20, 4}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Walk, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({20, 11}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Walk, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({20, 10}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Walk, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({20, 9}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Walk, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({20, 8}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Run, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({20, 15}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Run, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({20, 14}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Run, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({20, 13}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::CitizenFemale, constants::EntityState::Run, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({20, 12}, {1, 1}, 4), 125000.0);

    animationMap[{constants::EntityType::Wolf, constants::EntityState::Idle, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({8, 7}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Idle, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({8, 6}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Idle, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({8, 5}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Idle, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({8, 4}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Walk, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({8, 11}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Walk, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({8, 10}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Walk, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({8, 9}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Walk, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({8, 8}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Run, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({8, 15}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Run, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({8, 14}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Run, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({8, 13}, {1, 1}, 4), 125000.0);
    animationMap[{constants::EntityType::Wolf, constants::EntityState::Run, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({8, 12}, {1, 1}, 4), 125000.0);

    animationMap[{constants::EntityType::Snake, constants::EntityState::Idle, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({0, 5}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::Snake, constants::EntityState::Idle, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({0, 4}, {1, 1}, 4), 500000.0);
    animationMap[{constants::EntityType::Snake, constants::EntityState::Walk, constants::Direction::Up}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({0, 9}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::Snake, constants::EntityState::Walk, constants::Direction::Down}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({0, 8}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::Snake, constants::EntityState::Walk, constants::Direction::Left}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({0, 7}, {1, 1}, 4), 187500.0);
    animationMap[{constants::EntityType::Snake, constants::EntityState::Walk, constants::Direction::Right}] = std::make_unique<Animation>(handler, spriteAtlas, computeTextureRectangleSequence({0, 6}, {1, 1}, 4), 187500.0);

    animatorMap.clear();
    animatorMap.reserve(animationMap.size());
    for (const std::pair<const graphics::EntityVisualKey, std::unique_ptr<Animation>>& pair : animationMap)
    {
        animatorMap.emplace(pair.first, std::make_unique<Animator>(handler, pair.second.get()));
    }

    sharedAnimatorList.clear();
    for (const std::pair<const graphics::EntityVisualKey, std::unique_ptr<Animator>>& pair : animatorMap)
    {
        sharedAnimatorList.push_front(pair.second.get());
    }
}

void SpriteManager::updateLogic()
{
    for(Animator* animator : sharedAnimatorList)
    {
        animator->updateLogic();
    }

    for(auto iterator = instanceAnimatorList.before_begin(); std::next(iterator) != instanceAnimatorList.end(); )
    {
        std::shared_ptr<Animator>& animator = *std::next(iterator);

        if(animator->getIsFinished())
        {
            instanceAnimatorList.erase_after(iterator);    // TODO: make sure there are no memory leaks.
        }
        else
        {
            animator->updateLogic();
            iterator++;
        }
    }
}

void SpriteManager::loadSpriteAtlas() // TODO: improve.
{
    if(std::filesystem::exists("res/spritesheet.png"))
    {
        spriteAtlas.loadFromFile("res/spritesheet.png");
    }
    else if(std::filesystem::exists("spritesheet.png"))
    {
        spriteAtlas.loadFromFile("spritesheet.png");
    }
    else if(std::filesystem::exists("../res/spritesheet.png"))
    {
        spriteAtlas.loadFromFile("../res/spritesheet.png");
    }
    else if(std::filesystem::exists("../spritesheet.png"))
    {
        spriteAtlas.loadFromFile("../spritesheet.png");
    }
}

std::vector<sf::IntRect> SpriteManager::computeTextureRectangleSequence(sf::Vector2i startTexureGridIndex, sf::Vector2i rectangleTextureGridSize, std::uint8_t seqenceLength)
{
    std::vector<sf::IntRect> textureRectangleSequence;
    textureRectangleSequence.reserve(seqenceLength);

    for(std::uint8_t i = 0; i < seqenceLength; i++)
    {
        textureRectangleSequence.emplace_back((startTexureGridIndex.x + i * rectangleTextureGridSize.x) * constants::defaultSpriteWidth,
                                              startTexureGridIndex.y * constants::defaultSpriteHeight,
                                              rectangleTextureGridSize.x * constants::defaultSpriteWidth,
                                              rectangleTextureGridSize.y * constants::defaultSpriteHeight);
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

Animator* SpriteManager::getSharedAnimator(constants::EntityType entityType, constants::EntityState entityState, constants::Direction direction)
{
    auto iterator = animatorMap.find({entityType, entityState, direction});
    if(iterator == animatorMap.end())
    {
        return nullAnimator.get();
    }
    else
    {
        return  iterator->second.get();
    }
}

std::weak_ptr<Animator> SpriteManager::getInstanceAnimator(constants::EntityType entityType, constants::EntityState entityState, constants::Direction direction)
{
    auto iterator = animationMap.find({entityType, entityState, direction});
    if(iterator == animationMap.end())
    {
        instanceAnimatorList.push_front(std::make_shared<Animator>(handler, nullAnimation.get(), graphics::AnimationMode::Instance));
        return instanceAnimatorList.front();
    }
    else
    {
        instanceAnimatorList.push_front(std::make_shared<Animator>(handler, iterator->second.get(), graphics::AnimationMode::Instance));
        return instanceAnimatorList.front();
    }
}