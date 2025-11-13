#pragma once
#include "DynamicEntityController.hpp"

class Handler;
class DynamicEntity;

class NPCEntityController : public DynamicEntityController {
public:
    NPCEntityController(Handler& handler, DynamicEntity& dynamicEntity);

private:
    void gatherDecisionContext() override;
    void synthesizeIntent() override;
    void synthesizeIdleIntent();
    void synthesizeWalkRunIntent();
};