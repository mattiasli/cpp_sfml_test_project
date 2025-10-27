#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include <cstdint>
#include <unordered_map>
#include "../graphics/Graphics.hpp"

class Handler;

class SpriteManager {
public:
    SpriteManager(Handler& handler);

    void updateLogic();

    std::vector<sf::IntRect> computeTextureRectangleSequence(sf::Vector2i startTexureGridIndex, sf::Vector2i rectangleTextureGridSize, std::uint8_t seqenceLength);

    sf::Sprite* getDirtSprite();
    sf::Sprite* getGrassSprite();
    sf::Sprite* getBoulderSprite();
    sf::Sprite* getGroveSprite();
    sf::Sprite* getWaterSprite();

    Animation* getAnimation(constants::EntityType entityType, constants::EntityState entityState, constants::Direction direction);

private:
    Handler& handler;

    sf::Texture spriteAtlas;

    sf::Sprite dirtSprite;
    sf::Sprite grassSprite;
    sf::Sprite boulderSprite;
    sf::Sprite groveSprite;
    sf::Sprite waterSprite;

    Animation* nullAnimation;
    std::unordered_map<graphics::AnimationKey, Animation*, graphics::AnimationKeyHash> animationMap;
    std::vector<Animation*> animationVector;
};