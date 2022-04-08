#pragma once
#include "agent.h"

class payoff
{
private:
	float dd, dc, cd, cc;
	float p;

public:
	payoff(float dd, float dc,
		float cd, float cc, float p);

	void compute_score(Agent& agent1, Agent& agent2);
};