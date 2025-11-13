#pragma once
#include <memory>
#include "../Entity.hpp"
#include "../../graphics/Animator.hpp"
#include "../../control/DynamicEntityController.hpp"

class Handler;
class Map;
class CoordinateConverter;

struct PathStatus
{
    std::vector<sf::Vector2i> gridCoordinateVector;
    std::size_t index = 0;
    bool empty() const
    {
        return gridCoordinateVector.empty() && index == 0;
    }
    void clear()
    {
        *this = PathStatus{};
    }
};

class DynamicEntity : public Entity {
public:
    DynamicEntity(Handler& handler, sf::Vector2f worldCoordinate, const BoundingBox& boundingBox, constants::EntityType entityType);

    virtual void updateLogic() override;

    virtual double getMinWaitTimeMicroseconds() const;
    virtual double getMaxWaitTimeMicroseconds() const;
    virtual float getDefaultMovementSpeed() const;
    virtual float getRunEntityStateThreshold() const;
    virtual float getDefaultMovementSpeedExpectedValue() const;
    virtual float getDefaultMovementSpeedStandardDeviation() const;
    float getMovementSpeed() const;

    constants::EntityState getEntityState() const;
    PathStatus& getPathStatus();
    std::weak_ptr<Animator> getInstanceAnimator() const;

protected:
    sf::Vector2f deltaWorldCoordinate = {0, 0};
    float movementSpeed = 0.f;
    constants::EntityState entityState = constants::EntityState::Idle;
    constants::Direction lastHorizontalDirection = constants::Direction::Left;
    constants::Direction lastVerticalDirection = constants::Direction::Up;
    PathStatus pathStatus;
    std::weak_ptr<Animator> instanceAnimator;
    std::unique_ptr<DynamicEntityController> dynamicEntityController;

    void applyIntent();
    void setPathStatus(std::vector<sf::Vector2i> gridCoordinateVector);

private:
    static constexpr double minWaitTimeMicroseconds = 0.0;
    static constexpr double maxWaitTimeMicroseconds = 4000000.0;
    static constexpr float defaultMovementSpeed = 0.5f;
    static constexpr float runEntityStateThreshold = 0.25f;
    static constexpr float defaultMovementSpeedExpectedValue = 0.5f;
    static constexpr float defaultMovementSpeedStandardDeviation = 0.125f;

    Map& map;
    CoordinateConverter& coordinateConverter;
    BoundingBox deltaXBoundingBox;
    BoundingBox deltaYBoundingBox;

    void updateWorldCoordinate();
    void updateBoundingBoxesWorldCoordinates();
    void adjustBoundingBoxForTileCollisions();
    void updateDeltaWorldCoordinateFromPathStatus();
    void updateInstanceAnimatorFromEntityState();
    void updateDirectionsFromDeltaWorldCoordinate();
};