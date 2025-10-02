#pragma once
#include <SFML/Graphics.hpp>

class Handler;

class BoundingBox {
public:
    BoundingBox(Handler& handler, sf::Vector2f worldCoordinate, sf::Vector2f size);

    void setPosition(sf::Vector2f worldCoordinate);
    void setXWorldCoordinate(float xWorldCoordinate);
    void setYWorldCoordinate(float yWorldCoordinate);

    sf::Vector2f getCenterWorldCoordinate();
    float getLeftEdgeXWorldCoordinate();
    float getRightEdgeXWorldCoordinate();
    float getTopEdgeYWorldCoordinate();
    float getBottomEdgeYWorldCoordinate();

private:
    Handler& handler;

    sf::FloatRect floatRect;
};