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
    for (int j = 0; j < 64; j++)
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



bool DefectStrategy::MakeChoice(std::vector<Agent> agents, int agent_index) 
{
    return 0;
}


bool CoopStrategy::MakeChoice(std::vector<Agent> agents, int agent_index) 
{
    return 1;
}



bool TitForTat::MakeChoice(std::vector<Agent> agents, int agent_index) 
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


bool GeneticStrategy::MakeChoice(std::vector<Agent> agents, int agent_index)
{
    int asBinary = 0;

    if (agents.at(agent_index).history.size() <= 4)
    {
        for (auto i : agents.at(agent_index).history)
        {
            asBinary *= 2;
            asBinary += i;
        }
        
    }
    else
    {
        for (int i = 0; i < 6; ++i)
        {
            asBinary *= 2;
            asBinary += agents.at(agent_index).history.at(i);
        }
    }
    
    return agents.at(agent_index).strategy->chromosome.at(asBinary);
}