#include "../../include/control/PlayerController.hpp"
#include "../../include/core/Handler.hpp"

PlayerController::PlayerController(Handler& handler, DynamicEntity& dynamicEntity)
: Controller(handler, dynamicEntity)
{
}

void PlayerController::gatherDecisionContext()
{
}

void PlayerController::synthesizeIntent()
{
}