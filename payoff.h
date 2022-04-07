#pragma once
#include "agent.h"

class payoff
{
private:
	float dd, dc, cd, dd, p;
	float p;

public:
	payoff(float dd, float dc,
		float cd, float dd, p);

	void compute_score(agent agent1, agent agent2);
};