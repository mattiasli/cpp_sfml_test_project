#pragma once
#include <SFML/Graphics.hpp>
#include <cstdint>
#include <limits>

class Handler;
class CoordinateConverter;

class PathFinder {
public:
    PathFinder(Handler& handler);

private:
    Handler& handler;
    CoordinateConverter& coordinateConverter;

    struct NodeStatus
    {
        int gValue = std::numeric_limits<int>::max() / 4;
        sf::Vector2i parentGridCoordinate = {-1, -1};
        std::uint8_t isClosed = 0;
    };

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
        /*larger g bias the algorithm toward nodes that are:
        -Further along the path from the start (more committed)
        -Closer to reaching the goal
        -Less likely to "wander sideways" early on*/
    };
};