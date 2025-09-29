#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Handler;

class DynamicEntity : public Entity {
public:
    DynamicEntity(Handler& handler, float xCoordinate, float yCoordinate);

    virtual void updateLogic();

    virtual void updatePosition();

protected:
    float deltaX = 0, deltaY = 0;
};