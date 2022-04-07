#pragma once
#include <vector>
#include <random>
#include "agent.h"
#include "strategy.h"


class game
{
private:
	std::vector<agent> agents;
	payoff payoff;

public:
	game(int N, strategy strategy){};
	void round();
};