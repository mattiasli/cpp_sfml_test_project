#pragma once
#include <SFML/Graphics.hpp>
#include "DynamicEntity.hpp"

class Handler;

class Player : public DynamicEntity {
public:
    Player(Handler& handler, sf::Vector2f worldCoordinate);

    void updateLogic() override;

    void processInput();

    void render() const;

private:

    static constexpr float boundingBoxWidth = 12.f;
    static constexpr float boundingBoxHeight = 14.f;
    static constexpr float boundingBoxOffsetXWorldCoordinate = 2.f;
    static constexpr float boundingBoxOffsetYWorldCoordinate = 1.f;
    static constexpr float movementSpeed = 1.f;
};