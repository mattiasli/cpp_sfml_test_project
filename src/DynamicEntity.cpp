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