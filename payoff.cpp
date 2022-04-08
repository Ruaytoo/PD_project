#include "payoff.h"

payoff::payoff(float dd, float dc,
	float cd, float cc, float p)
{
	dd = dd;
	cd = cd;
	dc = dc;
	cc = cc;
	p = p;
};

void payoff::compute_score(Agent& agent1, Agent& agent2)
{
	if (agent1.choice == 0 && agent2.choice == 0)
	{
		agent1.score += dd;
		agent2.score += dd;
		agent1.history[agent1.history.size()] = 0;
		agent2.history[agent2.history.size()] = 0;
	}
	else if (agent1.choice == 0 && agent2.choice == 1)
	{
		agent1.score += dc;
		agent2.score += cd;
		agent1.history[agent1.history.size()] = 1;
		agent2.history[agent2.history.size()] = 0;
	}
	else if (agent1.choice == 1 && agent2.choice == 0)
	{
		agent1.score += cd;
		agent2.score += dc;
		agent1.history[agent1.history.size()] = 0;
		agent2.history[agent2.history.size()] = 1;
	}
	else
	{
		agent1.score += cc;
		agent2.score += cc;
		agent1.history[agent1.history.size()] = 1;
		agent2.history[agent2.history.size()] = 1;
	}
};