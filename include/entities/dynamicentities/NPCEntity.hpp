#pragma once
#include <SFML/Graphics.hpp>
#include "DynamicEntity.hpp"

class Handler;

class NPCEntity : public DynamicEntity {
public:
    NPCEntity(Handler& handler, sf::Vector2f worldCoordinate, const BoundingBox& boundingBox);

    virtual void updateLogic() override;

private:
    static constexpr double minWaitTimeMicroseconds = 0.0;
    static constexpr double maxWaitTimeMicroseconds = 4000000.0;

    double waitTimeRemainingMicroseconds;

    virtual void updateMovementSpeed();
    virtual void updateAction();
    virtual double getMinWaitTimeMicroseconds() const;
    virtual double getMaxWaitTimeMicroseconds() const;
};