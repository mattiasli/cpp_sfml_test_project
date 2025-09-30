#pragma once
#include <SFML/Graphics.hpp>

class Handler;

class BoundingBox {
public:
    BoundingBox(Handler& handler, sf::Vector2f worldCoordinate, sf::Vector2f size);

    void setPosition(sf::Vector2f worldCoordinate);

    sf::Vector2f getCenterWorldCoordinate();

private:
    Handler& handler;

    sf::FloatRect floatRect;
    sf::Vector2f centerOffsetWorldCoordinate;
};