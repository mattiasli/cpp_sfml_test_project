#include "../../../include/entities/dynamicentities/NPCEntity.hpp"
#include "../../../include/core/Handler.hpp"

NPCEntity::NPCEntity(Handler& handler, sf::Vector2f worldCoordinate, const BoundingBox& boundingBox, constants::EntityType entityType)
: DynamicEntity(handler, worldCoordinate, boundingBox, entityType)
{
    dynamicEntityController = std::make_unique<NPCEntityController>(handler, *this);
}

void NPCEntity::updateLogic()
{
    applyIntent();
    DynamicEntity::updateLogic();
}