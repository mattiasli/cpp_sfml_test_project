#include "../../include/control/DynamicEntityController.hpp"
#include "../../include/core/Handler.hpp"

DynamicEntityController::DynamicEntityController(Handler& handler, DynamicEntity& dynamicEntity)
: handler(handler),
dynamicEntity(dynamicEntity)
{
}

void DynamicEntityController::updateLogic()
{
    gatherDecisionContext();
    synthesizeIntent();
}

const Intent& DynamicEntityController::getIntent() const
{
    return intent;
}