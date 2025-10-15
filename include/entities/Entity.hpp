#pragma once
#include <SFML/Graphics.hpp>
#include "../core/BoundingBox.hpp"

class Handler;

class Entity {
public:
    Entity(Handler& handler, sf::Vector2f worldCoordinate, const BoundingBox& boundingBox);

    virtual ~Entity() = default;

    virtual void updateLogic() = 0;
    virtual void render() const = 0;

    virtual sf::Vector2f getWorldCoordinate();

protected:
    Handler& handler;
    sf::Vector2f worldCoordinate;
    BoundingBox boundingBox;
};