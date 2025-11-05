#pragma once
#include "Controller.hpp"

class Handler;
class DynamicEntity;

class PlayerController : public Controller {
public:
    PlayerController(Handler& handler, DynamicEntity& dynamicEntity);

private:
    void gatherDecisionContext() override;
    void synthesizeIntent() override;
};