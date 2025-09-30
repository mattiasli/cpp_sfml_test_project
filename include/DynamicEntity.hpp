#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Handler;

class DynamicEntity : public Entity {
public:
    DynamicEntity(Handler& handler, sf::Vector2f worldCoordinate, BoundingBox boundingBox);

    virtual void updateLogic();

    virtual void updatePosition();

protected:
    sf::Vector2f deltaWorldCoordinate = {0, 0};
};