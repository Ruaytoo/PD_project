#pragma once
#include "strategy.h"

class agent
{
public:
	float score;
	int choice;
	std::vector<int> history;
	strategy strategy;
	agent(strategy strategy);
};