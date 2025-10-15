#pragma once
#include <cstdint>
#include <cmath>
#include <limits>
#include <queue>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"

class Handler;
class Map;
class CoordinateConverter;

class PathFinder {
public:
    PathFinder(Handler& handler);

    std::vector<sf::Vector2i> computeAStarPath(sf::Vector2i startGridCoordinate, sf::Vector2i goalGridCoordinate);

private:
    struct NodeStatus
    {
        int gValue = std::numeric_limits<int>::max() / 4;
        sf::Vector2i parentGridCoordinate = constants::invalidCoordinate;
        std::uint8_t isClosed = 0;
    };

    struct OpenSetNode
    {
        int fValue;
        int gValue;
        sf::Vector2i gridCoordinate;

        bool operator<(const OpenSetNode& other) const
        {
        if(fValue != other.fValue) return fValue > other.fValue;
        return gValue < other.gValue;
        }
    };

    Handler& handler;
    Map& map;
    CoordinateConverter& coordinateConverter;

    const std::vector<sf::Vector2i> deltaGridCoordinate {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int hValue(sf::Vector2i startGridCoordinate, sf::Vector2i goalGridCoordinate);
    std::vector<sf::Vector2i> reconstructPath(std::vector<NodeStatus>& nodeStatusVector, sf::Vector2i goalGridCoordinate);
};