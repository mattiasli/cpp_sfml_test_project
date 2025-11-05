#pragma once
#include <SFML/Graphics.hpp>
#include "..\core\Constants.hpp"

struct Perception
{
};

struct ControlInput
{
    sf::Vector2f keyboardArrowKeyDirection = constants::zeroVector;
    sf::Vector2i mouseLeftButtonWorldCoordinate = constants::invalidCoordinate;
    bool isKeyboardAttackKeyPressed = false;
};

struct DecisionContext
{
    Perception perception;
    ControlInput controlInput;
};