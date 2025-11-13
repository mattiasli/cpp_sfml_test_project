#pragma once
#include <SFML/Graphics.hpp>
#include "..\core\Constants.hpp"

struct Perception
{
    void reset()
    {
        *this = Perception{};
    }
};

struct ControlInput
{
    bool hasKeyboardDirection = false;
    bool hasMouseGoalWorldCoordinate = false;

    sf::Vector2f keyboardDirection;
    sf::Vector2i mouseGoalWorldCoordinate;
    bool isKeyboardAttackActive = false;

    void reset()
    {
        *this = ControlInput{};
    }
};

struct DecisionContext
{
    Perception perception;
    ControlInput controlInput;

    void reset()
    {
        perception.reset();
        controlInput.reset();
    }
};