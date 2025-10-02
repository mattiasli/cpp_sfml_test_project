#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Handler;
class Map;
class CoordinateConverter;

class DynamicEntity : public Entity {
public:
    DynamicEntity(Handler& handler, sf::Vector2f worldCoordinate, BoundingBox boundingBox);

    virtual void updateLogic();

protected:
    sf::Vector2f deltaWorldCoordinate = {0, 0};

private:
    Map& map;
    CoordinateConverter& coordinateConverter;

    virtual void updatePosition();
    virtual void adjustDeltaWorldCoordinateForTileCollisions();
};