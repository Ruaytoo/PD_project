#pragma once
#include "strategy.h"

class agent
{
public:
	float score;
	std::vector<int> history;
	strategy strategy;
};