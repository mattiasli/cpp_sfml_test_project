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
    void setPathStatus(std::vector<sf::Vector2i> gridCoordinateVector);
    struct PathStatus
    {
        std::vector<sf::Vector2i> gridCoordinateVector;
        std::size_t index = 0;
    };
    sf::Vector2f deltaWorldCoordinate = {0, 0};
    PathStatus pathStatus;

private:
    static constexpr float boundingBoxWidth = 16.f;
    static constexpr float boundingBoxHeight = 16.f;
    static constexpr float boundingBoxOffsetRelativeXWorldCoordinate = 0.f;
    static constexpr float boundingBoxOffsetRelativeYWorldCoordinate = 0.f;
    static constexpr float movementSpeed = 1.f;

    Map& map;
    CoordinateConverter& coordinateConverter;
    BoundingBox deltaXBoundingBox;
    BoundingBox deltaYBoundingBox;

    void updateWorldCoordinate();
    void updateBoundingBoxesWorldCoordinates();
    void adjustBoundingBoxForTileCollisions();
    void updateDeltaWorldCoordinateFromPathStatus();
    virtual float getMovementSpeed();
};