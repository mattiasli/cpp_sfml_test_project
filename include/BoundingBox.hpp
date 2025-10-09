#pragma once
#include <SFML/Graphics.hpp>

class Handler;

class BoundingBox {
public:
    BoundingBox(Handler& handler, sf::Vector2f entityWorldCoordinate, sf::Vector2f size, sf::Vector2f rectangleOffsetWorldCoordinate);

    void setEntityWorldCoordinate(sf::Vector2f entityWorldCoordinate);
    void setEntityXWorldCoordinate(float entityXWorldCoordinate);
    void setEntityYWorldCoordinate(float entityYWorldCoordinate);

    sf::Vector2f getEntityWorldCoordinate() const;
    float getEntityXWorldCoordinate() const;
    float getEntityYWorldCoordinate() const;

    void setRectangleWorldCoordinate(sf::Vector2f rectangleWorldCoordinate);
    void setRectangleXWorldCoordinate(float rectanglXWorldCoordinate);
    void setRectangleYWorldCoordinate(float rectanglYWorldCoordinate);

    sf::Vector2f getRectangleWorldCoordinate() const;
    float getRectangleXWorldCoordinate() const;
    float getRectangleYWorldCoordinate() const;

    float getWidth() const;
    float getHeight() const;

    float getLeftEdgeXWorldCoordinate() const;
    float getRightEdgeXWorldCoordinate() const;
    float getTopEdgeYWorldCoordinate() const;
    float getBottomEdgeYWorldCoordinate() const;

private:
    Handler& handler;

    sf::Vector2f entityWorldCoordinate;
    sf::FloatRect rectangle;
    sf::Vector2f rectangleOffsetWorldCoordinate;

    void updateRectangleFromEntityWorldCoordinate();
    void updateEntityWorldCoordinateFromRectangle();
};