#pragma once


#include <random>

class Random
{
public:
    Random() : rng(std::random_device{}()) {}

    int getInt(int min, int max) 
    {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }

    float getFloat(float min, float max) 
    {
        std::uniform_real_distribution<float> dist(min, max);
        return dist(rng);
    }

    double getDouble(double min, double max) 
    {
        std::uniform_real_distribution<double> dist(min, max);
        return dist(rng);
    }

    bool getBool() 
    {
        std::bernoulli_distribution dist(0.5);
        return dist(rng);
    }
private:
    std::mt19937 rng;
};