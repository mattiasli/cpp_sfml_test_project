#pragma once
#include "DecisionContext.hpp"
#include "Intent.hpp"

class Handler;
class DynamicEntity;

class Controller {
public:
    Controller(Handler& handler, DynamicEntity& dynamicEntity);
    void updateLogic();
    const Intent& getIntent() const;

protected:
    Handler& handler;
    DynamicEntity& dynamicEntity;
    DecisionContext decisionContext;
    Intent intent;

private:
    virtual void gatherDecisionContext() = 0;
    virtual void synthesizeIntent() = 0;
};