#include "../../include/control/Controller.hpp"
#include "../../include/core/Handler.hpp"

Controller::Controller(Handler& handler, DynamicEntity& dynamicEntity)
: handler(handler),
dynamicEntity(dynamicEntity)
{
}

void Controller::updateLogic()
{
    gatherDecisionContext();
    synthesizeIntent();
}

const Intent& Controller::getIntent() const
{
    return intent;
}