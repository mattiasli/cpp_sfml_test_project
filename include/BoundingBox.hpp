#pragma once
#include <SFML/Graphics.hpp>

class Handler;

class BoundingBox {
public:
    BoundingBox(Handler& handler, sf::Vector2f worldCoordinate, sf::Vector2f size);

    void setWorldCoordinate(sf::Vector2f worldCoordinate);
    void setXWorldCoordinate(float xWorldCoordinate);
    void setYWorldCoordinate(float yWorldCoordinate);

    float getWidth();
    float getHeight();
    sf::Vector2f getWorldCoordinate();
    sf::Vector2f getCenterWorldCoordinate();
    float getXWorldCoordinate();
    float getYWorldCoordinate();
    float getLeftEdgeXWorldCoordinate();
    float getRightEdgeXWorldCoordinate();
    float getTopEdgeYWorldCoordinate();
    float getBottomEdgeYWorldCoordinate();

private:
    Handler& handler;

    sf::FloatRect floatRect;
};