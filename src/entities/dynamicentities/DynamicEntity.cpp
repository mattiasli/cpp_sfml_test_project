#include "../../../include/entities/dynamicentities/DynamicEntity.hpp"
#include "../../../include/core/Handler.hpp"

DynamicEntity::DynamicEntity(Handler& handler, sf::Vector2f worldCoordinate, const BoundingBox& boundingBox, constants::EntityType entityType)
: Entity(handler, worldCoordinate, boundingBox, entityType),
map(handler.getMap()),
coordinateConverter(handler.getCoordinateConverter()),
deltaXBoundingBox(boundingBox),
deltaYBoundingBox(boundingBox)
{
}

void DynamicEntity::updateLogic()
{
    applyIntent();
    updateInstanceAnimatorFromEntityState();
    updateDeltaWorldCoordinateFromPathStatus();
    updateDirectionsFromDeltaWorldCoordinate();
    if(deltaWorldCoordinate != constants::zeroVectorF)
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

void DynamicEntity::applyIntent()
{
    if(dynamicEntityController == nullptr)
    {
        return;
    }

    dynamicEntityController->updateLogic();

    if(dynamicEntityController->getIntent().hasEntityState)
    {
        entityState = dynamicEntityController->getIntent().entityState;
    }

    if(dynamicEntityController->getIntent().hasMovementDirection)
    {
        pathStatus.clear();
        deltaWorldCoordinate = dynamicEntityController->getIntent().movementDirection * dynamicEntityController->getIntent().movementSpeed * static_cast<float>(constants::scale);
    }
    else if(dynamicEntityController->getIntent().hasGoalGridCoordinate)
    {
        movementSpeed = dynamicEntityController->getIntent().movementSpeed;
        setPathStatus(handler.getPathFinder().computeAStarPath(handler.getCoordinateConverter().convertToGridCoordinate(boundingBox.getCenterWorldCoordinate()),
                                                               dynamicEntityController->getIntent().goalGridCoordinate));
    }
    else
    {
        deltaWorldCoordinate = constants::zeroVectorF;
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

double DynamicEntity::getMinWaitTimeMicroseconds() const
{
    return minWaitTimeMicroseconds;
}

double DynamicEntity::getMaxWaitTimeMicroseconds() const
{
    return maxWaitTimeMicroseconds;
}

float DynamicEntity::getDefaultMovementSpeed() const
{
    return defaultMovementSpeed;
}

float DynamicEntity::getRunEntityStateThreshold() const
{
    return runEntityStateThreshold;
}

float DynamicEntity::getDefaultMovementSpeedExpectedValue() const
{
    return defaultMovementSpeedExpectedValue;
}

float DynamicEntity::getDefaultMovementSpeedStandardDeviation() const
{
    return defaultMovementSpeedStandardDeviation;
}

float DynamicEntity::getMovementSpeed() const
{
    return movementSpeed;
}

void DynamicEntity::updateDeltaWorldCoordinateFromPathStatus()
{
    if(pathStatus.empty())
    {
        return;
    }

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
            this->pathStatus.clear();
            this->deltaWorldCoordinate = constants::zeroVectorF;
            this->movementSpeed = 0.f;
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

        if(distanceSquared == 0.f)
        {
            this->pathStatus.clear();
            this->deltaWorldCoordinate = constants::zeroVectorF;
            this->movementSpeed = 0.f;
            return;
        }
        else
        {
            if(tenativeDeltaWorldCoordinate.x * tenativeDeltaWorldCoordinate.x + tenativeDeltaWorldCoordinate.y * tenativeDeltaWorldCoordinate.y < distanceSquared)
            {
                this->deltaWorldCoordinate = tenativeDeltaWorldCoordinate;
                return;
            }
            else
            {
                this->deltaWorldCoordinate = targetRelativeWorldCoordinate;
                return;
            }
        }
    }
}

void DynamicEntity::updateInstanceAnimatorFromEntityState()
{
    if(entityState == constants::EntityState::Attack)
    {
        if(instanceAnimator.expired())
        {
            instanceAnimator = handler.getSpriteManager().getInstanceAnimator(constants::EntityType::CapedWarrior, entityState, direction);
        }
    }
}

void DynamicEntity::updateDirectionsFromDeltaWorldCoordinate()
{
    if(deltaWorldCoordinate == constants::zeroVectorF)
    {
        return;
    }

    if(std::abs(deltaWorldCoordinate.y) > std::abs(deltaWorldCoordinate.x))
    {
        if(deltaWorldCoordinate.y >= 0)
        {
            direction = constants::Direction::Down;
            lastVerticalDirection = constants::Direction::Down;
        }
        else
        {
            direction = constants::Direction::Up;
            lastVerticalDirection = constants::Direction::Up;
        }
    }
    else
    {
        if(deltaWorldCoordinate.x >= 0)
        {
            direction = constants::Direction::Right;
            lastHorizontalDirection = constants::Direction::Right;
        }
        else
        {
            direction = constants::Direction::Left;
            lastHorizontalDirection = constants::Direction::Left;
        }
    }
}

constants::EntityState DynamicEntity::getEntityState() const
{
    return entityState;
}

PathStatus& DynamicEntity::getPathStatus()
{
    return pathStatus;
}

std::weak_ptr<Animator> DynamicEntity::getInstanceAnimator() const
{
    return instanceAnimator;
}