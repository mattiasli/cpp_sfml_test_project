#include "../../include/core/ProbabilityManager.hpp"
#include "../../include/core/Handler.hpp"

ProbabilityManager::ProbabilityManager(Handler& handler)
: handler(handler),
randomDevice(),
mersenneTwisterEngine(randomDevice())
{
}

int ProbabilityManager::generateUniformInteger(int min, int max)
{
    std::uniform_int_distribution<> distribution(min, max);
    return distribution(mersenneTwisterEngine);
}

float ProbabilityManager::generateUniformFloat(float min, float max)
{
    std::uniform_real_distribution<> distribution(min, max);
    return distribution(mersenneTwisterEngine);
}

float ProbabilityManager::generateLogNormalFloat(float expectedValue, float standardDeviation) // TODO naming.
{
    std::lognormal_distribution<float> distribution(std::log(expectedValue) - 0.5 * standardDeviation * standardDeviation,
                                                    standardDeviation);
    return distribution(mersenneTwisterEngine);
}