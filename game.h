#pragma once
#include <vector>
#include <random>
#include "agent.h"
#include "payoff.h"
#include "strategy.h"


class Game
{
private:
	Payoff payoff;

public:
	std::vector<Agent> agents;
	Game(int N, Strategy strategy,
		float cc, float dc, float cd, float dd, float p);
	void round();
};