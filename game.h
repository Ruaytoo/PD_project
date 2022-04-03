#pragma once
#include <vector>
#include <random>
#include "agent.h"
#include "strategy.h"
#include "optimizer.h"

template <typename T>

class game
{
private:
	std::vector<agent> agents;
	std::vector<T> payoff;


public:
	game(int N, strategy strategy){};
	void round();
};