#pragma once
#include <vector>
#include <random>
#include "agent.h"
#include "payoff.h"
#include "strategy.h"


class game
{
private:
	std::vector<Agent> agents;
	payoff payoff;

public:
	game(int N, Strategy strategy,
		float cc, float dc, float cd, float dd, float p);
	void round();
};