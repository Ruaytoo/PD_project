#pragma once
#include "strategy.h"
#include <string>
#include <vector>
#include "agent.h"
#include <map>
#include <iostream>


class Agent
{
public:
	void PrintStrategy();
	float score;
	std::vector<int> history;
	int choice;
	Agent(Strategy *strategy);
	Strategy *strategy;
    int GetAgent_ID();

private:
	int Agent_ID;	
};

