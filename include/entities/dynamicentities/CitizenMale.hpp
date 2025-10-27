#pragma once
#include <SFML/Graphics.hpp>
#include "NPCEntity.hpp"

class Handler;

class CitizenMale : public NPCEntity {
public:
    CitizenMale(Handler& handler, sf::Vector2f worldCoordinate);

    void render() const override;

protected:
    void applyPathFollowingMovementSpeed() override;

private:
    static constexpr float boundingBoxWidth = 12.f;
    static constexpr float boundingBoxHeight = 14.f;
    static constexpr float boundingBoxOffsetRelativeXWorldCoordinate = 2.f;
    static constexpr float boundingBoxOffsetRelativeYWorldCoordinate = 1.f;

    static constexpr double minWaitTimeMicroseconds = 4000000.0;
    static constexpr double maxWaitTimeMicroseconds = 32000000.0;

    static constexpr float defaultMovementSpeedExpectedValue = 0.25f;
    static constexpr float defaultMovementSpeedStandardDeviation = 0.25f;

    double getMinWaitTimeMicroseconds() const override;
    double getMaxWaitTimeMicroseconds() const override;
};