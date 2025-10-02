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
    updateBoundingBoxesWorldCoordinates();
    adjustBoundingBoxForTileCollisions();
    updateWorldCoordinate();
}

void DynamicEntity::updateWorldCoordinate()
{
    worldCoordinate.x = deltaXBoundingBox.getXWorldCoordinate();
    worldCoordinate.y = deltaYBoundingBox.getYWorldCoordinate();
}

void DynamicEntity::updateBoundingBoxesWorldCoordinates()
{
    boundingBox.setWorldCoordinate(worldCoordinate);
    deltaXBoundingBox.setWorldCoordinate(worldCoordinate + sf::Vector2f({deltaWorldCoordinate.x, 0}));
    deltaYBoundingBox.setWorldCoordinate(worldCoordinate + sf::Vector2f({0, deltaWorldCoordinate.y}));
}

void DynamicEntity::adjustBoundingBoxForTileCollisions()
{
    int leftGridColumn = coordinateConverter.getXGridCoordinate(deltaXBoundingBox.getLeftEdgeXWorldCoordinate());
    int rightGridColumn = coordinateConverter.getXGridCoordinate(deltaXBoundingBox.getRightEdgeXWorldCoordinate());
    int topGridRow = coordinateConverter.getYGridCoordinate(deltaXBoundingBox.getTopEdgeYWorldCoordinate());
    int bottomGridRow = coordinateConverter.getYGridCoordinate(deltaXBoundingBox.getBottomEdgeYWorldCoordinate());

    for(int y = topGridRow; y <= bottomGridRow ; y++)
    {
        for(int x = leftGridColumn; x <= rightGridColumn ; x++)
        {
            if(map.isGridCoordinateSolid({x, y}))
            {
                if(deltaWorldCoordinate.x > 0)
                {
                deltaXBoundingBox.setXWorldCoordinate(coordinateConverter.getXWorldCoordinate(x) - deltaXBoundingBox.getWidth());
                }
                else if(deltaWorldCoordinate.x < 0)
                {
                deltaXBoundingBox.setXWorldCoordinate(coordinateConverter.getXWorldCoordinate(x) + constants::tileWidth * constants::scale);
                }
            }
        }
    }

    leftGridColumn = coordinateConverter.getXGridCoordinate(deltaYBoundingBox.getLeftEdgeXWorldCoordinate());
    rightGridColumn = coordinateConverter.getXGridCoordinate(deltaYBoundingBox.getRightEdgeXWorldCoordinate());
    topGridRow = coordinateConverter.getYGridCoordinate(deltaYBoundingBox.getTopEdgeYWorldCoordinate());
    bottomGridRow = coordinateConverter.getYGridCoordinate(deltaYBoundingBox.getBottomEdgeYWorldCoordinate());

    for(int y = topGridRow; y <= bottomGridRow ; y++)
    {
        for(int x = leftGridColumn; x <= rightGridColumn ; x++)
        {
            if(map.isGridCoordinateSolid({x, y}))
            {
                if(deltaWorldCoordinate.y > 0)
                {
                deltaYBoundingBox.setYWorldCoordinate(coordinateConverter.getYWorldCoordinate(y) - deltaYBoundingBox.getHeight());
                }
                else if(deltaWorldCoordinate.y < 0)
                {
                deltaYBoundingBox.setYWorldCoordinate(coordinateConverter.getYWorldCoordinate(y) + constants::tileHeight * constants::scale);
                }
            }
        }
    }
}