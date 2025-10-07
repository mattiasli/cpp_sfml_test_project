#pragma once
#include <SFML/Graphics.hpp>
#include "../include/Constants.hpp"
#include <cstdint>
#include <limits>
#include <vector>
#include <cmath>
#include <queue>

class Handler;
class Map;
class CoordinateConverter;

class PathFinder {
public:
    PathFinder(Handler& handler);

    std::vector<sf::Vector2i> aStarPath(sf::Vector2i startNode, sf::Vector2i goalNode);

private:
    Handler& handler;
    Map& map;
    CoordinateConverter& coordinateConverter;

    struct NodeStatus
    {
        int gValue = std::numeric_limits<int>::max() / 4;
        sf::Vector2i parentGridCoordinate = constants::invalidCoordinate;
        std::uint8_t isClosed = 0;
    };

    /*larger g bias the algorithm toward nodes that are:
    -Further along the path from the start (more committed)
    -Closer to reaching the goal
    -Less likely to "wander sideways" early on*/
    struct OpenSetNode
    {
        int fValue;
        int gValue;
        sf::Vector2i gridCoordinate;

        bool operator<(const OpenSetNode& other) const // invert comparisons for min-heap behaviour.
        {
        if(fValue != other.fValue) return fValue > other.fValue;
        return gValue < other.gValue;
        }
    };

    const std::vector<sf::Vector2i> deltaGridCoordinate {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int hValue(sf::Vector2i startGridCoordinate, sf::Vector2i goalGridCoordinate);

    std::vector<sf::Vector2i> reconstructPath(std::vector<NodeStatus>& nodeStatusVector, sf::Vector2i goalGridCoordinate);
};