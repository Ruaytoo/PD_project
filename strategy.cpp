#include "strategy.h"
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <random>
#include <chrono>  


Strategy::Strategy ()
{
    std::srand(std::time(0));
    for (int j = 0; j < 70; j++)
        {
            int random_state = rand() % 2;
            if (random_state % 2 == 0)
            {
                chromosome.push_back(0);
            }
            else
            {
                chromosome.push_back(1);
            }
        }
}



std::map<std::string, float> Strategy::GetStrategy() 
{
    return params;
}



void Strategy::SetStrategy(std::string& n, std::map<std::string, float>& p)
{
    name = n;
    params = p;
};



bool DefectStrategy::MakeChoice(const std::vector<Agent>& agents, int agent_index) 
{
    return 0;
}


bool CoopStrategy::MakeChoice(const std::vector<Agent>& agents, int agent_index) 
{
    return 1;
}



bool TitForTat::MakeChoice(const std::vector<Agent>& agents, int agent_index) 
{
    if (agents[agent_index].history.empty()) {
        int init = rand() % 2;
        if (init % 2 == 0) {
            return start_strategy1;
        }
        else {
            return start_strategy2;
        }
    }
    else {
        if (agent_index % 2 == 0) {
            return agents[agent_index + 1].history.back();
        }
        else {
            return agents[agent_index - 1].history.back();
        }
    }
}



void TitForTat::SetStart(int index, bool choice) {
    if (index == 1) {
        start_strategy1 = choice;
    }
    else {
        start_strategy2 = choice;
    }
}


bool GeneticStrategy::MakeChoice(const std::vector<Agent>& agents, int agent_index)
{
    int asBinary = 0;

    for (int i = 64; i < 70; ++i)
    {
        asBinary *= 2;
        asBinary += agents.at(agent_index).strategy->chromosome.at(i);
    }
    
    return agents.at(agent_index).strategy->chromosome.at(asBinary);
}