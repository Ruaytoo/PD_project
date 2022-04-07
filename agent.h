#pragma once
#include "strategy.h"
#include <string>


class Agent
{
public:
	void PrintStrategy();

private:
	int Agent_ID;
	float score;
	std::vector<int> history;
	Strategy strategy;
};
