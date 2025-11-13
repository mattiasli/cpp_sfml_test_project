#pragma once
#include "NPCEntity.hpp"

class Handler;

class GuardSwordsman : public NPCEntity {
public:
    GuardSwordsman(Handler& handler, sf::Vector2f worldCoordinate);

    void render() const override;

    double getMinWaitTimeMicroseconds() const override;
    double getMaxWaitTimeMicroseconds() const override;
    float getDefaultMovementSpeedExpectedValue() const override;
    float getDefaultMovementSpeedStandardDeviation() const override;

protected:

private:
    static constexpr float boundingBoxWidth = 12.f;
    static constexpr float boundingBoxHeight = 14.f;
    static constexpr float boundingBoxOffsetRelativeXWorldCoordinate = 2.f;
    static constexpr float boundingBoxOffsetRelativeYWorldCoordinate = 1.f;

    static constexpr double minWaitTimeMicroseconds = 4000000.0;
    static constexpr double maxWaitTimeMicroseconds = 32000000.0;
    static constexpr float defaultMovementSpeedExpectedValue = 0.375f;
    static constexpr float defaultMovementSpeedStandardDeviation = 0.25f;
};