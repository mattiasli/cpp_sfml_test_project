#pragma once
#include <filesystem>
#include <forward_list>
#include <memory>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Animator.hpp"
#include "../graphics/Graphics.hpp"

class Handler;

class SpriteManager {
public:
    SpriteManager(Handler& handler);

    void updateLogic();

    sf::Sprite* getDirtSprite();
    sf::Sprite* getGrassSprite();
    sf::Sprite* getBoulderSprite();
    sf::Sprite* getGroveSprite();
    sf::Sprite* getWaterSprite();

    Animator* getSharedAnimator(constants::EntityType entityType, constants::EntityState entityState, constants::Direction direction);
    std::weak_ptr<Animator> getInstanceAnimator(constants::EntityType entityType, constants::EntityState entityState, constants::Direction direction);

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
    std::forward_list<Animator*> sharedAnimatorList;
    std::forward_list<std::shared_ptr<Animator>> instanceAnimatorList;

    void loadSpriteAtlas();
    std::vector<sf::IntRect> computeTextureRectangleSequence(sf::Vector2i startTexureGridIndex, sf::Vector2i rectangleTextureGridSize, std::uint8_t seqenceLength);
};