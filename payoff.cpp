class payoff
{
private:
	float left_high, right_high, left_low, right_low;
	float p;

public:
	payoff(float dd, float dc,
		float cd, float dd, p)
	{
		left_high = left_high;
		right_high = right_high;
		left_low = left_low;
		right_low = right_low;
		p = p
	};

	void compute_score(agent& agent1, agent& agent2)
	{
		if (agent1.choice == 0 && agent2.choice == 0)
		{
			agent1.score += dd;
			agent2.score += dd;
			agent1.history[agent1.history.size] = 0;
			agent2.history[agent2.history.size] = 0;
		}
		else if (agent1.choice == 0 && agent2.choice == 1)
		{
			agent1.score += dc;
			agent2.score += cd;
			agent1.history[agent1.history.size] = 1;
			agent2.history[agent2.history.size] = 0;
		}
		else if (agent1.choice == 1 && agent2.choice == 0)
		{
			agent1.score += cd;
			agent2.score += dc;
			agent1.history[agent1.history.size] = 0;
			agent2.history[agent2.history.size] = 1;
		}
		else
		{
			agent1.score += cc;
			agent2.score += cc;
			agent1.history[agent1.history.size] = 1;
			agent2.history[agent2.history.size] = 1;
		}
	};
};