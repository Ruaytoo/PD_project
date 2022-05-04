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

void Payoff::UpdateScore(Agent* agent1, Agent* agent2,
                 float score1, float score2,
                 int choice1, int choice2) {
    agent1->score += score1;
    agent2->score += score2;
    agent1->history.push_back(choice1);
    agent2->history.push_back(choice2);
    agent1->history.push_back(choice2);
    agent2->history.push_back(choice1);
}

void Payoff::compute_score(Agent *agent1, Agent *agent2)
{
	if (agent1->choice == 0 && agent2->choice == 0)
	{
        UpdateScore(agent1, agent2, dd, dd, 0, 0);
	}
	else if (agent1->choice == 0 && agent2->choice == 1)
	{
		if (p * C < distr(gen))
		{
            UpdateScore(agent1, agent2, dc, cd, 1, 0);
		}
		else
		{
            UpdateScore(agent1, agent2, dd, cd, 0, 0);
		}
	}
	else if (agent1->choice == 1 && agent2->choice == 0)
	{
		if (p * C < distr(gen))
		{
            UpdateScore(agent1, agent2, cd, dc, 0, 1);
		}
		else
		{
            UpdateScore(agent1, agent2, cd, dd, 0, 0);
		}
	}
	else
	{
		if (p * C < distr(gen))
		{
            UpdateScore(agent1, agent2, cc, cc, 1, 1);
		}
		else
		{
            UpdateScore(agent1, agent2, cd, cd, 0, 0);
		}
	}
};