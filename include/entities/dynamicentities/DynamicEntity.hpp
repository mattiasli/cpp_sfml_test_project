#pragma once
#include <SFML/Graphics.hpp>
#include "../Entity.hpp"

class Handler;
class Map;
class CoordinateConverter;

class DynamicEntity : public Entity {
public:
    DynamicEntity(Handler& handler, sf::Vector2f worldCoordinate, const BoundingBox& boundingBox);

    virtual void updateLogic() override;

protected:
    void setPathStatus(std::vector<sf::Vector2i> gridCoordinateVector);
    struct PathStatus
    {
        std::vector<sf::Vector2i> gridCoordinateVector;
        std::size_t index = 0;
    };
    sf::Vector2f deltaWorldCoordinate = {0, 0};
    PathStatus pathStatus;
    constants::Direction lastHorizontalDirection;
    constants::Direction lastVerticalDirection;

    virtual float getRunAnimationThreshold() const;

private:
    static constexpr float defaultMovementSpeed = 0.5f;
    static constexpr float defaultRunAnimationThreshold = 0.25f;

    Map& map;
    CoordinateConverter& coordinateConverter;
    BoundingBox deltaXBoundingBox;
    BoundingBox deltaYBoundingBox;

    void updateWorldCoordinate();
    void updateBoundingBoxesWorldCoordinates();
    void adjustBoundingBoxForTileCollisions();
    void updateDeltaWorldCoordinateFromPathStatus();
    void updateDirectionsFromDeltaWorldCoordinate();
    virtual float getMovementSpeed() const;
};