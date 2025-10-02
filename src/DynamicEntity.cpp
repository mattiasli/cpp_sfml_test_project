#include "../include/DynamicEntity.hpp"
#include "../include/Handler.hpp"

DynamicEntity::DynamicEntity(Handler& handler, sf::Vector2f worldCoordinate, BoundingBox boundingBox)
: Entity(handler, worldCoordinate, boundingBox),
map(handler.getMap()),
coordinateConverter(handler.getCoordinateConverter())
{
}

void DynamicEntity::updateLogic()
{
    adjustDeltaWorldCoordinateForTileCollisions();
    updatePosition();

}

void DynamicEntity::updatePosition()
{
    worldCoordinate += deltaWorldCoordinate;
}

void DynamicEntity::adjustDeltaWorldCoordinateForTileCollisions()
{
    boundingBox.setPosition(worldCoordinate);

    boundingBox.setXWorldCoordinate(worldCoordinate.x + deltaWorldCoordinate.x);

    int leftGridColumn = coordinateConverter.getXGridCoordinate(boundingBox.getLeftEdgeXWorldCoordinate());
    int rightGridColumn = coordinateConverter.getXGridCoordinate(boundingBox.getRightEdgeXWorldCoordinate());
    int topGridRow = coordinateConverter.getYGridCoordinate(boundingBox.getTopEdgeYWorldCoordinate());
    int bottomGridRow = coordinateConverter.getYGridCoordinate(boundingBox.getBottomEdgeYWorldCoordinate());

    for(int y = topGridRow; y <= bottomGridRow ; y++)
    {
        for(int x = leftGridColumn; x <= rightGridColumn ; x++)
        {
            if(map.isGridCoordinateSolid({x, y}))
            {
                if(deltaWorldCoordinate.x > 0)
                {
                deltaWorldCoordinate.x += coordinateConverter.getXWorldCoordinate(x) - boundingBox.getRightEdgeXWorldCoordinate() - 1;
                }
                else if(deltaWorldCoordinate.x < 0)
                {
                deltaWorldCoordinate.x += coordinateConverter.getXWorldCoordinate(x) + constants::tileWidth * constants::scale - boundingBox.getLeftEdgeXWorldCoordinate();
                }
                boundingBox.setPosition(worldCoordinate + sf::Vector2f{deltaWorldCoordinate.x, 0});
            }
        }
    }

    boundingBox.setYWorldCoordinate(worldCoordinate.y + deltaWorldCoordinate.y);

    leftGridColumn = coordinateConverter.getXGridCoordinate(boundingBox.getLeftEdgeXWorldCoordinate());
    rightGridColumn = coordinateConverter.getXGridCoordinate(boundingBox.getRightEdgeXWorldCoordinate());
    topGridRow = coordinateConverter.getYGridCoordinate(boundingBox.getTopEdgeYWorldCoordinate());
    bottomGridRow = coordinateConverter.getYGridCoordinate(boundingBox.getBottomEdgeYWorldCoordinate());

    for(int y = topGridRow; y <= bottomGridRow ; y++)
    {
        for(int x = leftGridColumn; x <= rightGridColumn ; x++)
        {
            if(map.isGridCoordinateSolid({x, y}))
            {
                if(deltaWorldCoordinate.y > 0)
                {
                deltaWorldCoordinate.y += coordinateConverter.getXWorldCoordinate(y) - boundingBox.getBottomEdgeYWorldCoordinate() - 1;
                }
                else if(deltaWorldCoordinate.y < 0)
                {
                deltaWorldCoordinate.y += coordinateConverter.getXWorldCoordinate(y) + constants::tileHeight * constants::scale - boundingBox.getTopEdgeYWorldCoordinate();
                }
                boundingBox.setPosition(worldCoordinate + sf::Vector2f{0, deltaWorldCoordinate.y});
            }
        }
    }
}