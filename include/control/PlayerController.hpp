#pragma once
#include "DynamicEntityController.hpp"

class Handler;
class DynamicEntity;

class PlayerController : public DynamicEntityController {
public:
    PlayerController(Handler& handler, DynamicEntity& dynamicEntity);

private:
    void gatherDecisionContext() override;
    void synthesizeIntent() override;
    void synthesizeIdleWalkRunIntent();
    void synthesizeAttackIntent();
};