#pragma once
#include <memory>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "../graphics/Graphics.hpp"
#include "Animation.hpp"
#include "Animator.hpp"

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

    Animator* getAnimator(constants::EntityType entityType, constants::EntityState entityState, constants::Direction direction);

private:
    Handler& handler;

    sf::Texture spriteAtlas;

    sf::Sprite dirtSprite;
    sf::Sprite grassSprite;
    sf::Sprite boulderSprite;
    sf::Sprite groveSprite;
    sf::Sprite waterSprite;

    std::unique_ptr<Animation> nullAnimation;
    std::unique_ptr<Animator> nullAnimator;
    std::unordered_map<graphics::EntityVisualKey, std::unique_ptr<Animation>, graphics::EntityVisualKeyHash> animationMap;
    std::unordered_map<graphics::EntityVisualKey, std::unique_ptr<Animator>, graphics::EntityVisualKeyHash> animatorMap;
    std::vector<Animator*> animatorVector;
};