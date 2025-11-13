#pragma once
#include "DecisionContext.hpp"
#include "Intent.hpp"

class Handler;
class DynamicEntity;

struct WorkingMemory
{
    double idleTimeRemainingMicroseconds;
};

class DynamicEntityController {
public:
    DynamicEntityController(Handler& handler, DynamicEntity& dynamicEntity);
    void updateLogic();
    const Intent& getIntent() const;

protected:
    Handler& handler;
    DynamicEntity& dynamicEntity;
    DecisionContext decisionContext;
    WorkingMemory workingMemory;
    Intent intent;

private:
    virtual void gatherDecisionContext() = 0;
    virtual void synthesizeIntent() = 0;
};