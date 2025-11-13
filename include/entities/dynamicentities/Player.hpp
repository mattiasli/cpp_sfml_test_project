#pragma once
#include "DynamicEntity.hpp"
#include "../../../include/control/PlayerController.hpp"

class Handler;

class Player : public DynamicEntity {
public:
    Player(Handler& handler, sf::Vector2f worldCoordinate);

    void updateLogic() override;
    void render() const;

    float getDefaultMovementSpeed() const override;

private:
    static constexpr float boundingBoxWidth = 12.f;
    static constexpr float boundingBoxHeight = 14.f;
    static constexpr float boundingBoxOffsetRelativeXWorldCoordinate = 2.f;
    static constexpr float boundingBoxOffsetRelativeYWorldCoordinate = 1.f;

    static constexpr float defaultMovementSpeed = 1.f;
};