#pragma once
#include <vector>
#include <random>
#include "payoff.h"
#include "strategy.h"


class Game
{
private:
	Payoff payoff;

public:
	std::vector<Agent> agents;
	Game(std::vector<Agent> agents,
		float cc, float dc, float cd, float dd, float p);
	void round();
};