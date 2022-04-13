#pragma once
#include "agent.h"
#include <random>
#define C 10000

class Payoff
{
private:
	std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> distr;

public:
	float p;
	float dd, dc, cd, cc;
	Payoff(float dd, float dc,
		float cd, float cc, float p);

	void compute_score(Agent& agent1, Agent& agent2);
};