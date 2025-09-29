#pragma once
#include <SFML/Graphics.hpp>

class Handler;

class Entity {
public:
    Entity(Handler& handler, float xCoordinate, float yCoordinate);

    virtual ~Entity() = default;

    virtual void updateLogic() = 0;
    virtual void render() const = 0;

    virtual float getXCoordinate();
    virtual float getYCoordinate();

protected:
    Handler& handler;
    float xCoordinate, yCoordinate;
};