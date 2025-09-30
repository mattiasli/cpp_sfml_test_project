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
};