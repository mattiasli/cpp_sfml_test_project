#pragma once
#include "DynamicEntity.hpp"
#include "../../../include/control/NPCEntityController.hpp"

class Handler;

class NPCEntity : public DynamicEntity {
public:
    NPCEntity(Handler& handler, sf::Vector2f worldCoordinate, const BoundingBox& boundingBox, constants::EntityType entityType);

    virtual void updateLogic() override;

private:
};