#pragma once
#include <SFML/Graphics.hpp>
#include "DynamicEntity.hpp"

class Handler;

class Player : public DynamicEntity {
public:
    Player(Handler& handler, float xCoordinate, float yCoordinate);

    void updateLogic() override;

    void render() const;

private:
};