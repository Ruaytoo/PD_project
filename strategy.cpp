#include "strategy.h"
#include <string>
#include <vector>
#include <string>

Strategy::Strategy ()
{
    for (int j = 0; j < 15; j++)
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

    if (agents.at(agent_index).history.size() == 0)
        return agents.at(agent_index).strategy->chromosome.at(asBinary);

    else if (agents.at(agent_index).history.size() == 1)
    {
        for (auto i : agents.at(agent_index).strategy->chromosome)
        {
            asBinary *= 2;
            asBinary += i;
        }
        return agents.at(agent_index).strategy->chromosome.at(1 + asBinary);
    }
    else if (agents.at(agent_index).history.size() == 2)
    {
        for (auto i : agents.at(agent_index).strategy->chromosome)
        {
            asBinary *= 2;
            asBinary += i;
        }
        return agents.at(agent_index).strategy->chromosome.at(3 + asBinary);
    }
    else
    {
        for (auto i : agents.at(agent_index).strategy->chromosome)
        {
            asBinary *= 2;
            asBinary += i;
        }
        return agents.at(agent_index).strategy->chromosome.at(7 + asBinary);
    }
}