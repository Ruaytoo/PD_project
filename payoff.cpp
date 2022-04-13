#include "payoff.h"
#include <iostream>

Payoff::Payoff(float dd, float dc,
	float cd, float cc, float p)
:distr(0, C)
{
	this->dd = dd;
	this->dc = dc;
	this->cd = cd;
	this->cc = cc;
	this->p = p;
	std::random_device rd;
    std::mt19937 gen(rd());
};

void Payoff::compute_score(Agent& agent1, Agent& agent2)
{
	if (agent1.choice == 0 && agent2.choice == 0)
	{
		agent1.score += dd;
		agent2.score += dd;
		agent1.history.push_back(0);
		agent2.history.push_back(0);
	}
	else if (agent1.choice == 0 && agent2.choice == 1)
	{
		if (p * C < distr(gen))
		{
			agent1.score += dc;
			agent2.score += cd;
			agent1.history.push_back(1);
			agent2.history.push_back(0);
		}
		else
		{
			agent1.score += dd;
			agent2.score += cd;
			agent1.history.push_back(0);
			agent2.history.push_back(0);
		}
	}
	else if (agent1.choice == 1 && agent2.choice == 0)
	{
		if (p * C < distr(gen))
		{
			agent1.score += cd;
			agent2.score += dc;
			agent1.history.push_back(0);
			agent2.history.push_back(1);
		}
		else
		{
			agent1.score += cd;
			agent2.score += dd;
			agent1.history.push_back(0);
			agent2.history.push_back(0);			
		}
	}
	else
	{
		if (p * C < distr(gen))
		{
			agent1.score += cc;
			agent2.score += cc;
			agent1.history.push_back(1);
			agent2.history.push_back(1);
		}
		else
		{
			agent1.score += cd;
			agent2.score += cd;
			agent1.history.push_back(0);
			agent2.history.push_back(0);
		}
	}
};