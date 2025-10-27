#pragma once
#include <SFML/Graphics.hpp>
#include "NPCEntity.hpp"

class Handler;

class Wolf : public NPCEntity {
public:
    Wolf(Handler& handler, sf::Vector2f worldCoordinate);

    void render() const override;

protected:
    void applyPathFollowingMovementSpeed() override;

private:
    static constexpr float boundingBoxWidth = 14.f;
    static constexpr float boundingBoxHeight = 14.f;
    static constexpr float boundingBoxOffsetRelativeXWorldCoordinate = 1.f;
    static constexpr float boundingBoxOffsetRelativeYWorldCoordinate = 1.f;

    static constexpr double minWaitTimeMicroseconds = 2000000.0;
    static constexpr double maxWaitTimeMicroseconds = 64000000.0;

    static constexpr float defaultMovementSpeedExpectedValue = 0.5f;
    static constexpr float defaultMovementSpeedStandardDeviation = 0.25f;

    double getMinWaitTimeMicroseconds() const override;
    double getMaxWaitTimeMicroseconds() const override;
};