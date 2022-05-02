#pragma once
#include <vector>
#include <random>
#include <map>

class Population {
public:
    Population(int size);
    int Get_population_size();
    std::vector<std::vector<int>> population;
    void Initialize_population();
    void Competition();

private:
    int population_size;
};