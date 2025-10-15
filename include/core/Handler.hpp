#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "EventManager.hpp"
#include "../world/Map.hpp"
#include "../graphics/SpriteManager.hpp"
#include "CoordinateConverter.hpp"
#include "../graphics/RenderWindowManager.hpp"
#include "PathFinder.hpp"
#include "ProbabilityManager.hpp"

class Handler {
public:
    Handler();
    EventManager& getEventManager();
    Map& getMap();
    SpriteManager& getSpriteManager();
    CoordinateConverter& getCoordinateConverter();
    RenderWindowManager& getRenderWindowManager();
    PathFinder& getPathFinder();
    ProbabilityManager& getProbabilityManager();

private:
    EventManager eventManager;
    Map map;
    SpriteManager spriteManager;
    CoordinateConverter coordinateConverter;
    RenderWindowManager renderWindowManager;
    PathFinder pathFinder;
    ProbabilityManager probabilityManager;
};