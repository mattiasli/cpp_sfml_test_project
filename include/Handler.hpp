#pragma once
#include <SFML/Graphics.hpp>
#include "../include/Constants.hpp"
#include "../include/EventManager.hpp"
#include "../include/Map.hpp"
#include "../include/SpriteManager.hpp"
#include "../include/CoordinateConverter.hpp"
#include "../include/RenderWindowManager.hpp"
#include "../include/PathFinder.hpp"

class Handler {
public:
    Handler();
    EventManager& getEventManager();
    Map& getMap();
    SpriteManager& getSpriteManager();
    CoordinateConverter& getCoordinateConverter();
    RenderWindowManager& getRenderWindowManager();
    PathFinder& getPathFinder();

private:
    EventManager eventManager;
    Map map;
    SpriteManager spriteManager;
    CoordinateConverter coordinateConverter;
    RenderWindowManager renderWindowManager;
    PathFinder pathFinder;
};