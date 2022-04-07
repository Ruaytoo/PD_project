class agent
{
public:
	float score;
	std::vector<int> history;
	strategy strategy;
	agent(strategy strategy)
	{
		score = 0;
		strategy = strategy;
	}
};