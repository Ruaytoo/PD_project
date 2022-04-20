#pragma once
#include "strategy.h"
#include <string>
#include <vector>
#include <iostream>

std::map<std::string, float> Strategy::GetStrategy() {
	return params;
}

void Strategy::SetStrategy(std::string& n, std::map<std::string, float>& p)
{
		name = n;
		params = p;
};

bool DefectStrategy::MakeChoice(std::vector<Agent> agents, int agent_index) {
	return 0;
}

bool TitForTat::MakeChoice(std::vector<Agent> agents, int agent_index) {
    if (agents[agent_index].history.size() == 0) {
        if (agents[agent_index].GetAgent_ID() == 1) {
            return start_strategy1;
        }
        else {
            return start_strategy2;
        }
    }
    else {
        if (agent_index == 1) {
            return agents[0].history.back();
        }
        else {
            return agents[1].history.back();
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