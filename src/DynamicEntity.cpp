#include "../include/DynamicEntity.hpp"
#include "../include/Handler.hpp"

DynamicEntity::DynamicEntity(Handler& handler, sf::Vector2f worldCoordinate, BoundingBox boundingBox)
: Entity(handler, worldCoordinate, boundingBox),
map(handler.getMap()),
coordinateConverter(handler.getCoordinateConverter()),
deltaXBoundingBox(boundingBox),
deltaYBoundingBox(boundingBox)
{
}

void DynamicEntity::updateLogic()
{
    if(!pathStatus.gridCoordinateVector.empty())
    {
        updateDeltaWorldCoordinateFromPathStatus();
    }
    if(deltaWorldCoordinate != constants::zeroVector)
    {
        updateBoundingBoxesWorldCoordinates();
        adjustBoundingBoxForTileCollisions();
        updateWorldCoordinate();
    }
}

void DynamicEntity::updateWorldCoordinate()
{
    worldCoordinate.x = deltaXBoundingBox.getEntityXWorldCoordinate();
    worldCoordinate.y = deltaYBoundingBox.getEntityYWorldCoordinate();
}

void DynamicEntity::updateBoundingBoxesWorldCoordinates()
{
    boundingBox.setEntityWorldCoordinate(worldCoordinate);
    deltaXBoundingBox.setEntityWorldCoordinate(worldCoordinate + sf::Vector2f({deltaWorldCoordinate.x, 0}));
    deltaYBoundingBox.setEntityWorldCoordinate(worldCoordinate + sf::Vector2f({0, deltaWorldCoordinate.y}));
}

void DynamicEntity::adjustBoundingBoxForTileCollisions()
{
    int leftGridColumn = coordinateConverter.convertToXGridCoordinate(deltaXBoundingBox.getLeftEdgeXWorldCoordinate());
    int rightGridColumn = coordinateConverter.convertToXGridCoordinate(deltaXBoundingBox.getRightEdgeXWorldCoordinate());
    int topGridRow = coordinateConverter.convertToYGridCoordinate(deltaXBoundingBox.getTopEdgeYWorldCoordinate());
    int bottomGridRow = coordinateConverter.convertToYGridCoordinate(deltaXBoundingBox.getBottomEdgeYWorldCoordinate());

    for(int y = topGridRow; y <= bottomGridRow ; y++)
    {
        for(int x = leftGridColumn; x <= rightGridColumn ; x++)
        {
            if(!map.isGridCoordinateInsideMapGrid({x, y})) continue;
            if(map.isGridCoordinateSolid({x, y}))
            {
                if(deltaWorldCoordinate.x > 0)
                {
                deltaXBoundingBox.setRectangleXWorldCoordinate(coordinateConverter.convertToXWorldCoordinate(x) - deltaXBoundingBox.getWidth());
                }
                else if(deltaWorldCoordinate.x < 0)
                {
                deltaXBoundingBox.setRectangleXWorldCoordinate(coordinateConverter.convertToXWorldCoordinate(x) + constants::tileWidth * constants::scale);
                }
            }
        }
    }

    leftGridColumn = coordinateConverter.convertToXGridCoordinate(deltaYBoundingBox.getLeftEdgeXWorldCoordinate());
    rightGridColumn = coordinateConverter.convertToXGridCoordinate(deltaYBoundingBox.getRightEdgeXWorldCoordinate());
    topGridRow = coordinateConverter.convertToYGridCoordinate(deltaYBoundingBox.getTopEdgeYWorldCoordinate());
    bottomGridRow = coordinateConverter.convertToYGridCoordinate(deltaYBoundingBox.getBottomEdgeYWorldCoordinate());

    for(int y = topGridRow; y <= bottomGridRow ; y++)
    {
        for(int x = leftGridColumn; x <= rightGridColumn ; x++)
        {
            if(!map.isGridCoordinateInsideMapGrid({x, y})) continue;
            if(map.isGridCoordinateSolid({x, y}))
            {
                if(deltaWorldCoordinate.y > 0)
                {
                deltaYBoundingBox.setRectangleYWorldCoordinate(coordinateConverter.convertToYWorldCoordinate(y) - deltaYBoundingBox.getHeight());
                }
                else if(deltaWorldCoordinate.y < 0)
                {
                deltaYBoundingBox.setRectangleYWorldCoordinate(coordinateConverter.convertToYWorldCoordinate(y) + constants::tileHeight * constants::scale);
                }
            }
        }
    }
}

void DynamicEntity::setPathStatus(std::vector<sf::Vector2i> gridCoordinateVector)
{
    std::size_t tentativeIndex = constants::invalidIndex;

    if(!gridCoordinateVector.empty() &&
       (this->pathStatus.index < this->pathStatus.gridCoordinateVector.size()))
    {
        const sf::Vector2i previousTargetGridCoorinate = this->pathStatus.gridCoordinateVector[this->pathStatus.index];
        float shortestDistanceSquared = std::numeric_limits<float>::max();

        for(std::size_t i = 0; i < gridCoordinateVector.size(); i++)
        {
            sf::Vector2i distanceRelativeGridCoordinate = gridCoordinateVector[i] - previousTargetGridCoorinate;
            float distanceSquared = distanceRelativeGridCoordinate.x * distanceRelativeGridCoordinate.x + distanceRelativeGridCoordinate.y * distanceRelativeGridCoordinate.y;
            if(distanceSquared < shortestDistanceSquared)
            {
                shortestDistanceSquared = distanceSquared;
                tentativeIndex = i;
            }
        }
    }

    this->pathStatus.gridCoordinateVector = std::move(gridCoordinateVector);

    if(tentativeIndex != constants::invalidIndex &&
       !this->pathStatus.gridCoordinateVector.empty())
    {
        this->pathStatus.index = tentativeIndex;
        return;
    }
    else
    {
        this->pathStatus.index = 0;
        return;
    }
}

void DynamicEntity::updateDeltaWorldCoordinateFromPathStatus() // TODO: this->
{
    sf::Vector2f targetRelativeWorldCoordinate;
    float distanceSquared;
    sf::Vector2f tenativeDeltaWorldCoordinate;
    if(this->pathStatus.index < this->pathStatus.gridCoordinateVector.size())
    {
        while(this->pathStatus.index < this->pathStatus.gridCoordinateVector.size())
        {
            targetRelativeWorldCoordinate = coordinateConverter.convertToWorldCoordinate(pathStatus.gridCoordinateVector[pathStatus.index]) - getWorldCoordinate();
            distanceSquared = targetRelativeWorldCoordinate.x * targetRelativeWorldCoordinate.x + targetRelativeWorldCoordinate.y * targetRelativeWorldCoordinate.y;
            if(distanceSquared > constants::defaultArriveRadius * constants::scale * constants::defaultArriveRadius * constants::scale) break;
            this->pathStatus.index++;
        }

        if(distanceSquared == 0.f)
        {
            this->pathStatus.index = 0;
            this->pathStatus.gridCoordinateVector.clear();
            this->deltaWorldCoordinate = constants::zeroVector;
            return;
        }
        else
        {
            this->deltaWorldCoordinate = (targetRelativeWorldCoordinate / std::sqrt(distanceSquared)) * getMovementSpeed() * static_cast<float>(constants::scale);
            return;
        }
    }
    else
    {
        targetRelativeWorldCoordinate = coordinateConverter.convertToWorldCoordinate(pathStatus.gridCoordinateVector.back()) - getWorldCoordinate();
        distanceSquared = targetRelativeWorldCoordinate.x * targetRelativeWorldCoordinate.x + targetRelativeWorldCoordinate.y * targetRelativeWorldCoordinate.y;
        tenativeDeltaWorldCoordinate = (targetRelativeWorldCoordinate / std::sqrt(distanceSquared)) * getMovementSpeed() * static_cast<float>(constants::scale);

        if(tenativeDeltaWorldCoordinate.x * tenativeDeltaWorldCoordinate.x + tenativeDeltaWorldCoordinate.y * tenativeDeltaWorldCoordinate.y < distanceSquared)
        {
            this->deltaWorldCoordinate = tenativeDeltaWorldCoordinate;
            return;
        }
        else
        {
            this->pathStatus.index = 0;
            this->pathStatus.gridCoordinateVector.clear();
            this->deltaWorldCoordinate = targetRelativeWorldCoordinate;
            return;
        }
    }
}

float DynamicEntity::getMovementSpeed()
{
    return movementSpeed;
}