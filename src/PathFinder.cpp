#include "../include/PathFinder.hpp"
#include "../include/Handler.hpp"

PathFinder::PathFinder(Handler& handler)
: handler(handler),
map(handler.getMap()),
coordinateConverter(handler.getCoordinateConverter())
{
}

std::vector<sf::Vector2i> PathFinder::computeAStarPath(sf::Vector2i startGridCoordinate, sf::Vector2i goalGridCoordinate)
{
    if(map.isGridCoordinateSolid(startGridCoordinate) ||
       !map.isGridCoordinateInsideMapGrid(goalGridCoordinate))
    {
        return {};
    }

    std::vector<NodeStatus> nodeStatusVector(static_cast<std::size_t>(map.getGridWidth() * map.getGridHeight()));
    std::priority_queue<OpenSetNode> openSetNodePriorityQueue;
    OpenSetNode closestReachableOpenSetNode = {std::numeric_limits<int>::max(), 0, constants::invalidCoordinate};

    nodeStatusVector[coordinateConverter.convertTo1DIndex(startGridCoordinate)].gValue = 0;
    openSetNodePriorityQueue.push(OpenSetNode{hValue(startGridCoordinate, goalGridCoordinate), 0, startGridCoordinate});

    while(!openSetNodePriorityQueue.empty())
    {
        OpenSetNode currentOpenSetNode = openSetNodePriorityQueue.top();
        openSetNodePriorityQueue.pop();
        NodeStatus& currentNodeStatus = nodeStatusVector[coordinateConverter.convertTo1DIndex(currentOpenSetNode.gridCoordinate)];

        if(currentNodeStatus.isClosed)
        {
            continue;
        }
        else
        {
            currentNodeStatus.isClosed = 1;

            if(currentOpenSetNode.fValue - currentOpenSetNode.gValue < closestReachableOpenSetNode.fValue - closestReachableOpenSetNode.gValue ||
               (currentOpenSetNode.fValue - currentOpenSetNode.gValue == closestReachableOpenSetNode.fValue - closestReachableOpenSetNode.gValue && currentOpenSetNode.gValue < closestReachableOpenSetNode.gValue))
            {
                closestReachableOpenSetNode.gValue = currentOpenSetNode.gValue;
                closestReachableOpenSetNode.fValue = currentOpenSetNode.fValue;
                closestReachableOpenSetNode.gridCoordinate = currentOpenSetNode.gridCoordinate;
            }
        }

        if(currentOpenSetNode.gridCoordinate == goalGridCoordinate)
        {
            return reconstructPath(nodeStatusVector, goalGridCoordinate);
        }

        for(std::size_t i = 0; i < deltaGridCoordinate.size(); i++)
        {
            const sf::Vector2i adjacentGridCoordinate = currentOpenSetNode.gridCoordinate + deltaGridCoordinate[i];

            if(!map.isGridCoordinateInsideMapGrid(adjacentGridCoordinate)) continue;
            if(map.isGridCoordinateSolid(adjacentGridCoordinate)) continue;

            NodeStatus& adjacentNodeStatus = nodeStatusVector[coordinateConverter.convertTo1DIndex(adjacentGridCoordinate)];

            if(adjacentNodeStatus.isClosed) continue;

            if(currentNodeStatus.gValue + 1 < adjacentNodeStatus.gValue)
            {
                adjacentNodeStatus.gValue = currentNodeStatus.gValue + 1;
                adjacentNodeStatus.parentGridCoordinate = currentOpenSetNode.gridCoordinate;

                openSetNodePriorityQueue.push(OpenSetNode{hValue(adjacentGridCoordinate, goalGridCoordinate) + currentNodeStatus.gValue + 1,
                                                                 currentNodeStatus.gValue + 1,
                                                                 adjacentGridCoordinate});
            }
        }
    }

    if(closestReachableOpenSetNode.gridCoordinate != constants::invalidCoordinate)
    {
    return reconstructPath(nodeStatusVector, closestReachableOpenSetNode.gridCoordinate);
    }
    else
    {
    return {};
    }
}

int PathFinder::hValue(sf::Vector2i currentGridCoordinate, sf::Vector2i goalGridCoordinate)
{
    return std::abs(currentGridCoordinate.x - goalGridCoordinate.x) + std::abs(currentGridCoordinate.y - goalGridCoordinate.y);
}

std::vector<sf::Vector2i> PathFinder::reconstructPath(std::vector<NodeStatus>& nodeStatusVector, sf::Vector2i goalGridCoordinate)
{
    std::vector<sf::Vector2i> gridCoordinateVector;
    sf::Vector2i currentGridCoordinate = goalGridCoordinate;

    while(currentGridCoordinate != constants::invalidCoordinate)
    {
        gridCoordinateVector.push_back(currentGridCoordinate);
        const NodeStatus& currentNodeStatus = nodeStatusVector[coordinateConverter.convertTo1DIndex(currentGridCoordinate)];
        currentGridCoordinate = currentNodeStatus.parentGridCoordinate;
    }

    std::reverse(gridCoordinateVector.begin(), gridCoordinateVector.end());

    return gridCoordinateVector;
}