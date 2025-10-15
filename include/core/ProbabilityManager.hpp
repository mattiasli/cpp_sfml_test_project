#pragma once
#include <random>

class Handler;

class ProbabilityManager {
public:
    ProbabilityManager(Handler& handler);

    int generateUniformInteger(int min, int max);
    float generateUniformFloat(float min, float max);
    float generateLogNormalFloat(float expectedValue, float standardDeviation);

private:
    Handler& handler;
    std::random_device randomDevice;
    std::mt19937 mersenneTwisterEngine;
};