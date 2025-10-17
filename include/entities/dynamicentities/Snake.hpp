#pragma once
#include <SFML/Graphics.hpp>
#include "NPCEntity.hpp"

class Handler;

class Snake : public NPCEntity {
public:
    Snake(Handler& handler, sf::Vector2f worldCoordinate);

    void render() const override;

private:
    static constexpr float boundingBoxWidth = 10.f;
    static constexpr float boundingBoxHeight = 10.f;
    static constexpr float boundingBoxOffsetRelativeXWorldCoordinate = 3.f;
    static constexpr float boundingBoxOffsetRelativeYWorldCoordinate = 3.f;

    static constexpr double minWaitTimeMicroseconds = 2000000.0;
    static constexpr double maxWaitTimeMicroseconds = 64000000.0;

    static constexpr float defaultMovementSpeedExpectedValue = 0.25f;
    static constexpr float defaultMovementSpeedStandardDeviation = 0.5f;

    float movementSpeed;

    void updateMovementSpeed() override;
    float getMovementSpeed() const override;
    double getMinWaitTimeMicroseconds() const override;
    double getMaxWaitTimeMicroseconds() const override;
};