#pragma once
#include <SFML/Graphics.hpp>
#include "../include/Constants.hpp"
#include "../include/EventManager.hpp"
#include "../include/Map.hpp"
#include "../include/SpriteManager.hpp"

class Handler {
public:
    Handler(sf::RenderWindow& renderWindow);
    sf::RenderWindow& getRenderWindow();
    EventManager& getEventManager();
    Map& getMap();
    SpriteManager& getSpriteManager();

private:
    sf::RenderWindow& renderWindow;
    EventManager eventManager;
    Map map;
    SpriteManager spriteManager;
};