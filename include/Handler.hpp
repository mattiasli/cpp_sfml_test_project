#pragma once
#include <SFML/Graphics.hpp>
#include "../include/Constants.hpp"
#include "../include/EventManager.hpp"

class Handler {
public:
    Handler(sf::RenderWindow& renderWindow);
    EventManager& getEventManager();

private:
    EventManager eventManager;
};