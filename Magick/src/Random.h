#pragma once

#include <random>

class Random
{
public:
    Random() : rng(std::random_device{}()) {}

    static int getInt(int min, int max)
    {
        return getInstance().getIntImpl(min, max);
    }

    static float getFloat(float min, float max)
    {
        return getInstance().getFloatImpl(min, max);
    }

    static double getDouble(double min, double max)
    {
        return getInstance().getDoubleImpl(min, max);
    }

    static bool getBool()
    {
        return getInstance().getBoolImpl();
    }
private:
    static Random& getInstance()
    {
        static Random instance;
        return instance;
    }

    int getIntImpl(int min, int max)
    {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }

    float getFloatImpl(float min, float max)
    {
        std::uniform_real_distribution<float> dist(min, max);
        return dist(rng);
    }

    double getDoubleImpl(double min, double max)
    {
        std::uniform_real_distribution<double> dist(min, max);
        return dist(rng);
    }

    bool getBoolImpl()
    {
        std::bernoulli_distribution dist(0.5);
        return dist(rng);
    }   

    std::mt19937 rng;
};