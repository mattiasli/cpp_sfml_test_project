#pragma once
#include <SFML/Graphics.hpp>
#include "..\core\Constants.hpp"

struct Intent
{
    bool hasEntityState = false;
    bool hasMovementDirection = false;
    bool hasGoalGridCoordinate = false;

    constants::EntityState entityState;
    sf::Vector2f movementDirection;
    sf::Vector2i goalGridCoordinate;
    float movementSpeed;

    void reset()
    {
        *this = Intent{};
    }
};