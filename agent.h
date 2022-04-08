#pragma once
#include "strategy.h"
#include <string>
#include <vector>


class Agent
{
public:
	void PrintStrategy();
	float score;
	std::vector<int> history;
	int choice;
	Agent(Strategy strategy);

private:
	int Agent_ID;
	Strategy strategy;
	
};

